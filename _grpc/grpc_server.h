
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <atomic>

#include <base/base.h>
#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>
#include "fbs.grpc.pb.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using fbs::BizData;
using fbs::BizPipe;





class BizPipeService final : public BizPipe::Service
{
public:
    Status onBusiness(ServerContext* context, ServerReaderWriter<BizData, BizData>* stream) override
    {
        std::vector<BizData> recvData;
        BizData data;
        while (stream->Read(&data))
        {
            /*
            for (const BizData& n : recvData)
            {
                if (n.byteData() == data.byteData())
                {
                    stream->Write(n);
                }
            }
            */
            recvData.push_back(data);
        }
        return Status::OK;
    }
private:
    std::atomic_uint64_t m_un64Session = 0;
    std::map<uint64_t, std::vector<BizData>> m_mapS[];
};

static void runServer()
{
    std::string strAddr("0.0.0.0:50051");
    BizPipeService service; 
    ServerBuilder builder;
    builder.AddListeningPort(strAddr, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    server->Wait();
}


