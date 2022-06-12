#include "Integer.h"
#include "Number.h"
int main(int argc, char** argv)
{
	/*Integer i1(5);
	Integer i2(10);
	Integer i3(i1 + i2);
	Integer i4(i3);
	std::cout << i4;*/
	Number num1(2);
	Number num2(num1);	/*No copy constructor defined by us for Number. Compiler synthesises
						it and calls Integer's copy constructor*/
	num2 = num1;
	return 0;
}