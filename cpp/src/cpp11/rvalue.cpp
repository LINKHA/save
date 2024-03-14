#include <iostream>
#include <vector>
#include <utility> // std::move, std::forward
namespace rvalue {
	class Widget {
	public:
		std::vector<int> data;

		// Ĭ�Ϲ��캯��
		Widget() : data({ 1, 2, 3 }) {
			std::cout << "Ĭ�Ϲ��� Widget" << std::endl;
		}

		// �������캯��
		Widget(const Widget& w) : data(w.data) {
			std::cout << "�������� Widget" << std::endl;
		}

		// �ƶ����캯��
		Widget(Widget&& w) noexcept : data(std::move(w.data)) {
			std::cout << "�ƶ����� Widget" << std::endl;
		}

		// ��������������һ�� Widget ʵ��
		static Widget createWidget() {
			return Widget();
		}

		// ������ֵ���ò����ĺ�������ʾ�ƶ�����
		void acceptWidget(Widget&& w) {
			data = std::move(w.data); // ʹ�� std::move �����ƶ���ֵ
			std::cout << "ͨ���ƶ�������� Widget" << std::endl;
		}

		// ������ֵ���ò����ĺ�������ʾ�ƶ�����
		void acceptWidget(Widget& w) {
			data = std::move(w.data); // ʹ�� std::move �����ƶ���ֵ
			std::cout << "ͨ���ƶ�������� Widget" << std::endl;
		}

		// ����ת������ģ��
		template<typename T>
		void perfectlyForward(T&& t) {
			acceptWidget(std::forward<T>(t)); // ����ת�� t �� acceptWidget
		}
	};

	int show() {
		Widget w1; // ����Ĭ�Ϲ��캯��
		Widget w2 = Widget::createWidget(); // ���÷���ֵ�Ż� (RVO)��ֱ�ӹ��� w2

		Widget w3(std::move(w1)); // �����ƶ����캯����w1 ����Դ��ת�Ƹ� w3

		Widget w4; // �ٴε���Ĭ�Ϲ��캯��
		w4.acceptWidget(Widget::createWidget()); // ��ʱ������Ϊ��ֵ����

		//����ת����ֵ
		Widget w5;
		w5.perfectlyForward(Widget()); // ͨ������ת����������ʱ���� acceptWidget
		//����ת����ֵ
		Widget w6;
		w5.perfectlyForward(w6); // ͨ������ת����������ʱ���� acceptWidget
		return 0;
	}
}