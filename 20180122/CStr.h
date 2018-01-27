class CStr{
public:
	CStr();
	CStr(const char *str);
	CStr(const CStr& cstr);
	~CStr();
	const char *GetStrPtr(){return m_str;}
	CStr& operator =(const CStr& cstr);

private:
	char *m_str;
};