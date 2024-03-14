#include <iostream>
#include <vector>
#include <utility> // std::move, std::forward
namespace rvalue {
	class Widget {
	public:
		std::vector<int> data;

		// 默认构造函数
		Widget() : data({ 1, 2, 3 }) {
			std::cout << "默认构造 Widget" << std::endl;
		}

		// 拷贝构造函数
		Widget(const Widget& w) : data(w.data) {
			std::cout << "拷贝构造 Widget" << std::endl;
		}

		// 移动构造函数
		Widget(Widget&& w) noexcept : data(std::move(w.data)) {
			std::cout << "移动构造 Widget" << std::endl;
		}

		// 工厂函数，返回一个 Widget 实例
		static Widget createWidget() {
			return Widget();
		}

		// 接受右值引用参数的函数，演示移动语义
		void acceptWidget(Widget&& w) {
			data = std::move(w.data); // 使用 std::move 进行移动赋值
			std::cout << "通过移动语义接受 Widget" << std::endl;
		}

		// 接受左值引用参数的函数，演示移动语义
		void acceptWidget(Widget& w) {
			data = std::move(w.data); // 使用 std::move 进行移动赋值
			std::cout << "通过移动语义接受 Widget" << std::endl;
		}

		// 完美转发函数模板
		template<typename T>
		void perfectlyForward(T&& t) {
			acceptWidget(std::forward<T>(t)); // 完美转发 t 到 acceptWidget
		}
	};

	int show() {
		Widget w1; // 调用默认构造函数
		Widget w2 = Widget::createWidget(); // 利用返回值优化 (RVO)，直接构造 w2

		Widget w3(std::move(w1)); // 调用移动构造函数，w1 的资源被转移给 w3

		Widget w4; // 再次调用默认构造函数
		w4.acceptWidget(Widget::createWidget()); // 临时对象作为右值传入

		//完美转发右值
		Widget w5;
		w5.perfectlyForward(Widget()); // 通过完美转发，传递临时对象到 acceptWidget
		//完美转发左值
		Widget w6;
		w5.perfectlyForward(w6); // 通过完美转发，传递临时对象到 acceptWidget
		return 0;
	}
}