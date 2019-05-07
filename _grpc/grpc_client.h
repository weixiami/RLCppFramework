#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <thread>
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>
#include "fbs.grpc.pb.h"


using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using fbs::BizData;
using fbs::BizPipe;



class BizPipeClient
{
public:
    BizPipeClient(std::shared_ptr<Channel> channel) : stub_(BizPipe::NewStub(channel))
    {
    }

    void onBusiness()
    {
        ClientContext context;
        std::shared_ptr<ClientReaderWriter<BizData, BizData> > stream(stub_->onBusiness(&context));

        std::thread writer([stream]()
        {
            std::vector<BizData> notes;
            for (const BizData& note : notes)
            {
                stream->Write(note);
            }
            stream->WritesDone();
        });

        BizData server_note;
        while (stream->Read(&server_note))
        {
        }
        writer.join();
        Status status = stream->Finish();
        if (!status.ok()) std::cout << "RouteChat rpc failed." << std::endl;
    }

private:
    const float kCoordFactor_ = 10000000.0;
    std::unique_ptr<BizPipe::Stub> stub_;
};

/*
int main(int argc, char** argv)
{
    BizPipeClient guide(grpc::CreateChannel("localhost:50051"));
    std::cout << "-------------- RouteChat --------------" << std::endl;
    guide.onBusiness();

    return 0;
}
*/