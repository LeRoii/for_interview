自定义一个string类
--


一般有：<br>
public方法：<br>

1. 接受`const char*`的构造函数<br>
2. 接受`const CString&`的拷贝构造函数<br>
3. 析构函数<br>
4. 接受`const char*`的赋值操作符<br>
5. 接受`const CString&`的赋值操作符<br>
6. 接受`unsigned`的[]操作符<br>
7. 接受另一个`CString`的+=操作符<br>
8. 返回字符串地址的get函数<br>

private成员：<br>

`unsigned` 字符串长度<br>
`char*` 字符串<br>

注意：<br>
* 构造函数接受的参数要加`const`，因为这些参数不需要被改变<br>
* 当接受`const char*`指针时需要先**判空**<br>
* 为`m_str`申请空间时应该申请**strlen(str)+1**大小，最后一个放'\0'<br>
* 接受`const CString&`时也应当判断字符串是否为空<br>
* 析构时应该用`delete[]`来删除字符串，对应构造时的`new char[strlen(str)+1]`<br>


* 重载操作符接受的参数也要加`const`<br>
* 重载赋值操作符接受的参数是`const CString&`时要判断参数是不是本身<br>
```cpp
if(&str == this){
    return *this;
}
```
* 重载操作符返回值是引用，`return *this`<br>
* 重载赋值操作符时要判断参数字符串的长度和本身字符串的长度哪个大，如果自身长度大可以直接strcpy，不然需要先delete再申请足够的空间来copy<br>