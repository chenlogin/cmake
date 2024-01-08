# cmake目标与目标属性，即生成可执行文件，也生成静态库

cmake_minimum_required (VERSION 3.28)
project(course_03)

set(CMAKE_CXX_STANDARD 11)  # 将 C++ 标准设置为 C++ 11
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # C++ 11 是强制要求，不会衰退至低版本
set(CMAKE_CXX_EXTENSIONS OFF)  # 禁止使用编译器特有扩展

aux_source_directory(src SRC)
set(INCLUDE "include")

# 生成静态库目标
add_library(my_math)
# 添加源文件
# PUBLIC：可以自己用，也可以提供别人用；INTERFACE：提供别人用；PRIVATE：只可以自己用
target_sources(my_math PRIVATE ${SRC})
# 添加头文件
target_include_directories(my_math PUBLIC ${INCLUDE})

# 获取目标属性
get_target_property(MYSOURCES my_math SOURCES)
message(STATUS ${MYSOURCES})

# 1、生成可执行文件目标
add_executable(run test/main.cpp)
# run目标链接my_math库目标
target_link_libraries(run my_math)

# 2、生成可执行文件也可以一起设置目录属性，目录要绝对路径
#add_executable(run)
#set_target_properties(run PROPERTIES
#                      SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp
#                      LINK_LIBRARIES my_math)
