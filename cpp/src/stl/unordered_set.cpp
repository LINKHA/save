#include <iostream>
#include <unordered_set>
namespace unordered_set {
	int show() {
		// 创建一个空的无序集合
		std::unordered_set<int> mySet;

		// 向集合中添加元素
		mySet.insert(5);
		mySet.insert(10);
		mySet.insert(15);

		// 删除集合中的元素
		mySet.erase(10);

		// 查找集合中的元素
		int target = 15;
		if (mySet.find(target) != mySet.end()) {
			std::cout << "Element " << target << " found in the set." << std::endl;
		}
		else {
			std::cout << "Element " << target << " not found in the set." << std::endl;
		}

		// 输出集合中的所有元素
		std::cout << "Elements in the set:";
		for (auto it = mySet.begin(); it != mySet.end(); ++it) {
			std::cout << " " << *it;
		}
		std::cout << std::endl;

		return 0;
	}
}
