#include "StackClass.h"

using namespace std;

void fill_stack(Stack &stack, istream &is = cin)
{
    string str;
    while (is >> str && !stack.full()) //ctrl+d 为结束
        stack.push(str);

    cout << "Read in " << stack.size() << " elements\n";
    cout << "Stack is Empty?" << stack.empty();
}

int main() 
{
    Stack stacktest;
    fill_stack(stacktest,cin);
    return 0;
}