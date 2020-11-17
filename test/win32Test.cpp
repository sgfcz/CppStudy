#include <iostream>
#include <Windows.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
#pragma comment(lib, "User32.lib")
int main () {
    cout << "Hello World!" << endl;

    MessageBox(NULL, TEXT("Hello World!"), TEXT("弹窗"), MB_OK);
    return 0;
}