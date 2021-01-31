#include "personal.h"

Personal::Personal() : nameLen(10), cityLen(10) {
    name = new string[nameLen+1];
    city = new string[cityLen+1];
}

Personal::Personal(string *ssn, string *n, string *c, int y, long s) :
    nameLen(10), cityLen(10) {
    name = new string[nameLen+1];
    city = new string[cityLen+1];
    SSN = new string[10];
    SSN = ssn;
    name = n;
    city = c;
    year = y;
    salary = s;
}

