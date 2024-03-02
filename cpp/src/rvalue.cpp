#include <iostream>
#include <string>
using namespace std;

class Value {
public:
	Value() {}
	Value(int data) { this->data = data; }
	int data;
};

class MyObject {
public:
	void add(Value&& obj) {
		value = obj;
	}
	void add(Value& obj) {
		value = obj; //这里没有用右值，所以多复制一次
	}
	void print() {
		cout << value.data << endl;
	}
	Value value;
};

//int main() {
//	MyObject a;
//	Value v1 = Value(1);
//	a.add(std::move(v1));
//	a.print();
//
//	MyObject b;
//	Value v2 = Value(2);
//	b.add(v2);
//	b.print();
//	return 0;
//}
