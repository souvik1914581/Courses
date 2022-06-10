#include "Integer.h"

//Default constructor
Integer::Integer()
{
	std::cout << "Default constructor" << std::endl;
	m_ptr = new int(0);
}

//Parameterised constructor
Integer::Integer(const int&& val) :Integer()
{
	std::cout << "Parameterised constructor" << std::endl;
	*m_ptr = val;
}

//Destructor
Integer::~Integer()
{
	std::cout << "Destructor" << std::endl;
	delete m_ptr;
}

//Copy constructor
Integer::Integer(const Integer& that)
{
	std::cout << "Copy constructor" << std::endl;
	if (this == &that)
		return;
	delete m_ptr;
	m_ptr = new int(that.GetValue());
}

//Move constructor
Integer::Integer(Integer&& that) noexcept
{
	std::cout << "Move constructor" << std::endl;
	if (this == &that)
		return;
	delete m_ptr;
	m_ptr = that.m_ptr;
	that.m_ptr = nullptr;
}

//Copy assignment operator
Integer& Integer::operator=(const Integer& that)
{
	std::cout << "Copy assignment operator" << std::endl;
	if (this == &that)
		return *this;
	delete m_ptr;
	m_ptr = new int(that.GetValue());
	return *this;
}

//Move assignment opertor
Integer& Integer::operator=(const Integer&& that) noexcept
{
	std::cout << "Move assignment operator" << std::endl;
	if (this == &that)
		return *this;
	delete m_ptr;
	m_ptr = that.m_ptr;
	return *this;
}

//Addition operator
Integer Integer::operator+(const Integer& that)
{
	std::cout << "Addition operator" << std::endl;
	Integer result;
	*result.m_ptr = GetValue() + that.GetValue();
	return result;
}



std::ostream& operator << (std::ostream& out, const Integer& that)
{
	std::cout << " << operator" << std::endl;
	out << that.GetValue() << std::endl;
	return out;
}
