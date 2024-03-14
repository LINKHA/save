#include <iostream>
#include <vector>
namespace initialization_list {

class MyClass {
public:
	int x;
	double y;

	// ��֧���б��ʼ����Ҫ�ṩ���캯��
	MyClass(int x, double y) : x(x), y(y) {}
};

int show() {
	// �������͵��б��ʼ������ֹխ��ת��
	int a{ 10 };
	// float b{4.5}; // �������խ��ת��

	// ������б��ʼ��
	int arr[]{ 1, 2, 3, 4, 5 };

	// STL�������б��ʼ��
	std::vector<int> vec{ 1, 2, 3, 4, 5 };

	// �Զ������͵��б��ʼ��
	MyClass obj{ 10, 20.5 };

	// ʹ��auto���������Ƶ�
	auto anotherObj = MyClass{ 5, 10.5 };

	std::cout << "a: " << a << "\n";
	std::cout << "vec[2]: " << vec[2] << "\n";
	std::cout << "obj: (" << obj.x << ", " << obj.y << ")\n";
	std::cout << "anotherObj: (" << anotherObj.x << ", " << anotherObj.y << ")\n";

	return 0;
}
}
