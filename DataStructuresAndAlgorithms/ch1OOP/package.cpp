#include <iostream>
#include <cstring>

using namespace std;

class C {
public:
    C(string s = " ", int i = 0, double d = 1) {
        dataMember1 = s;
        dataMember2 = i;
        dataMember3 = d;
    }

    void memberFunction1() {
        cout << dataMember1 << ' ' << dataMember2 << ' '
            << dataMember3 << endl;
    }

    void memberFunction2(int i, string s = "unknown") {
        dataMember2 = i;
        cout << i << " received from " << s << endl;
    }
protected:
    string dataMember1;
    int dataMember2; 
    double dataMember3;
};

int main() 
{
    C object1("object1", 100, 200), object2("object"), object3;
    object1.memberFunction1();
    return 0;
}