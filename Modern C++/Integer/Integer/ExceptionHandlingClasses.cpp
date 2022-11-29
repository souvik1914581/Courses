#include <iostream>
#include <memory>
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

class TestException {
private:
	std::unique_ptr<A> m_ptrA;
	//A* m_rawPtrA;
	B m_objB;
public:
	TestException() {
		PRINT_FUNC();
		m_ptrA.reset(new A);
		//m_rawPtrA = new A;
		throw std::runtime_error("Exception in Constructor!");	//~TestException() will never be called. Only concrete objects of class TestException will be freed.
	}
	~TestException() {
		PRINT_FUNC();
		//try {
		//	throw std::runtime_error("Exception in Destructor!");	//causes process to Abort(). if raw pointer used for A, its never freed
		//}
		//catch (std::exception& ex) {		/*Any exception in Destructor must be caught locally*/
		//	std::cout << ex.what() << std::endl;
		//}
		//delete m_rawPtrA;
	}

};

int main() {
	try {
		TestException t1;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
		return 0;
}