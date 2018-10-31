#include "myApi.h" // 記得要include
// 不然gcc在編譯這個檔案(myMul.cpp)時，就不會知道要把mymul的可見度設為default

float mymul(float v1, float v2)
{
    return (v1 + 1.f) * (v2 - 3.f);
}
