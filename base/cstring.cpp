int strlen(const char* str){
	assert(str!=NULL);
	int len=0;
	while((*str++)!='\0'){
		len++;
	}
	return len;
}

int strcmp(const char* str1, const char* str2){
	assert(str1!=NULL && str2!=NULL);
	int ret=0;
	while(!(ret=*(unsigned char*)(str1)-*(unsigned char*)(str2))&&*str1){
		str1++;
		str2++;
	}
	if(ret<0) ret=-1;
	else if(ret>0) ret=1;
	return ret;
}

char* strcat(char* strDest, const char* strSrc){
	char* address = strDest;
	assert((strDest!=NULL)&&(strSrc!=NULL));
	while(*strDest){
		strDest++;
	}
	while(*strDest++ = *strSrc++);
	return address;
}

char* strcpy(char* strDest, const char* strSrc){
	assert(strDest!=NULL && strSrc!=NULL);
	char* address = strDest;
	while((*strDest++ = *strSrc++)!='\0');
	return address;
}

void* memmove(void* dest, const void* src, size_t n){
	char* p1 = destl
	const char* p2 = src;
	if(p2<p1){
		p2+=n;
		p1+=n;
		while(n--!=0){
			*--p1 = *--p2;
		}
	}else{
		while(n--!=0){
			*p1++ = *p2++;
		}
	}
	return p1;
}