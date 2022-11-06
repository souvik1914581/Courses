#include <iostream>
#include <array>
#include <initializer_list>
#include <assert.h>
template <typename T>
class Bag {
	std::array<T, 10> m_bag;
	unsigned m_tail = 0;
public:
	Bag() {
		m_tail = 0;
		m_bag.fill(0);
	}
	Bag(std::initializer_list<T> list):Bag() {
		assert(list.size() <= 10);
		for (const auto value : list)
		{
			m_bag[m_tail++] = value;
		}
	}
	void Add(const T x) {
		if (m_tail < 10)
		{
			m_bag[m_tail] = x;
			++m_tail;
		}
	}

	void Display() const {
		std::cout << "[";
		for (const auto& val : m_bag)
			std::cout << val << ",";
		std::cout << "]" << std::endl;
	}

};

//int main() {
//	Bag<unsigned> bag1{ 1,2,3,4,5,6,7,8,9,10 };	//Bag object initialized with initializer list
//	bag1.Display();
//	return 0;
//}