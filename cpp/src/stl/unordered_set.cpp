#include <iostream>
#include <unordered_set>
namespace unordered_set {
	int show() {
		// ����һ���յ����򼯺�
		std::unordered_set<int> mySet;

		// �򼯺������Ԫ��
		mySet.insert(5);
		mySet.insert(10);
		mySet.insert(15);

		// ɾ�������е�Ԫ��
		mySet.erase(10);

		// ���Ҽ����е�Ԫ��
		int target = 15;
		if (mySet.find(target) != mySet.end()) {
			std::cout << "Element " << target << " found in the set." << std::endl;
		}
		else {
			std::cout << "Element " << target << " not found in the set." << std::endl;
		}

		// ��������е�����Ԫ��
		std::cout << "Elements in the set:";
		for (auto it = mySet.begin(); it != mySet.end(); ++it) {
			std::cout << " " << *it;
		}
		std::cout << std::endl;

		return 0;
	}
}
