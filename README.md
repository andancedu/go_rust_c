# go_rust_c

This is a simple performance comparison test example about c, go and rust language

## 启动 UDP Server

### 编译 GoUDPServer.go

执行下面命令进入go 语言的编译

```
go build GoUDPServer.go
```

### 启动GoUDPServer
```
./GoUDPServer
```

## 测试 Go 程序

### 编译Go UDP客户端

```
go build GoUDPClient
```

### 执行Go测试程序

```
./GoUDPClient
```

## 测试 C 程序

### 在Mac下编译
执行下面命令进行编译
```
clang -o udpclient udpclient.c
```

### Linux
执行下面命令进行编译
```
gcc -o udpclient udpclient.c
```

### 执行C客户端程序
```
./udpclient
```

## 测试 RUST 程序

### 编译
执行下面命令进行编译
```
rustc rust_client.c
```

### 执行测试程序
```
./rust_client
```

### 注意
所有结果都是以纳秒为单位，换算公式：

1秒(s)=1000毫秒(ms)=1000 000 微秒（us) = 1000 000 000 纳秒（ns)

