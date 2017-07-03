#include<iostream>

using namespace std;


class CString{
	public:
		CString(const char* str);
		CString(const CString &str);
		~CString();

		CString& operator=(const CString &str);
		CString& operator=(const char* str);

		int Size() const;

		const char& operator[](unsigned n) const;

		CString& operator+=(const CString& other);

		const char* str() const {return m_str;};

	private:
		unsigned m_len;
		char* m_str;
};

ostream& operator<<(ostream& o,const CString& s);
