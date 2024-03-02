#include <iostream>
#include <list>

void list_show() {
	// ��ʼ��list
	std::list<int> myList;

	// ʹ��push_back��listĩβ���Ԫ��
	myList.push_back(10);
	myList.push_back(20);

	// ʹ��insert����Ԫ��
	auto it = myList.begin();
	myList.insert(it, 5); // �ڿ�ʼ����5����ʱit��ָ��ԭ���ĵ�һ��Ԫ��

	// ʹ��emplace��ָ��λ�ù���Ԫ��
	it = myList.begin(); // ���µ�����ָ���һ��Ԫ��
	std::advance(it, 2); // �ƶ���������������Ԫ�ص�λ��
	myList.emplace(it, 15); // �ڵ�����λ�ù���Ԫ��15

	// ʹ��emplace_back��ĩβֱ�ӹ���Ԫ��
	myList.emplace_back(25);

	// ����Ԫ��
	// listû���ṩֱ��ͨ���±���ʵķ�ʽ��ͨ��ʹ�õ���������
	std::cout << "List elements: ";
	for (const auto& elem : myList) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	// ɾ��Ԫ��
	myList.pop_back(); // ɾ�����һ��Ԫ��
	it = myList.begin();
	std::advance(it, 2); // �ƶ���������Ԫ��
	myList.erase(it); // ɾ��������Ԫ��

	// �����ǰlist������
	std::cout << "Current list: ";
	for (const auto& elem : myList) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	// ���list
	myList.clear();

	// ����Ƿ�Ϊ��
	if (myList.empty()) {
		std::cout << "List is now empty." << std::endl;
	}
}
