#include "counter.h"

int main() 
{
    Counter a, b;
    QObject::connect(&a, &Counter::valuChanged, &b, &Counter::setValue);
    
    a.setValue(12);
    b.setValue(48);
}