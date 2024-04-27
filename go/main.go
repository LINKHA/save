package main

import "fmt"

func main() {
	// 创建一个原始的 slice
	originalSlice := []int{1, 2, 3, 4, 5}
	fmt.Println("Original Slice:", originalSlice) // 输出: Original Slice: [1 2 3 4 5]

	// 从原始的 slice 中创建一个新的 slice
	newSlice := originalSlice[1:3]
	fmt.Println("New Slice:", newSlice) // 输出: New Slice: [2 3]

	// 修改原始的 slice
	originalSlice[1] = 100
	fmt.Println("Modified Original Slice:", originalSlice) // 输出: Modified Original Slice: [1 100 3 4 5]

	// 查看新的 slice
	fmt.Println("New Slice after modifying original:", newSlice) // 输出: New Slice after modifying original: [100 3]
}
