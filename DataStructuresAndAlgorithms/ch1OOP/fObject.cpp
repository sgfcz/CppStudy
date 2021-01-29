#include <iostream>

using namespace std;

class Classf {
public:
    Classf() {
    }

    double operator() (double x) { //double operator(double x)
        return 2*x;
    }
};

double sum2 (Classf f, int n, int m) {
    double result = 0;
    for (int i = n; i <= m; i++)
        result += f(i); //f.operator(i)
    return result;
}

int main() 
{
    Classf cf;
    cout << sum2(cf, 1, 2) << endl; 
}