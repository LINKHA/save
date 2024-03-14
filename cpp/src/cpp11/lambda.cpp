#include <iostream>
#include <vector>
#include <algorithm>
namespace lambda {
	int show() {
		std::vector<int> nums = { 1, 2, 3, 4, 5 };
		int multiplier = 2; // �ⲿ����


		// Lambda ���ʽ��Ϊν�ʴ��ݸ���׼�㷨 sort
		std::sort(nums.begin(), nums.end(), [](int a, int b) {
			return a > b;  // ��������
			});

		// Lambda ���ʽ��Ϊ��������洢�ڱ����У�������
		auto print = [multiplier](int x, int constant) { // ʹ�� [multiplier] �����ⲿ���� multiplier
			std::cout << (x * multiplier + constant) << " ";
			};
		print(42, 5); // ���ݶ���Ĳ��� 5 �� constant

		// Lambda ���ʽ��Ϊ��������洢�ڱ����У�������
		auto print2 = [=](int x) { // ʹ�� [=] �����ⲿ����
			std::cout << x << " ";
			};
		print2(4);
		return 0;
	}
}
