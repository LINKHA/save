package main

import "fmt"

func main() {
	// 创建并初始化一个空的 map
	emptyMap := make(map[string]int)
	fmt.Println("Empty Map:", emptyMap)

	// 创建并初始化一个带有初始键值对的 map
	person := map[string]string{
		"name":  "John",
		"age":   "30",
		"email": "john@example.com",
	}
	fmt.Println("Person Map:", person)

	// 添加元素到 map 中
	person["address"] = "123 Main St"
	fmt.Println("Updated Person Map:", person)

	// 获取 map 中的值
	name := person["name"]
	fmt.Println("Name:", name)

	// 检查 map 中的键是否存在
	_, ok := person["gender"]
	fmt.Println("Gender exists?", ok)

	// 删除 map 中的键值对
	delete(person, "age")
	fmt.Println("Updated Person Map (after deletion):", person)

	// 迭代遍历 map
	for key, value := range person {
		fmt.Printf("%s: %s\n", key, value)
	}

	// 获取 map 的长度
	length := len(person)
	fmt.Println("Length of the Person Map:", length)
}
