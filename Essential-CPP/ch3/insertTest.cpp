#include <list>
#include <iostream>

using namespace std;

int main() 
{
    //插入形式
    list<int> ilist(5,1);

    list<int>::iterator it = ilist.begin();
    int ival;
    cin >> ival;
    while (it != ilist.end())
    {
        if (*it >= ival)
        {
            ilist.insert(it, ival);
            break;
        }
        ++it;
    }

    if (it == ilist.end())
        ilist.push_back(ival);
    it = ilist.begin();
    while ( it != ilist.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;


    return 0;
}