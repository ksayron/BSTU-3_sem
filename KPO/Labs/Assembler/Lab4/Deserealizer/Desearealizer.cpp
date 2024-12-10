#include "Desearealizer.h"
#include "stdafx.h"

void Desearealizer::Deserialize(char* valChar, bool* valBool)
{
	ifstream file(FILENAME, ios::binary);
	short getType = 0;
	if (file.is_open())
	{
		
		file.read(reinterpret_cast<char*>(&getType), sizeof(char));
		if (getType == TYPECHAR) {
			file.read(reinterpret_cast<char*>(valChar), sizeof(char)*10);
		}
		else if (getType == TYPEBOOL) {
			file.read(reinterpret_cast<char*>(valBool), sizeof(bool));
		}
		file.read(reinterpret_cast<char*>(&getType), sizeof(char));
		if (getType == TYPECHAR) {
			file.read(reinterpret_cast<char*>(valChar), sizeof(char)*10);
		}
		else if (getType == TYPEBOOL) {
			file.read(reinterpret_cast<char*>(valBool), sizeof(bool));
		}
		file.close();
	}
	else
	{
		cout << "File not open" << endl;
	}
}