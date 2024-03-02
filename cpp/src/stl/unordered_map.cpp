#include <iostream>
#include <unordered_map>
#include <string>

int main() {
	// 初始化unordered_map
	std::unordered_map<std::string, int> myMap;

	// 使用insert添加元素
	myMap.insert({ "apple", 5 });
	myMap.insert(std::make_pair("banana", 2));

	// 使用emplace直接在容器内构造元素
	myMap.emplace("cherry", 3);
	myMap.emplace(std::make_pair("date", 4));

	// 访问元素
	std::cout << "apple count: " << myMap["apple"] << std::endl;
	// 使用at方法访问，如果键不存在则抛出std::out_of_range异常
	try {
		std::cout << "banana count: " << myMap.at("banana") << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Key not found: " << e.what() << std::endl;
	}

	// 检查元素是否存在
	if (myMap.find("cherry") != myMap.end()) {
		std::cout << "cherry found" << std::endl;
	}

	// 更新元素
	myMap["apple"] = 10;

	// 删除元素
	myMap.erase("banana");

	// 遍历unordered_map
	std::cout << "Current map: " << std::endl;
	for (const auto& pair : myMap) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}

	// 获取元素数量
	std::cout << "Number of elements: " << myMap.size() << std::endl;

	// 清空unordered_map
	myMap.clear();

	// 检查是否为空
	if (myMap.empty()) {
		std::cout << "Map is now empty." << std::endl;
	}

	return 0;
}
