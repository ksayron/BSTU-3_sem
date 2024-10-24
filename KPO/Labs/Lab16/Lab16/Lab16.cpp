using namespace std;
#include "FST.h"


void main()
{
    setlocale(LC_ALL, "russian");
    char stringline1[] = "ISCS;S{R;}";
    char stringline2[] = "IS{R;}";
    char stringline3[] = "ISASS;S{R;}";
    char stringline4[] = "ISCS{R;}";
    char stringline5[] = "ISCSS;SS{R;}";
    char stringline6[] = "ISASCS;SS{R;}";
    char stringline7[] = "IS;S{R;}";
    char stringline8[] = "I;S{R;}";
    char stringline9[] = "ISBS{R;}";
    char stringline10[] = "ISS";
#pragma region MyRegion



    FST::FST fst1(
        stringline1,
        10,
        FST::NODE(1, FST::RELATION('I', 1)),
        FST::NODE(2, FST::RELATION('S', 1), FST::RELATION('S', 2)),
        FST::NODE(5, FST::RELATION('U', 3), FST::RELATION('C', 3), FST::RELATION('A', 3), FST::RELATION(';', 5), FST::RELATION('{', 6)),
        FST::NODE(2, FST::RELATION('S', 3), FST::RELATION('S', 4)),
        FST::NODE(5, FST::RELATION('U', 3), FST::RELATION('C', 3), FST::RELATION('A', 3), FST::RELATION(';', 5), FST::RELATION('{', 6)),
        FST::NODE(2, FST::RELATION('S', 5), FST::RELATION('{', 6)),
        FST::NODE(1, FST::RELATION('R', 7)),
        FST::NODE(1, FST::RELATION(';', 8)),
        FST::NODE(1, FST::RELATION('}', 9)),
        FST::NODE()

    );


#pragma endregion
        execute(fst1, stringline1 ) ? cout << fst1.chain << " +\n" : cout << fst1.chain << " -\n";
        execute(fst1, stringline2 ) ? cout << fst1.chain << " +\n" : cout << fst1.chain << " -\n";
        execute(fst1, stringline3 ) ? cout << fst1.chain << " +\n" : cout << fst1.chain << " -\n";
        execute(fst1, stringline4 ) ? cout << fst1.chain << " +\n" : cout << fst1.chain << " -\n";
        execute(fst1, stringline5 ) ? cout << fst1.chain << " +\n" : cout << fst1.chain <<" -\n";
        execute(fst1, stringline6 ) ? cout << fst1.chain << " +\n" : cout << fst1.chain << " -\n";
        execute(fst1, stringline7 ) ? cout << fst1.chain << " +\n" : cout << fst1.chain << " -\n";
        execute(fst1, stringline8 ) ? cout << fst1.chain << " +\n" : cout << fst1.chain << " -\n";
        execute(fst1, stringline9 ) ? cout << fst1.chain << " +\n" : cout << fst1.chain << " -\n";
        execute(fst1, stringline10) ? cout << fst1.chain << " +\n" : cout << fst1.chain << " -\n";



}