#include "Integer.h"
#include "Number.h"
#include "SmartPointer.h"
#include <memory>
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


//int main(int argc, char** argv)
//{
//	Integer i1(5);
//	Integer i2(10);
//	Integer i3(i1 + i2);
//	Integer i4(i3);
//	/*std::cout << i4;
//	++i4;
//	std::cout << i4++ << std::endl;
//	std::cout << i4;
//	std::cin >> i4;
//	i4();
//	std::cout << *i4 << std::endl;*/
//	
//	return 0;
//}

//auto foo()
//{
//	return SmartPointer<int>(new int(10));
//}
//
//int main(int argc, char** argv)
//{
//	/*SmartPointer<int> intPtr = nullptr;
//	intPtr = new int(6);
//	SmartPointer<int> intPtr2 = nullptr;*/
//	//std::cout << *intPtr << std::endl;
//	SmartPointer<int> intPtr3 = foo();
//	SmartPointer<int> intPtr4 = std::move(intPtr3);	//invokes move constructor
//	SmartPointer<int> intPtr5 = nullptr;
//	intPtr5 = std::move(intPtr4);	//invokes move assignment operator
//
//	
//	return 0;
//}
//

//move constructor
//int main(int argc, char** argv)
//{
//	std::unique_ptr<Integer> IntPtr(new Integer(56));
//	auto IntPtr2(std::move(IntPtr));		//invoke move constructor
//	std::cout << *IntPtr2 << std::endl;
//	return 0;
//}

#if 0
//Type conversions
int main(int argc, char** argv)
{
	/*Primitive --> User defined type */
	Integer i1(6);	//Initialization done by Parameterised constructor
	
	Integer i2;
	i2 = 6;		//Assignment done by assignment operator

	/*User defined type --> Primitive type*/
	int iPrimitive = i2;	//Handled by operator <type>()
	
	return 0;
}
#endif