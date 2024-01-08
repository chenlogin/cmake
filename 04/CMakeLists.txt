# 在CMakeList中编写安装项目的相关代码。把生成的库和相关的头文件，安装到对应的系统目录下，去供别人使用
# sudo make install
├── build
├── CMakeLists.txt
├── include
│   └── my_math.hpp
├── install
│   ├── bin
│   │   └── run
│   ├── lib
│   │   └── libmy_math.a
│   └── my_math
│       └── include
│           └── my_math.hpp
├── src
│   ├── add.cpp
│   └── sub.cpp
└── test
    └── main.cpp


# 接03 CMAKELists.txt
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install/)
install(TARGETS 
            run my_math
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib)
 install(FILES include/my_math.hpp DESTINATION my_math/include)