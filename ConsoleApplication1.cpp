#include <iostream>

class SizeTable {
public:
    int m_rowCount;
    int m_colCount;
    SizeTable(int rowCount, int colCount) : m_rowCount(rowCount), m_colCount(colCount) {};
};

template<typename T>
class MatrixView // 2D interface to a buffer
{
protected:
    T* const m_Buff;
    int m_RowCount;
    int m_ColCount;
public:

    MatrixView(T* buff, int rowCount, int colCount)
        : m_Buff(buff)
        , m_RowCount(rowCount)
        , m_ColCount(colCount)
    {}
    T* operator[](int rowInd) const                         // Question 1
    {
        return m_Buff + rowInd * m_ColCount;
    }
};

template<typename T>
class DynBuffer // buffer owner
{
    T* const m_Buff;
protected:
    T* Buff() const { return m_Buff; };
    DynBuffer(int length) : m_Buff(new T[length]{}) {};
    ~DynBuffer() { delete[] m_Buff; }
    DynBuffer(const DynBuffer&) = delete;                   // Question 2
    DynBuffer& operator=(const DynBuffer&) = delete;        // Question 3
};

template<typename T>
class MatrixSimple: public DynBuffer<T>, public MatrixView<T>
{
    using Buff = DynBuffer<T>;
    using View = MatrixView<T>;
public:
    MatrixSimple(int rowCount, int colCount): 
        Buff(rowCount * colCount),
        View(Buff::Buff(), rowCount, colCount)
    {};

    SizeTable Size() const {
        SizeTable sizeTable(View::m_RowCount, View::m_ColCount);   // Question 4
        // SizeTable sizeTable(m_RowCount, m_ColCount);               // Question 4 ERROR
        return sizeTable;
    }
};


int main()
{
    MatrixSimple<int> table(2, 3);
    table[0][0] = 4;
    std::cout << table[0][0];

    std::cout << std::endl;
    SizeTable sizeTable = table.Size();
    std::cout << "rowCount: " << sizeTable.m_rowCount << " ColCount: " << sizeTable.m_colCount;


}