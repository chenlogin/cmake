#最低cmake版本
cmake_minimum_required (VERSION 3.28)

#设置项目名称和版本
project(Tutorial VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)  # 将 C++ 标准设置为 C++ 11
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # C++ 11 是强制要求，不会衰退至低版本
set(CMAKE_CXX_EXTENSIONS OFF)  # 禁止使用编译器特有扩展

# 我们应该使用自己的数学函数吗
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 配置头文件以将某些CMake设置传递给源代码
configure_file(TutorialConfig.h.in TutorialConfig.h)

# 添加 MathFunctions 库
if (USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif ()

# 查找目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(src DIR_SRCS)
add_executable(Tutorial ${DIR_SRCS})

# 将二进制目录添加到包含文件的搜索路径中，以便我们找到TutorialConfig.h
target_include_directories(Tutorial PUBLIC
        "${PROJECT_BINARY_DIR}"
        )
target_include_directories(Tutorial PUBLIC
        "${EXTRA_LIBS}"
        "${EXTRA_INCLUDES}"
        )
