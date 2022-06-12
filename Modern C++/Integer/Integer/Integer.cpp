#include "Integer.h"

#ifdef _PRINT_FUNC_SIGN_
#define PrintFunctionSignature()	\
{\
	std::cout << __FUNCSIG__ << std::endl;\
}
#else
#define PrintFunctionSignature()
#endif


//Default constructor
Integer::Integer()
{
	PrintFunctionSignature();
	m_ptr = new int(0);
}

Integer::Integer(const int val):Integer()
{
	PrintFunctionSignature();
	*m_ptr = val;
}

//Parameterised constructor
//Integer::Integer(const int&& val) :Integer()
//{
//	PrintFunctionSignature();
//	*m_ptr = val;
//}

//Destructor
Integer::~Integer()
{
	PrintFunctionSignature();
	delete m_ptr;
}

//Copy constructor
Integer::Integer(const Integer& that)
{
	PrintFunctionSignature();
	if (this == &that)
		return;
	delete m_ptr;
	m_ptr = new int(that.GetValue());
}

//Move constructor
Integer::Integer(Integer&& that) noexcept
{
	PrintFunctionSignature();
	if (this == &that)
		return;
	delete m_ptr;
	m_ptr = that.m_ptr;
	that.m_ptr = nullptr;
}

//Copy assignment operator
Integer& Integer::operator=(const Integer& that)
{
	PrintFunctionSignature();
	if (this == &that)
		return *this;
	delete m_ptr;
	m_ptr = new int(that.GetValue());
	return *this;
}

//Move assignment opertor
Integer& Integer::operator=(const Integer&& that) noexcept
{
	PrintFunctionSignature();
	if (this == &that)
		return *this;
	delete m_ptr;
	m_ptr = that.m_ptr;
	return *this;
}

//Addition operator
Integer Integer::operator+(const Integer& that)
{
	PrintFunctionSignature();
	Integer result;
	*result.m_ptr = GetValue() + that.GetValue();
	return result;
}

Integer& Integer::operator++()
{
	++*m_ptr;
	return *this;
}

Integer Integer::operator++(int)
{
	Integer temp(this->GetValue());
	++*m_ptr;
	return temp;
}



std::ostream& operator << (std::ostream& out, const Integer& that)
{
	PrintFunctionSignature();
	out << that.GetValue() << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Integer& that)
{
	int tempVal;
	in >> tempVal;
	that.SetValue(tempVal);
	return in;
}
