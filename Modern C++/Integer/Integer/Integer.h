#pragma once
#include <iostream>
#include "GlobalDefines.h"
class Integer {
private:
	int* m_ptr{ nullptr };
public:
	//default constructor
	Integer();

	Integer(const int val);
	
	//Parameterised constructor
	/*Integer(const int&& val);*/
	
	//Destructor
	~Integer();

	//Copy constructor
	Integer(const Integer& that);

	//Move constructor
	Integer(Integer&& that) noexcept;


	//Copy assigment operator
	Integer& operator = (const Integer& that);

	//Move assignment operator
	Integer& operator = (const Integer&& that) noexcept;

	Integer operator + (const Integer& that);

	Integer& operator ++();

	Integer operator ++(int);
	
	friend std::ostream& operator << (std::ostream& ,const Integer& that);

	friend std::istream& operator >> (std::istream&,  Integer& that);

	void operator ()();

	int operator *();

	int*& operator ->();

	inline int GetValue() const
	{
		return *m_ptr;
	}

	void SetValue(const int val)
	{
		*m_ptr = val;
	}
};
