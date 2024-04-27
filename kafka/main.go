package main

import (
	"context"
	"fmt"
	"log"

	"github.com/go-redis/redis/v8"
)

func main() {
	// 创建 Redis 客户端
	client := redis.NewClient(&redis.Options{
		Addr:     "localhost:36379",  // Redis 服务器地址
		Password: "G62m50oigInC30sf", // 密码，如果有的话
		DB:       0,                  // 使用默认数据库
	})

	// 创建上下文
	ctx := context.Background()

	// 订阅频道
	channel := "sl_window"
	pubsub := client.Subscribe(ctx, channel)

	// 确保关闭连接
	defer func() {
		if err := pubsub.Close(); err != nil {
			log.Fatal(err)
		}
	}()

	// 循环监听消息
	for {
		// 接收消息
		msg, err := pubsub.ReceiveMessage(ctx)
		if err != nil {
			log.Fatal(err)
		}

		// 处理消息
		fmt.Printf("Received message from channel %s: %s\n", msg.Channel, msg.Payload)
	}
}
