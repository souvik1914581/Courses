#include "Integer.h"
int main(int argc, char** argv)
{
	Integer i1(5);
	Integer i2(10);
	Integer i3(i1 + i2);
	Integer i4(i3);
	std::cout << i4;
	return 0;
}