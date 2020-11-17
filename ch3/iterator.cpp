#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {

    string s("some string");
    if (s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl;
    
    return 0;
}