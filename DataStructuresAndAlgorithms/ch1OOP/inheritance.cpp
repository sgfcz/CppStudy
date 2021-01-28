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

int main() 
{
    BaseClass bc;
    Derived1Leve11  d111;
    Derived2Leve11 d211;
    DerivedLeve12 d12;
    bc.f("main(1)");

    //bc.g(); //不可访问
    //bc.h(); //不可访问
    d111.f("main(2)");
    //d111.g();//不可访问你
    d111.h("main(3)");
    d211.f("main(4)");
    //d211.g(); //不可访问
    //d211.h();//不可访问
    d12.f("main(5)");
    //d12.g();//不可访问
    d12.h();
    return 0;
}