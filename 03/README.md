- 在CMake中主要有三种生成目标的办法：
  - 使用add_executable生成可执行目标，add_library可以用来生成共享库与静态库目标(SHARED表示共享库，STATIC表示静态库)
```
add_executable(run main.cpp)   #生成可执行文件目标run
add_library(math SHARED add.cpp sub.cpp)   #生成共享库目标math
add_library(math STATIC add.cpp sub.cpp)   #生成静态库目标math
```