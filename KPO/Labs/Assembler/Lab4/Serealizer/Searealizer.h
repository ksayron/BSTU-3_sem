#pragma once
#define TYPECHAR 1
#define TYPEBOOL 2
class Serealizer
{
public:
	void Serialize(char* valChar, bool valBool);

private:
	const char* FILENAME = "bin.bin";
};