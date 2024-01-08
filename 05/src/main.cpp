#include <iostream>
#include <string>
#include "../include/add.h"
#include "../include/sub.h"
#include "../include/div.h"

#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "../MathFunctions/MathFunctions.h"
#else
#include <cmath>
#endif

using namespace std;

int main(int argc,char *argv[])
{
  if (argc < 2) {
    /**
    * 当 CMake 配置此头文件时，会在二进制目录下生成一个文件 TutorialConfig.h，会把 TutorialConfig.h.in 中的内容拷贝到里面
    * PROJECT_VERSION, <PROJECT-NAME>_VERSION
    * PROJECT_VERSION_MAJOR, <PROJECT-NAME>_VERSION_MAJOR
    * PROJECT_VERSION_MINOR, <PROJECT-NAME>_VERSION_MINOR
    * PROJECT_VERSION_PATCH, <PROJECT-NAME>_VERSION_PATCH
    * PROJECT_VERSION_TWEAK, <PROJECT-NAME>_VERSION_TWEAK
    * MAJOR、MINOR、PATCH、TWEAK 分别代表着版本号的四位，比如版本号 1.2.3.4，MAJOR=1、MINOR=2、PATCH=3、TWEAK=4。版本号可以只有1位，最大为4位
    */
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;        
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]); 
  // which square root function should we use?
  #ifdef USE_MYMATH
    const double outputValue = mysqrt(inputValue);
  #else
    const double outputValue = sqrt(inputValue);
  #endif
  std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;
  
  int a = 20;
  int b = 10;
  printf("%d+%d=%d\n",a,b,add(a,b));
  printf("%d-%d=%d\n",a,b,sub(a,b));
  printf("%d/%d=%d\n",a,b,division(a,b));
  return 0;
}