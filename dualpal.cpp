/*
ID: ashishm3
LANG: C++
TASK: dualpal
*/


#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;
int c=0;
int bin(int n,int base, char (&num1)[32])
{
	if(n==0)
	return 0;
	else
	{
	 num1[c++] = n%(base)+'0';
	 
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
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
    int n,test=0,
    count =0,total;
    fin>>total>>n;
    while(total!=test)
    {n++;count=0;
    for(int i= 2;i<11;i++)
    {
    	char num1[32]= {""};
    	bin(n,i,num1);
    	if(checkPalin(num1)==0)
    	{count++;}
    	c=0;
    	if(count>=2)
    	{
    		fout<<n<<"\n";
    		test++;
    		break;
    	}
    }
    }
    return 0;
}
