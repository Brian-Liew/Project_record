#include<iostream>
using namespace std;
void* memcp(void* decs,const void* source,int size)
{
	if(decs==NULL&&source==NULL)
		return NULL;
	unsigned char* decs1=(unsigned char*) decs;
	unsigned char* src1=(unsigned char*)src1;
	while(size-->0)
	{
		*decs1=*src1;
		decs1++;
		src1++;
	}
	return decs;
}
int main()
{
	int dest[2]={0};
	const char src[5]='1234';
	memcp(dest,src,sizeof(src));
}