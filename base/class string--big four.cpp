class String{
public:
	String(const char* str=NULL);		//constructor
	String(const String& other);		//copy constructor
	~String();		
	String& operator=(const String& other);		//copy operator
private:
	char* m_data;
};

String::String(const char* str){
	if(str==NULL){
		m_data = new char[1];
		m_data[0]='\0';
	}else{
		int len = strlen(str);
		m_data = new char[len+1];
		assert(m_data!=NULL);
		strcpy(m_data, styr);
	}
}

String::String(const String& other){
	m_data = new char[strlen(other.m_data)+1];
	strcpy(m_data, other.m_data);
}

String::~String(){
	delete[] m_data;
}

String& String::operator=(const String& str){
	if(this==str){
		return *this;
	}
	delete[] m_data;
	m_data = new char[strlen(str.m_data)+1]；
	strcpy(m_data, str.m_data);
	return *this;
}

String& String::operator=(const String& str){
	if(*this!=str){
		String strTemp(str);			//防止内存分配过程中抛出异常
		char* pTemp = strTemp.m_data;
		strTemp.m_data = m_data;
		m_data = pTemp;
	}
	return *this;
}

