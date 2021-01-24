#include <iostream>

using namespace std;

class C {
public:
    C(char *s = "", int i = 0, double d = 1) {
        strcpy(dataMember1, s);
        dataMember2 = i;
        dataMember3 = d;
    }

    void memberFunction1() {
        cout << dataMeber1 << ' ' << dataMember2 << ' '
            << dataMember3 << endl;
    }

    void memberFunction2(int i, char *s = "unknown") {
        dataMeber2 = i;
        cout << i << " received from " << s << endl;
    }
protected:
    char dataMeber1[20];
    int dataMeber2; 
    double dataMember3;
}