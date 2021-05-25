package main

import (
    "fmt"
    "net"
    "strings"
)

// 读取消息
func handleConnection(udpConn *net.UDPConn) {

    // 读取数据
    buf := make([]byte, 1024)
    len, udpAddr, err := udpConn.ReadFromUDP(buf)
    if err != nil{
        return
    }
    logContent := strings.Replace(string(buf),"\n","",1)
    fmt.Println("server read len:", len)
    fmt.Println("server read data:", logContent)

    // 发送数据
    len, err = udpConn.WriteToUDP([]byte("ok\r\n"), udpAddr)
    if err != nil{
        return
    }

    fmt.Println("server write len:", len,"\n")
}

// udp 服务端
func main() {
    /*
        network: "udp"、"udp4"或"udp6"
        addr: "host:port"或"[ipv6-host%zone]:port"
    */
    udpAddr, _ := net.ResolveUDPAddr("udp4", "127.0.0.1:9998")

    //监听端口
    udpConn, err := net.ListenUDP("udp", udpAddr)
    if err != nil {
        fmt.Println(err)
    }
    defer udpConn.Close()

    fmt.Println("udp listening ... ")

    //udp不需要Accept
    for {
        handleConnection(udpConn)
    }
}

