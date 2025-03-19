#ifndef SAY_HELLO_HH
#define SAY_HELLO_HH
#include <iostream>

// 使用关键字，__declspec(dllexport)来导出函数
// 这个关键字是Windows特有的，Linux下不需要
// 这个关键字的作用是，告诉编译器，这个函数是要导出的
// 这样，在编译的时候，编译器就会生成一个.lib文件，这个.lib文件是用来链接的
// 这个.lib文件里面包含了这个函数的地址，这样在链接的时候，就可以找到这个函数的地址
// 这个函数的地址是在编译的时候确定的，所以在链接的时候，就可以找到这个函数的地址

void say_hello();
void add(int a, int b);
#endif