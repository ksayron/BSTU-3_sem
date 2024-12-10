#pragma once
#define TYPECHAR 1
#define TYPEBOOL 2
class Desearealizer
{
public:
	void Deserialize(char* valChar, bool* valBool);

private:
	const char* FILENAME = "../Serealizer/bin.bin";
};