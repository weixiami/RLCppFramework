# RLCppFramework
C++基本开发库，负责封装线程池、HTTP、JSON、XML、日志、共享内存、数据库、Websocket等开发工具


## 环境
| 环境 | 版本 | 状态 |
|:--:|:--|:--:|
| macOS | 10.14.3 later | [![](https://api.travis-ci.org/spacewander/termdump.svg)]() |
| Ubuntu |  | [![](https://img.shields.io/travis/USER/REPO.svg)]() |
| Windows |  | [![](https://img.shields.io/travis/USER/REPO.svg)]() |


## 模块进度
| 模块 | 描述 | 进度 |
|:--:|:--|:--:|
| public | 公有代码工具，如映射表、数学函数、字符串等 |  | 
| async | 异步工具，包含有：线程、线程池、定时器，封装于boost |  | 
| grpc |  |  | 
| http |  |  | 
| json | JSON解析工具，封装于Jsoncpp |  | 
| log | 日志工具，封装于Google的glog |  | 
| mmap |  |  | 
| mysql |  |  | 
| redis |  |  | 
| sqlite |  |  | 
| websocket |  |  | 
| xml |  |  | 
| zmq |  |  | 
|  |  |  | 
| tests | 测试用例 |  | 
|  |  |  | 


## 使用安装
``` shell
    mkdir release && cd release
    cmake -DCMAKE_BUILD_TYPE=Release ..
    make
    make install
```


## 使用

