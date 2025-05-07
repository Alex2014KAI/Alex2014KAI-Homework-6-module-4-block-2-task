#include <iostream>
#include "Table.h"


int main()
{
    Table<int> table(2, 3);
 
     table[0][0] = 4;
     std::cout << table[0][0];

    std::cout << std::endl;


    SizeTable sizeTable = table.Size();
    std::cout << "rowCount: " << sizeTable.m_rowCount << " ColCount: " << sizeTable.m_colCount;


}