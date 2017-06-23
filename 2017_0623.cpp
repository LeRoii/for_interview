#include<iostream>

using namespace std;
/*
int main()
{
	union U{
		short i;		//2byte
		char a[2];		//1*2byte
	}u;

	//u.i=1;
	u.a[0]=0x12;
	u.a[1]=0x34;

	printf("%#x\n",u.i);	//0x3412
}

int i;
int *p;
int func()
{
	static int j=0;		//局部静态变量赋初值是在编译时进行的，即只赋初值一次,再次调用时用的是上次的值而不是初始化的值
	j=11;
	p=&j;
	cout<<"p is: "<<p<<endl;
	cout<<"*p is: "<<*p<<endl;
	return j++;
}

int main()
{
	int rst=0;
	rst=func()+i;
	cout<<*p<<endl;
	cout<<rst<<endl;
	rst=rst+func()+i;
	cout<<*p<<endl;
	cout<<rst<<endl;
}
*/
struct ST{
	int i;		//4byte		4
//	short s;	//2byte		8
	float f;
	double d;	//8byte		16
//	float f;	//4byte		24
//	char c[4];	//5byte		32
//	int *p;		//8byte		40		//64位系统指针8字节，32位系统指针4字节
};

int main()
{
	cout<<sizeof(ST)<<endl;
}
