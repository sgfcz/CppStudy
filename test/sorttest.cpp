#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string list = "asdgABhxnDmbAHVCB";
    vector<double> sortlist;
    
    
    for (char c : list) {
        if ((c - 31) > 65)
            sortlist.push_back(c - 31.1);
        else
            sortlist.push_back(c);
    }

    sort(sortlist.begin(), sortlist.end());

    for (auto d : sortlist)      
        if ((int(d * 10)) % 10 != 0)
            cout << char(d + 32);
        else 
            cout << char(d);
    
    return 0;
}