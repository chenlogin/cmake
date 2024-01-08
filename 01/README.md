- 创建一个build目录并进入是因为，在执行cmake的过程中，会产生许多中间文件。为了避免产生的中间文件，污染我们的工作目录，就让CMake在build中执行。
- "cmake .."是将CMakeLists.txt文件转换为适合当前系统的构建文件的命令。".."表示CMakeLists.txt文件在当前目录的上一级目录中。cmake会产生一系列Makefile文件或者其他的构建工具需要的文件。
- 在运行"cmake .."之后，您只需运行"make"命令，它会读取Makefile文件，并按照其中的指示编译源代码，生成可执行文件run（生成可执行文件或库）
- make生成的可执行文件在windows、mac、linux中类型
  - 在Windows操作系统中，Make生成的可执行文件通常是 .exe 文件。
  - 在Mac操作系统中，Make生成的可执行文件通常没有扩展名，可以直接通过命令行运行。例如，如果项目中的目标文件名为"project"，在Mac中可以通过./project在命令行中执行。
  - 在Linux操作系统中，Make生成的可执行文件通常没有扩展名，是一个二进制文件。可以直接在终端中运行
  
```
mkdir build
cd build
cmake ..
make
./run
#此时会输出Hello World
```