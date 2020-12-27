#include <vector>
#include <iostream>

using namespace std;

template<typename elemType>
elemType* find(elemType *first, elemType *last, elemType &value)
{
    if (!first || !last)
        return 0;
    for (; first != last; ++first)
        if(*first == value)
            return first;
    return 0;
}

int main()
{
    int ia[8] = {1,1,2,3,5,8,13,21};
    double da[6] = {1.5,2.0,2.5,3.0,3.5,4.0};
    string sa[4] = {"pooh", "piglet", "eeyore", "tigger"};

    int *pi = find(ia,ia+8,ia[3]);
    double *pd = find(da,da+6,da[3]);
    string *ps = find(sa,sa+4,sa[3]);

    cout << *pi << " " << *pd << " "<< *ps << " " << endl;
}