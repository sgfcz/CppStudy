#include <string>

using namespace std;

class Triangular
{
public:
    Triangular::Triangular(int len, int bp)
        : _name("Triangular")
    {
        _length = len > 0 ? len : 1;
        _beg_pos = bp > 0 ? bp : 1;
        _next = _beg_pos - 1;
    }
private:
    int _length,_beg_pos,_next;
    string _name;
};

class Matrix 
{
public:
    Matrix::Matrix(const Matrix &rhs)
        : _row(rhs._row), _col(rhs._col)
    {
        int elem_cnt = _row * _col;
        _pmat = new double[elem_cnt];

        for (int ix = 0; ix < elem_cnt; ++ix)
            _pmat[ix] = rhs._pmat[ix];
    }
    Matrix(int row, int col)
        : _row(row), _col(col)
    {
        _pmat = new double[ row * col];
    }
    ~Matrix()
    {
        delete [] _pmat;
    }
private:
    int _row, _col;
    double* _pmat;
};