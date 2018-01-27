#### * vector和list分别怎么用

vector在内存中连续存储，随机存储效率高，插入删除或重新申请空间需要拷贝内存效率低
list和链表类似，在内存中不连续，随机存取效率低，插入删除效率高<br>
使用原则：<br>

vector适用：对象数量变化少，结构简单，随机访问频繁<br>
list适用：对象数量变化大，结构复杂，插入删除频繁<br>

#### * static_cast,dynamic_cast,reinterpret_cast,const_cast的区别

`static_cast<typeid>(expression)`<br>
把expression转换为typeid类型<br>
1. 用于基类派生类之间指针或引用的转换，派生类转为基类是安全的，基类转为派生类是不安全的<br>
2. 基本数据类型的转换（int，char，double，float）<br>
3. 空指针转为目标类型的空指针<br>
4. 任意类型的表达式转换成void类型<br>

一般的转换，用的最多，在编译时强制转换<br>

`dynamic_cast`<br>
用于类层次间的转换，还有类之间的交叉转换，基类转为派生类时比static_cast安全，因为有类型检查的功能，根据RTTI<br>

一般用于基类和派生类之间的转换，在运行时转换<br>

`reinterpret_cast`<br>
用于进行没有任何关联之间的转换，如一个字符转为一个整形，指针和整数之间的转换<br>

`const_cast`<br>
用来移除const，volatile属性，常量转为非常量<br>


#### *volatile有什么用<br>


使用volatile声明变量，说明该变量会在程序外被改变，系统总是重新从它所在的内存读取数据，而不是使用寄存器中的备份.<br>


#### *extern C用法

为了能够正确实现C++代码调用其他C语言代码, 它会指示编译器这部分代码按C语言进行编译和链接,cpp支持重载而c不支持,编译函数时会加入函数的参数信息,编译c语言时不会带入参数信息<br>
用g++编译cpp程序时,编译器会定义宏__cplusplus,可以根据是否定义了这个宏决定是否需要extern “C”<br>


为了能够正确实现C++代码调用其他C语言代码。加上extern "C"后，会指示编译器这部分代码按C语言的进行编译，而不是C++的。由于C++支持函数重载，因此编译器编译函数的过程中会将函数的参数类型也加到编译后的代码中，而不仅仅是函数名；而C语言并不支持函数重载，因此编译C语言代码的函数时不会带上函数的参数类型，一般之包括函数名。



场景：<br>
1.写一个c模块供以后使用,源文件事先编译好<br>
```c
#ifdef __cplusplus
extern “C”{
#endif
//some code
#ifdef __cplusplus
}
#endif
```

2.模块已经存在,在cpp代码中<br>
```cpp
extern “C”{
#include “module_written_in_c.h”
int funcInC(int);
}
```

#### * const用法<br>
```cpp
char greeting[ ] = “hello”;
char const *p = greeting;   //non-const pointer const data
const char *p = greeting;   //non-const pointer const data
char * const p = greeting;  //const pointer non-const data
const char * const p = greeting;    //const pointer const data;
```

**const出现在星号左边，指针指的数据是变量**<br>
**const出现在星号右边，指针本身是常量**<br>


STL迭代器类似指针,作用如同 T*<br>
声明迭代器为const如同声明指针为const, 即指针为常量,不可指向其他数据, <br>但指向的数据可以改变,即 T* const p<br>
如果希望迭代器指向的数据不可变,即 const T* p,需要用 const_iterator<br>
```cpp
std::vector<int> vec;
const std::vector<int>::iterator iter = vec.begin( );       //T* const p
*iter = 10;     //ok
iter++;         //error
std::vector<int>::const_iterator cIter;     //const T* p
*cIter = 10;        //error
cIter++;        //ok
```

const可以修饰：<br>
1. 局部和全局变量：变量值不会变<br>
2. 函数参数：参数不会被函数改变<br>
3. 函数返回值：返回值不能做为左值，多用于操作符重载，避免出现如下错误<br>
```cpp
class Rational{…};
const Rational operator* (const Rational& lhs, const Rational& rhs);
Rational a,b,c;
(a*b) = c;
```
4. 类的成员函数本身：只有被const修饰的成员函数才可以被const对象调用<br>
const成员函数中不允许对成员进行修改<br>
如果成员变量被mutable修饰，就可以被const成员函数修改<br>
如果成员是指针，const成员函数可以修改指针指向的内容，如<br>
```cpp
har* m_sName;
void setName(const string &s) const
{
    m_sName = s.c_str();    //error
    m_sName[1] = s[1];      //ok
}
```


