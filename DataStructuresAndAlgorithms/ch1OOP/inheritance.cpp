#include <iostream>

using namespace std;

class BaseClass {
public:
    BaseClass() {}
    void f(string s = "unknown") {
        cout << "Function f() in BaseClases called from " << s << endl;
        h();
    }
protected:
    void g(string s = "unknown") {
        cout << "Function g() in BaseClass called from "  << s << endl;
    }
private:
    void h() {
        cout << "Function h() in BaseClass\n";
    }
};

class Derived1Leve11 : public virtual BaseClass {
public:
    void f(string s = "unknown") {
        cout << "Function f() in Derived1Leve11 called from " << s << endl;
        g("Derived1Leve11");
        h("Derived1Leve11");
    }
    void h(string s = "unknown") {
        cout << "Function h() in Derived1Leve11 called from " << s << endl;
    }
};

class Derived2Leve11 : public virtual BaseClass {
public:
    void f(string s = "unknown") {
        cout << "Function f() in Derived2Leve11 called from " << s << endl;
        g("Derived2Leve11");
//        h(); //不可访问
    }
};

class DerivedLeve12 : public Derived1Leve11, public Derived2Leve11 {
public:
    void f(string s = "unknown") {
        cout << "Function f() in DerivedLeve12 called from " << s << endl;
        g("DerivedLeve12");
        Derived1Leve11::h("DerivedLeve12");
        BaseClass::f("DerivedLeve12");
    }
};