#include <iostream>

using namespace std;


template <class T> class auto_ptr {
	private: 
	T* ptr;
	
	public:
	explicit auto_ptr(T* p = 0) : ptr(p) { }
	~auto_ptr() { delete ptr; }
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }
};

void foo0() {
	auto_ptr<string> p(new string("I did one P.O.F!\n"));
	// p->print();
}

void foo1() {
	try {
		auto_ptr<string> p(new string("Oi!\n"));
		throw 20;
	} catch (int e) { cout << "Oops: " << e << "\n"; }
}

int main() {
	foo0();
	// foo1();
	return 0;
}