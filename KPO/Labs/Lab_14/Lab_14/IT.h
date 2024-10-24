#pragma once
#include "stdafx.h"
#define ID_MAXSIZE 5
#define IT_MAXSIZE 4096
#define INT_DEFAULT 0x00000000
#define STR_DEFAULT 0x00
#define NULL_INDEX 0xffffffff
#define STR_MAXSIZE 255

namespace IT {
	enum DATATYPES { INT = 1, STR = 2 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 3 };

	struct Entry {
		int first_line_ID;//link to the lexem table
		char id[ID_MAXSIZE];
		DATATYPES IDDataType;
		IDTYPE IDType;
		union {
			int vint;
			struct {
				char len;
				char str[STR_MAXSIZE - 1];
			}vstr[STR_MAXSIZE];
		}value;
	};

	struct IDTable {
		int maxsize;
		int size;
		Entry* table;
	};
	IDTable Create(int size);
	void AddToIDTable(IDTable& idtable, Entry entry);
	Entry GetEntry(IDTable& idtable, int str_num);
	int IsId(IDTable& idtable, char id[ID_MAXSIZE]);
	void DeleteIdTable(IDTable& idtable);
	void Write(IDTable idtable);
}