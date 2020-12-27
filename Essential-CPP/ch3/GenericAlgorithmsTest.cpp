#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

extern bool grow_vec(vector<int>&, int )
{

}

bool is_elem(vector<int> &vec, int elem)
{
    int max_value = vec.empty() ? 0 : vec[vec.size()-1];
    if (max_value < elem)
        return grow_vec(vec,elem);

    if (max_value == elem)
        return true;
    
    return binary_search(vec.begin(), vec.end(), elem);
    
}

int main() 
{
    vector<int> ivec = {1,1,2,3,5,8,13,21,34,55};

    cout << is_elem(ivec,79);

    return 0;
}