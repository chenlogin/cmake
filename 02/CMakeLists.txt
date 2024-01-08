# 多个源文件和头文件

cmake_minimum_required (VERSION 3.28)
project(course_02)

set(CMAKE_CXX_STANDARD 11)  # 将 C++ 标准设置为 C++ 11
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # C++ 11 是强制要求，不会衰退至低版本
set(CMAKE_CXX_EXTENSIONS OFF)  # 禁止使用编译器特有扩展

if(NOT CMAKE_BUILD_TYPE)
	message(WARNING "NOT SET CMAKE_BUILD_TYPE")
  set(CMAKE_BUILD_TYPE "Release")
endif()

# 获取所有源文件，将src下面所有cpp源文件的名字，记录到变量SRC中，然后再通过${SRC}引用变量
aux_source_directory(src SRC)
message(STATUS ${SRC})
set(INCLUDE "include")

add_executable(run ${SRC})
# 指明了run目标的包含路径，这样我们在生成run这个可执行文件的过程中，它就知道在哪些路径下去找头文件
target_include_directories(run PRIVATE ${INCLUDE})

# 既然有指定头文件路径的这个属性，那肯定也有目标的源文件（cpp）存放地址的这个属性
# add_executable(run) 
# target_sources(run PRIVATE ${SRC})
# target_include_directories(run PRIVATE ${INCLUDE})