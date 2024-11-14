#include "stdafx.h"
#include "FST.h"
#include <string.h>
#include <stdarg.h>

namespace FST
{
    RELATION::RELATION(char c, short ns)
    {
        symbol = c;
        nnode = ns;
    }

    NODE::NODE()
    {
        n_relation = 0;
        relations = NULL;
    };

    NODE::NODE(short n, RELATION rel, ...)
    {
        n_relation = n;
        relations = new RELATION[n];

        va_list factor;
        va_start(factor, rel);
        relations[0] = rel;

        for (int i = 1; i < n; i++) {
            relations[i] = va_arg(factor, RELATION);
        }

        va_end(factor);
    };

    FST::FST(std::string s, short ns, NODE n, ...)
    {
        string = s;
        nstates = ns;
        nodes = new NODE[ns];
        va_list factor;
        va_start(factor, n);
        nodes[0] = n;

        for (int i = 1; i < ns; i++) {
            nodes[i] = va_arg(factor, NODE);
        }

        va_end(factor);

        rstates = new short[nstates];

        memset(rstates, 0xff, sizeof(short) * nstates);
        rstates[0] = 0;
        position = -1;
    }

    bool step(FST& fst, short*& rstates) {
        bool rc = false;
        auto temp = rstates;
        rstates = fst.rstates;
        fst.rstates = temp;
        for (short i = 0; i < fst.nstates; i++)
        {
            if (rstates[i] != -1)
                for (short j = 0; j < fst.nodes[i].n_relation; j++)
                    if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
                    {
                        fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
                        rc = true;
                    }
        };
        return rc;
    }

    bool execute(FST& fst)
    {

        short* rstates = new short[fst.nstates];
        memset(rstates, 0xff, sizeof(short) * fst.nstates);
        short lstring = fst.string.length();
        bool rc = true;
        for (short i = 0; i < lstring && rc; i++)
        {
            fst.position++;
            rc = step(fst, rstates);
        };
        fst.string.clear();
        return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
    }

}
