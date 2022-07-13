#include"Integer.h"
#include "GlobalDefines.h"
#include <memory>

void Display(const Integer* const ptr)
{
	if (!ptr)
		return;
	std::cout << *ptr << std::endl;
}

Integer* GetPointer(int value)
{
	Integer* ptr = new Integer(value);
	return ptr;
}

void Store(std::unique_ptr<Integer> ptr)
{
	std::cout << "Storing " << ptr->GetValue() << std::endl;
}

int main(int argc, char** argv)
{
	std::unique_ptr<Integer> intPtr(GetPointer(5));
	if (intPtr == nullptr)
	{
		intPtr.reset(new Integer(5));	//reset() deletes existing memory pointed by intPtr and then changes value
	}
	intPtr->SetValue(10);	//Can call methods of underlying pointer
	Display(intPtr.get());	//.get() gets the underlying raw pointer
	*intPtr = __LINE__;
	Display(intPtr.get());
	Store(std::move(intPtr));	//give up ownership of underlying pointer
	//Display(intPtr.get());	//should not attempt to use after doing std::move()!!!
	return 0;
}