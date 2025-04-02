#include "add.hh"
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

exampleClass::exampleClass(int value)
    : data(value) {}

int exampleClass::getData() const
{
    return data;
}

void exampleClass::setData(int value)
{
    data = value;
}