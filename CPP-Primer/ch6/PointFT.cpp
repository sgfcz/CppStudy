#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reset(int *ip) {
    *ip = 0;
}

int main() {
    int i = 42;
    reset(&i);
    cout << "i = " << i << endl;

    return 0;
}