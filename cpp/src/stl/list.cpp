#include <iostream>
#include <list>

void list_show() {
	// 初始化list
	std::list<int> myList;

	// 使用push_back在list末尾添加元素
	myList.push_back(10);
	myList.push_back(20);

	// 使用insert插入元素
	auto it = myList.begin();
	myList.insert(it, 5); // 在开始插入5，此时it仍指向原来的第一个元素

	// 使用emplace在指定位置构造元素
	it = myList.begin(); // 更新迭代器指向第一个元素
	std::advance(it, 2); // 移动迭代器到第三个元素的位置
	myList.emplace(it, 15); // 在第三个位置构造元素15

	// 使用emplace_back在末尾直接构造元素
	myList.emplace_back(25);

	// 访问元素
	// list没有提供直接通过下标访问的方式，通常使用迭代器遍历
	std::cout << "List elements: ";
	for (const auto& elem : myList) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	// 删除元素
	myList.pop_back(); // 删除最后一个元素
	it = myList.begin();
	std::advance(it, 2); // 移动到第三个元素
	myList.erase(it); // 删除第三个元素

	// 输出当前list的内容
	std::cout << "Current list: ";
	for (const auto& elem : myList) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	// 清空list
	myList.clear();

	// 检查是否为空
	if (myList.empty()) {
		std::cout << "List is now empty." << std::endl;
	}
}
