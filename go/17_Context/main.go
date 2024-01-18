package main

import (
	"context"
	"fmt"
	"time"
)

var (
	ctx    context.Context
	cancel context.CancelFunc
)

// 创建一个背景上下文：
// 这将创建一个空的背景上下文，通常用作根上下文。
func fun1() {
	ctx = context.Background()
}

// 创建一个带有取消功能的上下文：
// 这将创建一个新的上下文ctx和一个与之相关联的取消函数cancel，用于取消该上下文。
func fun2() {
	ctx, cancel = context.WithCancel(context.Background())
	defer cancel() // 确保在函数退出时调用取消函数
}

// 创建一个带有超时的上下文：
// 这将创建一个带有5秒超时的上下文，当超过指定时间时，上下文会自动取消。
func fun3() {
	ctx, cancel = context.WithTimeout(context.Background(), 5*time.Second)
	defer cancel()
}

// 创建一个带有截止时间的上下文：
// 这将创建一个在指定时间点截止的上下文。
func fun4() {
	deadline := time.Now().Add(2 * time.Second)
	ctx, cancel = context.WithDeadline(context.Background(), deadline)
	// defer cancel()
}

// 在上下文中存储值：
// 这允许将值与上下文相关联，以在整个请求处理链中传递数据。
func fun5() {
	key := "user"
	value := "Alice"
	ctxWithValue := context.WithValue(ctx, key, value)
	fmt.Println("1----------|", ctxWithValue)
}

// 获取上下文中的值：
// 可以使用ctx.Value方法获取上下文中存储的值。
func fun6() {
	val := ctx.Value("user")
	fmt.Println("1----------|", val)
}

// 监视取消信号：
func fun7(id int) {
	fmt.Println(fmt.Sprintf("start func: %d", id))
	go func() {
		select {
		case <-ctx.Done():
			fmt.Println(fmt.Sprintf("finish: %d", id))
		}
	}()
}

func main() {
	fun4()
	fun7(1)
	fun7(2)
	// time.Sleep(time.Duration(2) * time.Second)

	// cancel()
	time.Sleep(time.Duration(100) * time.Second)
}
