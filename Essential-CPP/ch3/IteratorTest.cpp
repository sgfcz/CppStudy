#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// template<typename elemType>
// void display(const vector<elemType> &vec, ostream &os)
// {
//     vector<elemType>::const_iterator iter = vec.begin();
//     vector<elemType>::const_iterator end_it = vec.end();

//     for (; iter != end_it; ++iter)
//         os << *iter << ' ';
//     os << endl;
// }

template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last, const elemType &value)
{
    for (; first != last; ++first)
        if (value == *first)
            return first;
    
    return last;
}

int main() 
{
    const int asize = 8;
    vector<int> iv = {1,1,2,3,5,8,13,21};

    vector<int>::iterator piv;
    piv = find(iv.begin(), iv.end(), 2);
    if (piv != iv.end())
        cout << "find over!";

    return 0;
}