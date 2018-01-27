#include<string.h>
#include"CStr.h"


CStr::CStr(){
	m_str = new char;
}

CStr::CStr(const char *str){
	m_str = new char;
	strcpy(m_str,str);
}

CStr::CStr(const CStr& cstr){
	m_str = new char;
	strcpy(m_str,cstr.m_str);
}

CStr& CStr::operator =(const CStr& cstr){

}

CStr::~CStr(){
	if(m_str){
		delete m_str;
		m_str = NULL;
	}
}