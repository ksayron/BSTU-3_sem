#pragma once
#include <string>
class Desearealizer
{
public:
	void Deserialize(wchar_t* str, char* number);

private:
	const char* FILENAME = "../Serealizer/bin.bin";
};    
