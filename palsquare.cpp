/*
ID: ashishm3
LANG: C++
TASK: palsquare
*/
#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;
int c=0,i;
int bin(long long int n,int base, char (&num1)[32])
{
	if(n==0){
	return 0;}
	else
	{
	char x = n%(base)+'0';
	int inc;
	if(x-'9'>0)
	{
		inc = x-'9';inc--;
		x='A'+inc;
	}
	 num1[c++] =x;
	n/=(base);
	bin(n,base,num1);
	} 
}
int checkPalin(char (&arr)[32])
{
	char tmp[32]={""};
	int len;
	len = strlen(arr);
	int t=0;
	for(int i = strlen(arr)-1;i>=0;i--)
	{
		tmp[t++] = arr[i];
	}
	return strcmp(tmp,arr);
}
int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
    int base;
    fin>>base;
    for(i=1;i<=300;i++)
    {
    	char num1[32]= {""},numa[32]={""};c=0;
    	bin(i,base,numa);c=0;
    	bin(i*i,base,num1);
    	if(checkPalin(num1)==0)
    	{
    		char tmp[32]={""};int t=0;
    		for(int j= strlen(numa)-1;j>=0;j--)
				{
					tmp[t++] = numa[j];
				}
    		fout<<tmp<<" "<<num1<<"\n";
    	}
    }
    return 0;
}
