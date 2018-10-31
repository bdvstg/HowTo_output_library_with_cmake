#include "myApi.h" // 記得要include
// 不然gcc在編譯這個檔案(myAdd.cpp)時，就不會知道要把myAdd的可見度設為default

int myAdd(int v1, int v2)
{
    return v1 + v2;
}
