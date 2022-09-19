#include <string>
#include <cstring>
#include <iostream>
#include <ctype.h>

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

int main(int argc, char **argv)
{
	/*if (argc < 2 || argv[1] == NULL || argv[1][0] == '\0')
	{
		exit(EXIT_FAILURE);
	}*/
	std::string str{"hola am1g0s!%f"};
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
	return 0;
}