#include <iostream>
#include <functional>
namespace bind {
	// 普通函数
	void greet(const std::string& greeting, const std::string& name) {
		std::cout << greeting << ", " << name << "!" << std::endl;
	}

	// 成员函数
	class Greeter {
	public:
		void sayHello(const std::string& name) {
			std::cout << "Hello, " << name << "!" << std::endl;
		}
	};

	int show() {
		// 绑定普通函数，并指定部分参数
		auto greetFunc = std::bind(greet, "Good morning", std::placeholders::_1);
		greetFunc("Alice"); // 输出：Good morning, Alice!

		// 创建 Greeter 对象
		Greeter greeter;

		// 绑定成员函数，并指定对象和部分参数
		auto sayHelloFunc = std::bind(&Greeter::sayHello, &greeter, std::placeholders::_1);
		sayHelloFunc("Bob"); // 输出：Hello, Bob!

		return 0;
	}
}

