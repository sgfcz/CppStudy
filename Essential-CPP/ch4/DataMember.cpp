#include "constTest.h"
#include <iostream>

using namespace std;

int sum(const Triangular &trian)
{
    if(!trian.length())
        return 0;
    int val, sum=0;
    trian.next_reset();
    while (trian.next(val))
        sum+=val;
    return sum;
}

int main()
{
    Triangular tri(4);

    cout << " -- sum of elements: "
        << sum(tri) << endl;
    
    return 0;
}