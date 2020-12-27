#include "StackClass.h"

void fill_stack(Stack &stack, istream &is = cin)
{
    string str;
    while (is >> str && !stack.full())
        stack.push(str);
    cout << "Read in " << stack.size() << " elements\n";
}