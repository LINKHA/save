#include <iostream>
#include <vector>

namespace auto_decltype {
	int show() {
		// ʹ�� auto �Ƶ���������
		auto x = 5; // x ������Ϊ int
		auto y = 3.14; // y ������Ϊ double
		auto z = "Hello"; // z ������Ϊ const char*

		std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

		// ʹ�� auto �Ƶ�������Ԫ�ص�����
		std::vector<int> numbers = { 1, 2, 3, 4, 5 };
		for (auto num : numbers) {
			std::cout << num << " ";
		}
		//std::cout << std::endl;
		//��������������
		for (auto& num : numbers) {
			std::cout << num << " ";
		}
		std::cout << std::endl;

		// ʹ�� decltype ��ȡ���ʽ������
		const int& a = x;
		decltype(a) b = x; // b ������Ϊ const int&
		decltype(x + y) c; // c ������Ϊ double��������ִ�� x + y

		std::cout << "b: " << b << ", c: " << c << std::endl;

		return 0;
	}

}
