#ifndef PERSONAL
#define PERSONAL

#include <fstream>
#include <string>
using namespace std;

class Personal {
public:
    Personal();
    Personal(string* ,string* ,string* ,int,long);
    void writeToFile(fstream&) const;
    void readFromFile(fstream&);
    void readkey();
protected:
    const int nameLen, cityLen;
    string *SSN, *name, *city;
    int year;
    long salary;
    ostream& writeLegibly(ostream&);
    friend ostream& operator<<(ostream& out, Personal& pr) {
        return pr.writeLegibly(out);
    }
    istream& readFromConsole(istream&);
    friend istream& operator>>(istream& in, Personal& pr) {
        return pr.readFromConsole(in);
    }
};

#endif