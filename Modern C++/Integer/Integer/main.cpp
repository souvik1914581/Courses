#include "Integer.h"
#include "Number.h"
//int main(int argc, char** argv)
//{
//	
//
//	Number num1(2);	//Invokes value parameterised constructor
//	Number num2(num1);	/*No copy constructor defined by us for Number. Compiler synthesises
//						it and calls Integer's copy constructor*/
//	num2 = num1;	//Invokes Copy Assignment operator
//
//	Number n3{ CreateNumber(3) };	//Invokes Move Constructor
//	Number n4 = CreateNumber(3);	//returns R-val refererence. Invokes Move assignment operator
//	return 0;
//}


int main(int argc, char** argv)
{
	Integer i1(5);
	Integer i2(10);
	Integer i3(i1 + i2);
	Integer i4(i3);
	std::cout << i4;
	++i4;
	std::cout << i4++ << std::endl;
	std::cout << i4;
	return 0;
}