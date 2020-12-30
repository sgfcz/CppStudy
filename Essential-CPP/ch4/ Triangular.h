#include <iostream>
#include <vector>

using namespace std;

class Triangular
{
public:
    int length() const{ return _length; }

private:
    int _length, _beg_pos, _next;
    static vector<int> _elems;
}