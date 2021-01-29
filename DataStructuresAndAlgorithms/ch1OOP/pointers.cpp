#include <iostream>
#include <cstring>

using namespace std;

//复制构造函数
struct Node {
    char *name;
    int age;
    Node(char *n = 0, int a = 0) {
        name = strdup(n);
        age = a;
    }
    Node(const Node& n) { 
        name = strdup(n.name);
        age = n.age;
    }
};

int main() 
{
    int i = 15, j, *p, *q;

    p = &i;

    cout << "p = " <<  p << endl; //地址
    *p = *p - 1;
    cout << "*p = " << *p << endl; //数
    cout << "i = " << i << endl;

    return 0;
}