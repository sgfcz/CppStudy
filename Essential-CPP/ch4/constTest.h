//按照代码输入无法编译过
#include <iostream>
#include <vector>

using namespace std;

class Triangular
{
public:
    Triangular(int len=1, int bp=1);

    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
    int elem(int pos) const;

    bool next(int &val) const;
    void next_reset() const { _next = _beg_pos -1; }

private:
    int _length, _beg_pos;
    mutable int _next;
    static vector<int> _elems;
};

bool Triangular::next(int &value) const
{
    if(_next < _beg_pos + _length - 1)
    {
        value = _elems[_next++];
        return true;
    }
    return false;
}

int Triangular::elem( int pos ) const
    { return _elems[ pos - 1]; }

Triangular::Triangular(int len, int bp)
{
    _length = len > 0 ? len : 1;
    _beg_pos = bp > 0 ? bp : 1;
    _next = _beg_pos - 1;
}