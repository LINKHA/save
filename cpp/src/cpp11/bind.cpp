#include <iostream>
#include <functional>
namespace bind {
	// ��ͨ����
	void greet(const std::string& greeting, const std::string& name) {
		std::cout << greeting << ", " << name << "!" << std::endl;
	}

	// ��Ա����
	class Greeter {
	public:
		void sayHello(const std::string& name) {
			std::cout << "Hello, " << name << "!" << std::endl;
		}
	};

	int show() {
		// ����ͨ��������ָ�����ֲ���
		auto greetFunc = std::bind(greet, "Good morning", std::placeholders::_1);
		greetFunc("Alice"); // �����Good morning, Alice!

		// ���� Greeter ����
		Greeter greeter;

		// �󶨳�Ա��������ָ������Ͳ��ֲ���
		auto sayHelloFunc = std::bind(&Greeter::sayHello, &greeter, std::placeholders::_1);
		sayHelloFunc("Bob"); // �����Hello, Bob!

		return 0;
	}
}

