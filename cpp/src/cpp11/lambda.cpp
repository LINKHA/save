#include <iostream>
#include <vector>
#include <algorithm>
namespace lambda {
	int show() {
		std::vector<int> nums = { 1, 2, 3, 4, 5 };
		int multiplier = 2; // 外部变量


		// Lambda 表达式作为谓词传递给标准算法 sort
		std::sort(nums.begin(), nums.end(), [](int a, int b) {
			return a > b;  // 降序排序
			});

		// Lambda 表达式作为函数对象存储在变量中，并调用
		auto print = [multiplier](int x, int constant) { // 使用 [multiplier] 捕获外部变量 multiplier
			std::cout << (x * multiplier + constant) << " ";
			};
		print(42, 5); // 传递额外的参数 5 给 constant

		// Lambda 表达式作为函数对象存储在变量中，并调用
		auto print2 = [=](int x) { // 使用 [=] 捕获外部变量
			std::cout << x << " ";
			};
		print2(4);
		return 0;
	}
}
