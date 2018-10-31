# 如何產生library

## 前言背景
- linux下的動態連結檔是 **.so**，靜態連結檔是 **.a**
  - linux下決定某個function/class/變數可不可以被外部呼叫的是其可見度(visibility)
  - linux下沒有特別設定，所有的東西預設都是可見的(**可以**被外部呼叫的)
  - 因此在linux下包library時，第一件要做的事是將可見度預設設為hidden
- Windows下的動態連結檔是 **.dll**，靜態連結檔是 **.lib**
  - windows下決定某個function/class/變數可不可以被外部呼叫的是其有沒有被EXPORT
  - windows下沒有特別設定，所有的東西預設都是沒有EXPORT的(**不可以**被外部呼叫的)

<br/>

## linux如和包library
#### CMakeLists.txt部分
- 設定可見度預設為hidden
  - set(CMAKE_CXX_VISIBILITY_PRESET hidden) # C++預設可見度為hidden
  - set(CMAKE_C_VISIBILITY_PRESET hidden) # C預設可見度為hidden
- 將add_executable改為add_library
  - add_library(<名稱> SHARED <程式碼清單>) 會產生動態連結檔
  - add_library(<名稱> STATIC <程式碼清單>) 會產生靜態連結檔

#### 程式碼部分 (主要請參考myApi.h)
- 想要讓人使用的function/class/變數，加上 `__attribute__((visibility ("default")))`
- 由於編譯是以 .cpp/.c 為單位做編譯，記得都要include到

<br/>

## 建置此專案
- 由於只是說明建置library的流程，因此普通有gcc的電腦就可以了
- `cd create_library`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`
- 成功後應該會看到libmyApi.so檔出現

<br/>

## 測試工具
- 建置好後，可以用以下幾個工具來看.so檔有哪些function/class/變數是可見的
  - `nm -gC libmyApi.so`
    - `-g` 只顯示可見的東西
    - `-C` 將名稱做修飾，變得比較容易看
  - `objdump -TC libmyApi.so`
    - `-T` 只顯示可見的東西
    - `-C` 將名稱做修飾，變得比較容易看
  - `readelf --dyn-syms libmyApi.so`
    - `--dyn-syms` 只顯示可見的東西
- 你可以試著把DLL_EXPORT拿掉，或是CMAKE_CXX_VISIBILITY_PRESET拿掉，再make一次
- 然後看看會有甚麼變化(記得之後要復原)

<br/>

## 延伸閱讀
- Name mangling : 編譯器編譯時，會把變數名稱/function名稱/不管甚麼名稱，都會做修飾(修改)
  - 主要目的是為了記錄其參數型態或是資料型態
  - nm和objdump的-C，都是在做demangle，也就是把名稱還原成原本的樣子
  - 參考資料[https://en.wikipedia.org/wiki/Name_mangling](https://en.wikipedia.org/wiki/Name_mangling)
    - 中文版[https://zh.wikipedia.org/wiki/%E5%90%8D%E5%AD%97%E4%BF%AE%E9%A5%B0](https://zh.wikipedia.org/wiki/%E5%90%8D%E5%AD%97%E4%BF%AE%E9%A5%B0)
