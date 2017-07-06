#include<iostream>
#include<stdio.h>

class CSingleton
{
	private:
		CSingleton(){}
		CSingleton(const CSingleton &singleton);
		CSingleton& operator=(const CSingleton &);
		static CSingleton* m_pself;
	public:
		static CSingleton* GetInstance(){
			if(NULL == m_pself)
				m_pself = new CSingleton();
			return m_pself;
		}
};

CSingleton* CSingleton::m_pself=NULL;//必须初始化否则会有链接错误,非常量的静态成员变量必须在类外初始化
