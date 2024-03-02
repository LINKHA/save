#include <iostream>
#include <vector>

void vector_show() {
	// ��ʼ��vector
	std::vector<int> vec;

	// ʹ��push_back���Ԫ��
	vec.push_back(10);
	vec.push_back(20);

	// ʹ��insert����Ԫ��
	vec.insert(vec.begin(), 5); // �ڿ�ʼ����5
	vec.insert(vec.begin() + 2, 15); // �ڵ�����λ�ò���15

	// ʹ��emplace��ĩβ����Ԫ��
	vec.emplace(vec.end(), 25);

	// ʹ��emplace_backֱ����ĩβ����Ԫ��
	vec.emplace_back(30);

	// ����Ԫ��
	std::cout << "First element: " << vec[0] << std::endl;
	std::cout << "Second element: " << vec.at(1) << std::endl;
	std::cout << "First element (using front): " << vec.front() << std::endl;
	std::cout << "Last element (using back): " << vec.back() << std::endl;

	// ɾ��Ԫ��
	vec.pop_back(); // ɾ�����һ��Ԫ��
	vec.erase(vec.begin() + 2); // ɾ��������Ԫ��

	// �����ǰvector������
	std::cout << "Current vector: ";
	for (int i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// ���vector
	vec.clear();

	// ����Ƿ�Ϊ��
	if (vec.empty()) {
		std::cout << "Vector is now empty." << std::endl;
	}
}