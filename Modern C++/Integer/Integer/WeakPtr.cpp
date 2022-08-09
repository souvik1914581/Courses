#include "GlobalDefines.h"

template <typename T>
class Printer {
	std::weak_ptr<T> m_ptr;
public:
	void SetValue(const std::weak_ptr<T>& ptr) {
		m_ptr = ptr;
	}

	void Display() const {
		if (m_ptr.expired())
		{
			std::cout << "Resource Unavailable" << std::endl;
			return;
		}
		auto sp = m_ptr.lock();	//lock() returns a shared_ptr
		std::cout <<"Value = "<< *sp << std::endl;
		std::cout << sp.use_count() << std::endl;
	}
};

#if 0
int main(int argc, char** argv)
{
	int val{ 0 };
	Printer<int> p1;
	std::cout << "Enter integer:";
	std::cin >> val;
	std::shared_ptr<int> intPtr(new int(val));
	p1.SetValue(intPtr);
	if (*intPtr > 10) {
		intPtr = nullptr;
	}
	p1.Display();
	return 0;
}
#endif