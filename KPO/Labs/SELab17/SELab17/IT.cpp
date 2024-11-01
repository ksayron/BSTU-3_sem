#include "stdafx.h"
#include "IT.h"

namespace IT
{
    IdTable Create(int size)
    {
        if (size > 0)
        {
            IdTable idtable;
            idtable.maxsize = size;
            idtable.size = 0;
            idtable.table = new Entry[size];
            return idtable;
        }
        ERROR_THROW(116);
    }

    void Add(IdTable& idtable, Entry entry)
    {
        if (entry.id.size() > TI_MAXSIZE)
        {
            ERROR_THROW(119);
        }
        if (idtable.size < idtable.maxsize) {
            idtable.table[idtable.size] = entry;
            idtable.size++;
        }
        else {
            ERROR_THROW(117);
        }
    }

    Entry GetEntry(IdTable& idtable, int n)
    {
        if (n >= 0 && n < idtable.size) {
            return idtable.table[n];
        }
        else {
            cout << "Ошибка: неверный индекс в таблице идентификаторов" << endl;
            Entry invalid;
            invalid.id = "";
            invalid.iddatatype = static_cast<IDDATATYPE>(0);
            invalid.idtype = static_cast<IDTYPE>(0);
            invalid.idxfirstLE = TI_NULLIDX;
            return invalid;
        }
    }

    int IsId(IdTable& idtable, std::string id)
    {
        for (int i = 0; i < idtable.size; i++)
        {
            if (idtable.table[i].id == id) 
                return i;
        }
        return TI_NULLIDX;
    }

    void Delete(IdTable& idtable)
    {
        delete[] idtable.table;
        idtable.size = 0;
        idtable.maxsize = 0;
    }
}
