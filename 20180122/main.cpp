#include<stdio.h>
#include"CStr.h"

int main(){
	CStr *s1 = new CStr();
	CStr *s2 = new CStr("s2");
	CStr *s3 = new CStr(*s2);

	printf("%s,%s,%s",s1->GetStrPtr(),s2->GetStrPtr(),s3->GetStrPtr());

	delete s1;
	delete s2;
	delete s3;

	return 0;
}