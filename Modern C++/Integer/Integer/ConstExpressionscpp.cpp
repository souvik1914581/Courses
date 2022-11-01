#include <iostream>
template<typename T>
constexpr T Max(T x, T y) {	/*constexpr functions can have only one line - a return statement*/
	return x > y ? x : y;
}

#if 0
int main() {
	constexpr int a = Max(2, 3);	//behaves like a constexpr function
	int x = 5;
	//constexpr int b = Max(x, 4);	//This does not work as x is not a compile time expression
	int b = Max(x, 3);	//Here, Max() behaves like a normal function
	return 0;
}
#endif