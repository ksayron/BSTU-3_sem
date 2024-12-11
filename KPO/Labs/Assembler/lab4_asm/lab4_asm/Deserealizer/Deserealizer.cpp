#include "Deserealizer.h"
#include "stdafx.h"

enum types {
	WCHAR_T = 1,
	CHAR = 2
};

void Desearealizer::Deserialize(wchar_t* str, char* character)
{
	ifstream file(FILENAME, ios::binary);
	if (file.is_open())
	{
		while (file) {
			uint8_t type;
			if (!file.read(reinterpret_cast<char*>(&type), sizeof(type))) {
				break;
			}

			if (type == types::CHAR) {
				char chr;
				file.read(reinterpret_cast<char*>(&chr), sizeof(char));
				*character = chr;
			}
			else if (type == types::WCHAR_T) {
				wchar_t charr='/0';
				file.read(reinterpret_cast<char*>(&charr), sizeof(wchar_t));
				*str = charr;
			}
			else {
				throw "Unknown type encountered in file";
			}
		}
	}
	else
	{
		cout << "DesFile not open" << endl;
	}
}