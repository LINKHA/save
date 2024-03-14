#include <iostream>
#include <vector>
namespace initialization_list {

class MyClass {
public:
	int x;
	double y;

	// 类支持列表初始化需要提供构造函数
	MyClass(int x, double y) : x(x), y(y) {}
};

int show() {
	// 内置类型的列表初始化，防止窄化转换
	int a{ 10 };
	// float b{4.5}; // 编译错误，窄化转换

	// 数组的列表初始化
	int arr[]{ 1, 2, 3, 4, 5 };

	// STL容器的列表初始化
	std::vector<int> vec{ 1, 2, 3, 4, 5 };

	// 自定义类型的列表初始化
	MyClass obj{ 10, 20.5 };

	// 使用auto进行类型推导
	auto anotherObj = MyClass{ 5, 10.5 };

	std::cout << "a: " << a << "\n";
	std::cout << "vec[2]: " << vec[2] << "\n";
	std::cout << "obj: (" << obj.x << ", " << obj.y << ")\n";
	std::cout << "anotherObj: (" << anotherObj.x << ", " << anotherObj.y << ")\n";

	return 0;
}
}
