#include <iostream>

#define PRINT_FUNC()	\
	do{ std::cout<<__FUNCSIG__<<std::endl; }while(0);

class A {
public:
	A() {
		PRINT_FUNC();
	}
	~A() {
		PRINT_FUNC();
	}
};

class B {
public:
	B() {
		PRINT_FUNC();
	}
	~B() {
		PRINT_FUNC();
	}
};

class Test {
private:
	A* m_ptrA = nullptr;
	B m_objB;
public:
	Test() {
		PRINT_FUNC();
		m_ptrA{ new A() };
	}
	~Test() {
		PRINT_FUNC();
		delete m_ptrA;
	}

};

int main() {
	Test t1;
	return 0;
}