#pragma once
#include "stdafx.h"
#include <cstddef>

namespace FST
{
    struct RELATION
    {
        char symbol;
        short nnode;
        RELATION(char c = 0x00, short ns = NULL);
    };
    struct NODE
    {
        short n_relation; 
        RELATION* relations; 
        NODE();
        NODE(short n, RELATION rel, ...);
    };
    struct FST  
    {
        std::string string;   
        short position;   
        short nstates;   
        NODE* nodes;    
        short* rstates;    
        FST(std::string s, short ns, NODE n, ...);
    };
    bool execute(FST& fst);
}
