#pragma once
#include "Integer.h"

class Number
{
	Integer m_integer{};
public:
	Number(const int val) :m_integer{ val }
	{

	}

	/*Number(const Number& n1) : m_integer{ m_integer.GetValue() }
	{

	}*/

	
};

Number CreateNumber(const int num);
