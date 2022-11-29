#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <random>
#define PRINT_FUNC_NAME() { \
	do{ std::cout<<__FUNCSIG__<<std::endl; } while(0); }

class Test {
public:
	Test() {
		PRINT_FUNC_NAME();
	}

	~Test() {
		PRINT_FUNC_NAME();
	}
};
void ProcessData(int size) {
	if (size < 10)
		throw std::runtime_error("Insufficient data\n");
	std::unique_ptr<Test> tPtr(new Test);
	std::vector<int> arr;
	arr.reserve(size);
	for (auto& i : arr) {
		i = 0;
	}
	unsigned errors{};
	std::default_random_engine randEng;	/*Generate random number*/
	std::bernoulli_distribution bDist;
	for (unsigned i = 0; i < size; ++i) {
		try {
			std::cout << "Processing record: " << i << std::endl;
			if (!bDist(randEng)) {
				throw std::runtime_error("Could not process record");
			}
		}
		catch (std::exception& e) {
			++errors;
			std::cout << e.what();
			if (errors > 5) {
				std::runtime_error abandonException("Too many errors.Processing abandoned");
				e = abandonException;	//Modifying the throw object
				throw;					//throw to outer catch block in main()
			}
		}
	}
	/*Test* tPtr = new Test();
	if (size < 10)
		throw std::out_of_range("Insufficient data size\n");
	int* ptr = (int*)malloc(size * sizeof(int));
	if (ptr == nullptr)
		throw std::runtime_error("Failed to allocate memory\n");
	for (int i = 0; i < size; ++i) {
		ptr[i] = i;
	}
	free(ptr);
	delete tPtr;	*///this does not get invoked if above exceptions are thrown
}

//int main() {
//	try {
//		//ProcessData(std::numeric_limits<int>::max());
//		ProcessData(30);
//	}
//	catch (std::exception& e) {									/*Base class of all exceptions*/
//		std::cout << "Caught Exception: " << e.what() << std::endl;
//	}
//	catch (...) {					/*This can catch any exception, but cannot specify the type of exception. Not recommended*/
//		std::cout << "Caught unknown exception" << std::endl;
//	}
//	return 0;
//}