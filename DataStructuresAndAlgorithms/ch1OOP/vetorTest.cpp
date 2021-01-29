#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<class T>
void printVector (string s, const vector<T>& v) {
    cout << s << "= (";
    if (v.size() == 0) {
        cout << ")\n";
        return;
    }
    typename vector<T>::const_irerator i = v.begin();
    for (; i != v.end() - 1; i++)\
        cout << *i << " ";
    cout << *i << ")\n";
}

bool f1(int n) {
    return n < 4;
}

int main() 
{
    int a[] = {1,2,3,4,5};
    vector<int> v1;
    printVector("v1", v1);

    return 0;
}