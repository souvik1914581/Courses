#include "GlobalDefines.h"
#include <memory>


/*Function object as Deleter*/
struct Free {
	//overload function call operator
	void operator()(int* ptr) {
		if(ptr)
			free(ptr);
		std::cout << "Freed ptr using Function object\n";
	}
};

void mallocFree(int* ptr)
{
	if (ptr)
		free(ptr);
	std::cout << "Freed ptr using Function pointer\n";
}
#if 0
int main(int argc, char** argv)
{
#if 0
	std::unique_ptr<int> intPtr{ (int*)malloc(sizeof(int))};	//By default delete() will be called,need to define our own Deleter
#endif
	void (*fPtr)(int*)= mallocFree;
	//Deleter using Function Object-
	std::unique_ptr<int,Free> intPtr{ (int*)malloc(sizeof(int)), Free{} };

	//Deleter using Function Pointer - 
	std::unique_ptr<int, void (*)(int*)> intPtr2{(int*)malloc(sizeof(int)),mallocFree};

	//For Shared pointers, we do not need to specify the function pointer as template argument
	std::shared_ptr<int> intSharedPtr{ (int*)malloc(sizeof(int)),mallocFree };
	return 0;
}
#endif