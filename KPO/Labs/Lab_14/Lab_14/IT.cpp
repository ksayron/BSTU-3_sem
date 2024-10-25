#include "stdafx.h"


namespace IT {
	IDTable Create(int size) {
		IDTable newIDTable;
		newIDTable.size = 0;
		newIDTable.table = new Entry[size];
		newIDTable.maxsize = ID_MAXSIZE;
		return newIDTable;
	}

	void AddToIDTable(IDTable& idtable, Entry entry) {
		if (idtable.size >= ID_MAXSIZE) {
			throw ERROR_THROW(66);
		}
		idtable.table[idtable.size] = entry;
		idtable.size++;
	}

	Entry GetEntry(IDTable& idtable, int str_num) {
		if (str_num >= ID_MAXSIZE || str_num < 0) {
			throw ERROR_THROW(67);
		}
		Entry IDTableElem = idtable.table[str_num];
		return IDTableElem;
	}

	int IsId(IDTable& idtable, char id[ID_MAXSIZE]) {
		for (int i = 0; i < idtable.size; i++) {
			if (idtable.table[i].id == id) {
				return i;
			}
		}
		return NULL_INDEX;
	}

	void DeleteIdTable(IDTable& idtable) {
		idtable.table = nullptr;
		delete[] idtable.table;
		idtable.size = 0;
	}
	void Build(IDTable idtable) {
		std::ofstream IDfile = new ofstream
	}

};