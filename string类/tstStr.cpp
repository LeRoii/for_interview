#include"CString.h"
#include<iostream>

using namespace std;

int main()
{
	CString a("aaa");
	CString b=a;
	CString c("ccc");
	c="ddd";
	cout<<a<<" "<<b<<" "<<c<<endl;
}
