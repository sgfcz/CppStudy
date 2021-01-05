#include "counter.h"

int main(int argc, char *argv[]) 
{
    Counter a, b;
    QObject::connect(&a, &Counter::valuChanged, &b, &Counter::setValue);
    
    a.setValue(12);
    b.setValue(48);
}