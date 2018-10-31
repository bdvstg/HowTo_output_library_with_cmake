#include <iostream>

#include "myApi.h"

int main(void)
{
    // 這行程式碼會讓編譯不過，因為myApi.h裡面這個function沒有被設為visible
    //this_func_should_not_be_visible(1,1);

    printf("call mymul(%f,%f) ret %f\n",
        2.f, 3.f, mymul(2.f, 3.f));

    printf("call myAdd(%d,%d) ret %d\n",
        3, 4, myAdd(3, 4));

    printf("create class class1(6,7), type : MyTestClass\n");
    MyTestClass class1(6,7);

    printf("class1.Pineapple() = %d\n", class1.Pineapple());
    printf("class1.ApplePencil() = %f\n", class1.ApplePencil());
    return 0;
}
