package main

import (
	"fmt"
)

func main() {
	ch := make(chan int, 1)

	// 关闭管道
	close(ch)

	// 尽管管道已经关闭，但如果你尝试这样做，它会在运行时产生恐慌：
	// ch <- 42

	// 从已关闭的管道读取数据
	data1 := <-ch      // 读取数据和状态
	data2, ok2 := <-ch // 从一个空的、已关闭的管道读取数据

	fmt.Println(data1)      // 输出: 0 false，表示从空的已关闭的管道读取得到零值，并且读取操作指示通道已经关闭
	fmt.Println(data2, ok2) // 输出: 0 false，同上

	// 当从已关闭的管道读取数据时，除了得到该类型的零值外，还可以得到一个布尔值，它会告诉你通道是否已经关闭（false表示关闭）。
}
