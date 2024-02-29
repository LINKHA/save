package main

import (
	"fmt"
	"net"
	"time"
)

func main() {
	// 连接到服务器
	conn, err := net.Dial("tcp", "localhost:8080")
	if err != nil {
		fmt.Println("Dial error:", err)
		return
	}
	defer conn.Close()

	// 发送数据
	_, err = conn.Write([]byte("Hello, Server!"))
	if err != nil {
		fmt.Println("Write error:", err)
		return
	}

	// 等待一会，以便可以看到服务端接收到消息
	time.Sleep(1 * time.Second)
}
