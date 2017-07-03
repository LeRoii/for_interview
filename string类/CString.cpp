#include"CString.h"
#include"stdlib.h"

using namespace std;


CString::CString(const char* str)
{
	if(NULL == str)
	{
		m_len = 0;
		m_str = NULL;
	}
	else
	{
		m_len = strlen(str);
		m_str = new char[m_len+1];
		strcpy(m_str,str);
	}
}

CString::CString(const CString &str)
{
	if(NULL == str.m_str)
	{
		m_len = 0;
		m_str = NULL;
	}
	else
	{
		m_len = strlen(str.m_str);
		m_str = new char[str.m_len+1];
		strcpy(m_str,str.m_str);
	}
}

CString::~CString()
{
	if(NULL != m_str)
	{
		delete[] m_str;
		m_str = NULL;
	}
}

CString& CString::operator=(const CString& str)
{
	if(&str == this)
	{
		return *this;
	}
	if(this->m_len >= str.m_len)
	{
		if(NULL == str.m_str)
		{
			this->m_len = 0;
			this->m_str = NULL;
			return *this;
		}
		else
		{
			strcpy(this->m_str,str.m_str);
			return *this;
		}
	}
	else
	{
		delete[] m_str;
		this->m_len = str.m_len;
		this->m_str = new char[m_len+1];
		strcpy(m_str,str.m_str);
		return *this;
	}
}

CString& CString::operator=(const char* str)
{
	if(NULL == str)
	{
		m_len = 0;
		m_str = NULL;
		return *this;
	}
	if(m_len >= strlen(str))
	{
		m_len = strlen(str);
		strcpy(m_str,str);
		return *this;
	}
	else
	{
		delete[] m_str;
		m_len = strlen(str);
		m_str = new char[m_len + 1];
		strcpy(m_str,str);
		return *this;
	}
}

int CString::Size() const
{
	return m_len;
}

const char& CString::operator[](unsigned n) const
{
	if(n < m_len)
		return m_str[n];
	exit(-1);
	return m_str[0];;
}

CString& CString::operator+=(const CString &str)
{
	if(NULL == str.m_str)
		return *this;
	int len = m_len + str.m_len;
	char* newStr = new char[len + 1];
	if(0 == m_len)
	{
		*newStr = '\0';
	}
	else
	{
		strcpy(newStr,m_str);
	}
	strcat(newStr,str.m_str);
	delete[] m_str;
	m_str = newStr;
	return *this;
}

ostream& operator<<(ostream& o,const CString& s)
{
	if(s.str())
		o<<s.str();
	return o;
}


		

































































