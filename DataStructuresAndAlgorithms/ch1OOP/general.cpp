template<class genType, int size = 50>
class genclass {
    genType storage[size];
};

int main() 
{
    genclass<int> intobjec1;
    genclass<int, 100> intobjec2;
    genclass<float, 123> floatobject1;

    return 0;
}