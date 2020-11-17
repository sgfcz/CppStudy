#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;

int main () {

    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10];
    }
    for (int i = 0; i < 11; i++)
    {
         cout << scores[i] << endl;   
    }
 
    return 0;
}