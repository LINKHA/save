#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class A {};

class B {
	virtual void b() {
		cout << "B_b" << endl;
	}

	int b_v;
};

class C : public B
{
	virtual void b() {
		cout << "C_b" << endl;
	}
	virtual void c() {
		cout << "C_c" << endl;
	}

	int c_v;
};

class D
{

	virtual void b_f() {
		cout << "C_b" << endl;
	}

	char a;
	char b;
	//char c;
	int d;
	double ddd;
	int dww;
};


int main() {
	
	//int a = sizeof(A);
	//int b = sizeof(B);
	//int c = sizeof(C);
	/*int d = sizeof(D);
	cout << d << endl;*/

	string ss = "npos";


	return 0;
}
