#include <iostream>
#include <string>
#include <vector>

using namespace  std;

class Stack 
{
public:
    bool push(const string&);
    bool pop(string &elem);
    bool peek(string &elem);

    bool empty();
    bool full();

    int size() {return _stack.size();}

private:
    vector<string> _stack;
};

inline bool Stack::empty()
{
    return _stack.empty();
}
bool Stack::pop(string &elem)
{
    if (empty())
        return false;
    
    elem = _stack.back();
    _stack.pop_back();
    return true;
}
inline bool Stack::full()
{ return _stack.size() == _stack.max_size();}
bool Stack::peek(string &elem)
{
    if (empty())
        return false;
    
    elem = _stack.back();
    return true;
}
bool Stack::push(const string &elem)
{
    if(full())
        return false;
    
    _stack.push_back(elem);
    return true;
}