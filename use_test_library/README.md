# 如何使用.so檔
## 前置作業
- 首先把create_library建置完畢，參考create_library/README.md來完成
- 將**libmyApis.so**、**myApi.h**複製到use_test_library底下
## 修改CMakeLists.txt
- 首先要讓cmake知道libmyApis.so在哪裏
  - `find_library(<變數名稱> myApis HINTS ${CMAKE_CURRENT_SOURCE_DIR})`
  - linux的gcc，在連結時，預設前面會加lib，後面加.so，所以只打myApis，而不是libmyApis.so
    - ex : `gcc main.cpp -o myApiTestProgram -lmyApis`
      - `-l` : 要連結哪個.so檔，**中間不會加空格**
      - `-o` : 輸出的執行檔名稱
  - 這行指令會在CMakeLists.txt所在目錄下(use_test_library/)，搜尋libmyApis.so
  - 如果有找到，會將其路徑存到變數內
  - 以use_test_library/CMakeLists.txt為例，會存到MY_APIS裡
- 接著設定要連結的library
  - `target_link_libraries(<程式名稱> <要連結的Library>)`
  - 以use_test_library/CMakeLists.txt為例
    - `target_link_libraries(myApiTestProgram ${MY_APIS}`
  - 不直接target_link_libraries(myApiTestProgram libmyApis.so}
  - 或是target_link_libraries(myApiTestProgram myApis}的原因在於
  - 很大的機率cmake/gcc會找不到libmyApis.so放在哪而造成失敗

## 建置此專案
- `cd use_test_library`
- `cp ../create_library/build/libmyApis.so ./`
- `cp ../create_library/myApi.h ./`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`
- 接著應該會編譯失敗
  - 因為`this_func_should_not_be_visible`這個function是hidden的
  - 你可以把create_library/myApi.h裡的該function也加上DLL_EXPORT重新編譯複製
  - 或是直接把use_test_library/main.cpp的this_func_should_not_be_visible註解掉
- `make`
- 這次應該就會成功了 `./myApiTestProgram` 看執行結果
