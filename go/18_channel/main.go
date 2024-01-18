package main

import (
	"fmt"
	"sync"
	"time"
)

var (
	ch  chan int
	ch2 chan int
)

// 创建一个管道：常用作根上下文。
// 这会创建一个整数类型的无缓冲管道。
func fun1() {
	ch = make(chan int)
}

// 发送数据到管道：
// 这将整数值42发送到管道中。
func fun2() {
	fmt.Println("1----------|", "")
	go func() {
		ch <- 42
	}()
	fmt.Println("2----------|", "")
}

// 从管道接收数据：
// 这将从管道中接收一个整数值并存储在data变量中。
func fun3() {
	data := <-ch
	fmt.Println("3----------|", data)
}

// 关闭管道：
// 这会关闭管道，表示不再向管道发送数据。
func fun4() {
	close(ch)
}

// 使用带缓冲的管道：
// 这会创建一个容量为10的带缓冲整数管道，允许发送多个数据项而不立即阻塞。
func fun5() {
	ch2 = make(chan int, 10)
}

// 使用select选择不同的管道操作：
// select语句用于选择多个管道操作中的一个，以处理多路复用的情况。
func fun6() {
	select {
	case data := <-ch:
		fmt.Println("1----------|", data)
		// 从ch1接收数据
	case ch2 <- 42:
		// 向ch2发送数据
	case <-time.After(time.Second):
		// 等待1秒后执行
	}
}

// 管道作为函数参数：
func sendData(ch chan<- int) {
	ch <- 42
}

func receiveData(ch <-chan int) {
	data := <-ch
	fmt.Println("1----------|", data)
}

// 管道的循环和迭代：
func fun7() {
	for data := range ch {
		fmt.Println("1----------|", data)
		// 从管道中迭代接收数据
	}
}

// 使用sync包中的WaitGroup等同步工具与管道结合：
// 这个示例结合了sync.WaitGroup和管道，以等待多个协程完成后关闭管道并读取数据。

// 这些示例展示了Go语言中管道的一些常见用法，用于协程之间的通信和同步。管道是一种强大的工具，使得多个协程之间能够安全地共享数据和协同工作。
func fun8() {
	var wg sync.WaitGroup

	ch2 := make(chan int)

	for i := 0; i < 3; i++ {
		wg.Add(1)
		go func(id int) {
			defer wg.Done()
			ch2 <- id
		}(i)
	}

	go func() {
		wg.Wait()
		close(ch2)
	}()

	for data := range ch2 {
		fmt.Println(data)
	}
}

// 当channel关闭的时候
// 当一个管道被关闭后，虽然不能再向该管道写入数据，但仍然可以从该管道读取数据。读取已关闭管道的数据不会导致运行时错误，而是会返回通道类型的零值，如 0 对于整数类型的管道。
func fun9() {
	ch := make(chan int, 1)

	// 关闭管道
	close(ch)

	// 尽管管道已经关闭，但如果你尝试这样做，它会在运行时产生恐慌：
	// ch <- 42

	// 从已关闭的管道读取数据
	data1, ok1 := <-ch // 读取数据和状态
	data2, ok2 := <-ch // 从一个空的、已关闭的管道读取数据

	fmt.Println(data1, ok1) // 输出: 0 false，表示从空的已关闭的管道读取得到零值，并且读取操作指示通道已经关闭
	fmt.Println(data2, ok2) // 输出: 0 false，同上

	// 当从已关闭的管道读取数据时，除了得到该类型的零值外，还可以得到一个布尔值，它会告诉你通道是否已经关闭（false表示关闭）。
}

func main() {
	fun1()
	close(ch)
	fun2()
	fun3()

	// time.Sleep(time.Duration(100) * time.Second)
	select {}
}
