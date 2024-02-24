package main

import (
	"fmt"
	"net"

	"golang.org/x/sys/unix"
)

func main() {
	// 创建监听的socket
	ln, err := net.Listen("tcp", ":8080")
	if err != nil {
		fmt.Println("Listen error:", err)
		return
	}
	defer ln.Close()

	// 创建epoll
	epfd, err := unix.EpollCreate1(0)
	if err != nil {
		fmt.Println("EpollCreate1 error:", err)
		return
	}
	defer unix.Close(epfd)

	// 将监听的文件描述符添加到epoll中
	file, err := ln.(*net.TCPListener).File()
	if err != nil {
		fmt.Println("Get file descriptor error:", err)
		return
	}
	defer file.Close()

	lfd := file.Fd()

	ev := unix.EpollEvent{
		Events: unix.EPOLLIN,
		Fd:     int32(lfd),
	}
	if err := unix.EpollCtl(epfd, unix.EPOLL_CTL_ADD, int(lfd), &ev); err != nil {
		fmt.Println("EpollCtl error:", err)
		return
	}

	// 事件循环
	events := make([]unix.EpollEvent, 100)
	for {
		nevents, err := unix.EpollWait(epfd, events, -1)
		if err != nil {
			fmt.Println("EpollWait error:", err)
			continue
		}

		for i := 0; i < nevents; i++ {
			if events[i].Fd == int32(lfd) {
				// 接受新的连接
				conn, err := ln.Accept()
				if err != nil {
					fmt.Println("Accept error:", err)
					continue
				}
				conn.Close() // 在这个示例中，我们只是接受连接然后关闭它
			}
		}
	}
}
