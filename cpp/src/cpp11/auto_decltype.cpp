#include <iostream>
#include <vector>

namespace auto_decltype {
	int show() {
		// 使用 auto 推导变量类型
		auto x = 5; // x 的类型为 int
		auto y = 3.14; // y 的类型为 double
		auto z = "Hello"; // z 的类型为 const char*

		std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

		// 使用 auto 推导容器中元素的类型
		std::vector<int> numbers = { 1, 2, 3, 4, 5 };
		for (auto num : numbers) {
			std::cout << num << " ";
		}
		//std::cout << std::endl;
		//这里是引用数据
		for (auto& num : numbers) {
			std::cout << num << " ";
		}
		std::cout << std::endl;

		// 使用 decltype 获取表达式的类型
		const int& a = x;
		decltype(a) b = x; // b 的类型为 const int&
		decltype(x + y) c; // c 的类型为 double，但不会执行 x + y

		std::cout << "b: " << b << ", c: " << c << std::endl;

		return 0;
	}

}
