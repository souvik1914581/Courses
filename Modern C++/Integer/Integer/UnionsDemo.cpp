#include <iostream>
#include <cstdint>

struct IOREG {
	uint8_t m_data;
	IOREG() {
		m_data = 0;
		std::cout << __FUNCSIG__ << std::endl;
	}
	~IOREG() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	const IOREG& operator = (uint8_t x) {
		IOREG temp;
		temp.m_data = x;
		return temp;
	}
};

struct MEMREG {
	uint8_t m_data;
	MEMREG() {
		m_data = 0;
		std::cout << __FUNCSIG__ << std::endl;
	}
	~MEMREG() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};

union REG {
	IOREG a;		//Default constructor is a deleted function
	MEMREG b;
	std::string str;	//This is the largest member of the union
	REG() {			//Need to define constructor and destructor
		std::cout << __FUNCSIG__ << std::endl;
	}
	~REG() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};

int main() {
	using namespace std::string_literals;
	REG reg;
	//reg.str = "Hola DEA!"s;	//This causes undefined behavior as memory is not yet initialized

	//new (&reg.str) std::string("Hola DEA"s);
	new (&reg.a) IOREG{};	//initialization using placement new
	reg.a.~IOREG();		//need to manually invoke destructor
	return 0;
}