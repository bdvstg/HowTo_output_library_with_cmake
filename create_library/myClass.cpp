#include "myApi.h"

int this_func_should_not_be_visible(int a, int b)
{
    return a*b+13;
}

MyTestClass::MyTestClass(int num_of_pen, int num_of_apple)
{
    pen = num_of_pen;
    apple = num_of_apple;
}

int MyTestClass::Pineapple()
{
    return this_func_should_not_be_visible(pen, apple);
}

float MyTestClass::ApplePencil()
{
    return mymul(pen, apple) / myAdd(pen, apple);
}
