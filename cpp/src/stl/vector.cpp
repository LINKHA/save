#include <iostream>
#include <vector>

void vector_show() {
	// 初始化vector
	std::vector<int> vec;

	// 使用push_back添加元素
	vec.push_back(10);
	vec.push_back(20);

	// 使用insert插入元素
	vec.insert(vec.begin(), 5); // 在开始插入5
	vec.insert(vec.begin() + 2, 15); // 在第三个位置插入15

	// 使用emplace在末尾构造元素
	vec.emplace(vec.end(), 25);

	// 使用emplace_back直接在末尾构造元素
	vec.emplace_back(30);

	// 访问元素
	std::cout << "First element: " << vec[0] << std::endl;
	std::cout << "Second element: " << vec.at(1) << std::endl;
	std::cout << "First element (using front): " << vec.front() << std::endl;
	std::cout << "Last element (using back): " << vec.back() << std::endl;

	// 删除元素
	vec.pop_back(); // 删除最后一个元素
	vec.erase(vec.begin() + 2); // 删除第三个元素

	// 输出当前vector的内容
	std::cout << "Current vector: ";
	for (int i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// 清空vector
	vec.clear();

	// 检查是否为空
	if (vec.empty()) {
		std::cout << "Vector is now empty." << std::endl;
	}
}