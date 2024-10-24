

#include <iostream>
#include <string>
#include <map>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string input="кучерук николай петрович";
	std::map<char, int> freq,huff_dictionary;
	//std::cin >> input;
	for (char c : input) {
		freq[c] += 1;
	}
	for (const auto& el : freq)
		if(el.first!=' ')std::cout << el.first << "\t" << el.second << std::endl;
		else std::cout << "' '" << "\t" << el.second << std::endl;
	char first_rare=INT32_MAX, second_rare=INT32_MAX;
	while(true){
		for (const auto& el : freq)
		{
			if (el.second<INT32_MAX)
		}
	}
}

