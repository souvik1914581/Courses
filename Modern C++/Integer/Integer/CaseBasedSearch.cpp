#include <string>
#include <iostream>
#include <vector>

enum class SEARCH_TYPE {
	SEARCH_CASE_SENSITIVE,
	SEARCH_CASE_INSENSITIVE,
	SEARCH_CASE_INVALID
};

namespace ns_caseBasedSearch 
{
	bool isSameChar(char x, char y)
	{
		return (x == y) || (x == toupper(y)) || (x == tolower(y));
	}

	size_t find(const std::string& sourceString, const std::string& searchString,SEARCH_TYPE searchType = SEARCH_TYPE::SEARCH_CASE_SENSITIVE, size_t offset = 0)
	{
		if (sourceString.empty() || searchString.empty())
			return std::string::npos;
		size_t matchPos = std::string::npos;
		switch (searchType)
		{
			case SEARCH_TYPE::SEARCH_CASE_INSENSITIVE:
			{
				//first try searching without modifying case
				size_t result = sourceString.find(searchString, offset);
				if (result != std::string::npos)
					return result;
				//now try switching case and search
				const char* rawSourceString = sourceString.c_str();
				const char* rawSearchString = searchString.c_str();
				if (rawSourceString == nullptr || (offset > sourceString.length() - 1) || rawSearchString == nullptr)
					return std::string::npos;

				//iterate through the raw strings
				unsigned sourceCharIndex = offset;
				unsigned searchCharIndex = 0;
				unsigned matchCount = 0;
				while (rawSourceString[sourceCharIndex] != '\0')
				{
					if (isSameChar(rawSourceString[sourceCharIndex], rawSearchString[searchCharIndex]))
					{
						//increment the match count
						++matchCount;
						if (matchCount == 1)
							matchPos = sourceCharIndex;
						else if (matchCount == searchString.length())
						{
							//we have found a match
							break;
						}
						searchCharIndex = (searchCharIndex >= searchString.length()) ? 0 : searchCharIndex + 1;
					}
					else
					{
						//reset the search
						matchPos = std::string::npos;
						searchCharIndex = 0;
						matchCount = 0;
					}
					++sourceCharIndex;
				}
				break;
			}
		default:
			return sourceString.find(searchString, offset);
		}
		return matchPos;
	}

	/******
	*	@name FindAll
	*	@brief	find indices of all substrings in a string
	* 
	*/
	std::vector<int> FindAll(const std::string& sourceString, const std::string& searchString, SEARCH_TYPE searchType = SEARCH_TYPE::SEARCH_CASE_SENSITIVE, size_t offset = 0)
	{
		std::vector<int> results;
		size_t searchIndex = 0;
		size_t result = 0;
		do {
			result = find(sourceString, searchString, searchType, searchIndex);
			if (result != std::string::npos)
			{
				/*Successful hit*/
				results.push_back(result);
				searchIndex += result + 1;
			}
		
		} while (result != std::string::npos);
		return results;
	}
};

#if 0
int main()
{
	const std::string sourceString = "Jaja! #Hola DEA!! a dea ";
	const std::string searchString = "a dea";
	/*size_t result = ns_caseBasedSearch::find(sourceString, searchString,SEARCH_TYPE::SEARCH_CASE_INSENSITIVE,3);
	if (result != std::string::npos)
		std::cout << "\"" << searchString << "\" found in position "<< result << " of \"" << sourceString << "\"" << std::endl;
	else
		std::cout <<"\"" <<searchString << "\" not found in \"" << sourceString <<"\""<< std::endl;*/
	const std::vector<int> results = ns_caseBasedSearch::FindAll(sourceString, searchString, SEARCH_TYPE::SEARCH_CASE_INSENSITIVE);
	if (results.empty())
		std::cout <<"\""<< searchString <<"\""<< " not found in " << "\""<<sourceString <<"\""<< std::endl;
	else
	{
		std::cout << "\"" << searchString << "\"" << " found in " << "\"" << sourceString << "\"" << " at: ";
		for (const auto& pos : results)
			std::cout << pos << ",";
		std::cout << std::endl;
	}
	return 0;
}
#endif