#include <string>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <sstream>

namespace ns_String {
	int toupper(char ch) {
		return (ch >= 97 && ch <= 122) ? ch -= 32 : ch;
	}

	int tolower(char ch) {
		return (ch >= 65 && ch <= 90) ? ch += 32 : ch;
	}
};
std::string ToUpper(const std::string& str)
{
	std::string result;
	const char* cString = str.c_str();
	int charIndex = 0;
	if (cString != NULL)
	{
		while (cString[charIndex]) {
			result.push_back(ns_String::toupper(cString[charIndex++]));
		}
	}
	return result;
}

std::string ToLower(const std::string& str)
{
	std::string result;
	const char* cString = str.c_str();
	int charIndex = 0;
	if (cString != NULL)
	{
		while (cString[charIndex]) {
			result.push_back(ns_String::tolower(cString[charIndex++]));
		}
	}
	return result;

}

template <typename T>
T Add(T x, T y) {
	return (x + y);
}

void displayIntsInString(const std::string& str) {
	std::stringstream ss;
	ss.str(str);
	int x{ 0 };
	while (ss >> x) {	//fail bit is set if extraction fails
		std::cout << x << std::endl;
	}
}
#if 0
int main(int argc, char **argv)
{
	/*if (argc < 2 || argv[1] == NULL || argv[1][0] == '\0')
	{
		exit(EXIT_FAILURE);
	}*/
	std::string str{"hOla am1g0s!%f"};
	std::cout << "entered string : " << str << std::endl;
	std::string resultstr = ToUpper(str);
	if (resultstr.empty())
	{
		std::cout << "error toupper" << std::endl;
	}
	else
		std::cout << "toupper : " << resultstr << std::endl;
	resultstr.clear();
	resultstr = ToLower(str);
	if (resultstr.empty())
		std::cout << "error tolower" << std::endl;
	else
		std::cout << "tolower: " << resultstr << std::endl;

	int x{ 5 }, y{ 4 };
	std::ostringstream outPutStream;
	outPutStream << x << " + " << y << " = " << Add<int>(x, y) << std::endl;
	std::string resultString = outPutStream.str();
	std::cout << resultString;

	/*C++11 has to_string() for all primitive types
		eg. to_string(int) would also work
	*/

	std::string numString{ "12 34 54 -22" };
	displayIntsInString(numString);

	/*std::stoi also converts string to int*/
	return 0;
}
#endif