#include <deque>
#include <iostream>

using namespace std;

int main()
{
    deque<int> a_line;
    int ival;

    while(cin >> ival)
    {
        a_line.push_back(ival);

        int curr_value = a_line.front();
        cout << a_line[0];
        a_line.pop_front();
    }

    return 0;
}