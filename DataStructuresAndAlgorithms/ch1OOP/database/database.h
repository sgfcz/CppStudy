#ifndef DATABASE
#define DATABASE

#include <fstream>
#include <iostream>
using namespace std;

template<class T>
class Database {
public:
    Database();
    void run();
protected:
    fstream database;
    char fName[20];
    ostream& print(ostream&);
    void add(T&);
    bool find(const T&);
    void modify(const T&);
    friend ostream& operator<<(ostream out, Database& db) {
        return db.print(out);
    }
};

#endif