#include <iostream>
#include <vector>

using namespace std;

class Triangular
{
public:
    int length() const { return _length; }
    int beg_pos() const { return _beg_pos; }
    int elem(int pos) const;

    bool next(int &val);
    void next_reset() { _next = _beg_pos -1; }

private:
    int _length, _beg_pos, _next;
    static vector<int> _elems;
};