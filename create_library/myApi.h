#ifndef MY_CLASS_H__
#define MY_CLASS_H__

// 由於在CMakeLists.txt內，已將所有的設為隱藏
// 因此需要使用這個macro讓該function/class變得可以被看到
#define DLL_EXPORT __attribute__((visibility ("default")))

DLL_EXPORT float mymul(float v1, float v2);
DLL_EXPORT int myAdd(int v1, int v2);
class DLL_EXPORT MyTestClass
{
private:
    int pen;
    int apple;
public:
    MyTestClass(int num_of_pen, int num_of_apple);
    int Pineapple();
    float ApplePencil();
};


// 這個function故意不加DLL_EXPORT，之後會造成use_test_library的編譯錯誤
// nm -g libmyApis.so也應該看不到這個function
int this_func_should_not_be_visible(int a, int b);

#endif
