package main

import (
    "fmt"
    "net"
    "os"
    "time"
)

func main() {

    ip := net.ParseIP("127.0.0.1")
    srcAddr := &net.UDPAddr{IP: ip, Port: 0}
    dstAddr := &net.UDPAddr{IP: ip, Port: 9998}
    conn, err := net.DialUDP("udp", srcAddr, dstAddr)
    if err != nil {
        fmt.Println(err)
        os.Exit(2)
    }
    defer conn.Close()

    var lastime int64 = time.Now().UnixNano()
    fmt.Printf("lastime: %d\n", lastime)
    i := 0
    //for {
    for a:=0; a < 10000000; a++ {
        // 发送数据
        _, err = conn.Write([]byte("I'm Go!"))
        /*
        if err != nil {
            fmt.Println(err)
            return
        }
        */

        /*
        i++
        var curtime int64 = time.Now().UnixNano()
        if(curtime >= lastime + 1000000000){
            fmt.Printf("curtime: %d, count=%d\n", curtime, i)
            break
        }
        */
    }

    var curtime int64 = time.Now().UnixNano()
    fmt.Printf("curtime: %d, count=%d\n", curtime, i)
}
