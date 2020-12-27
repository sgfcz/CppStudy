/*
    练习1-7
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    vector<string> sentences;
    string sentence;
    ifstream infile("string.txt");
    if (! infile)
    {
        cerr << "dont open file!";
    }
    else
        while (infile >> sentence)
            sentences.push_back(sentence);
    sort(sentences.begin(), sentences.end());
    for (auto s : sentences)
    {
        cout << s << endl;
    }
    
    return 0;
}