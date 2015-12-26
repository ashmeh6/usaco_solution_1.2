/*
ID: ashishm3
LANG: C++
TASK: transform
*/

#include<iostream>
#include<fstream>
using namespace std;
char arr[10][10],tmp[10][10], arrcpy[10][10]
,mainarr[10][10];int n;
void rot(char (&tmp)[10][10], char (&arrcpy)[10][10])
{
	for(int j=0,ii=0;j<n;j++)
	{
		for(int i=n-1,jj=0;i>=0;i--)
		{
			tmp[ii][jj] = arrcpy[i][j];
			jj++;
		}
		ii++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arrcpy[i][j] = tmp[i][j];
		}
	}
}

void refl(char (&arrcpy)[10][10])
{
	for(int i=0,ii=0;i<n;i++)
	{
		for(int j=n-1,jj=0;j>=0;j--)
		{
			arrcpy[ii][jj] = arr[i][j];
			jj++;
		}ii++;
	}
}


bool valid(char (&arrcpy)[10][10])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mainarr[i][j] != arrcpy[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int ans = 0;
	ifstream fin ("transform.in");
	 ofstream fout ("transform.out");
	fin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fin>>arr[i][j];//1st Array
		}
	}
	 for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fin>>mainarr[i][j];//2nd array
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arrcpy[i][j] = arr[i][j];
		}
	}
	
	
	rot(tmp,arrcpy);//again i.e 90
	ans++;
	if(valid(arrcpy))
	{
		fout<<ans<<"\n";
		return 0;
	}
	 	rot(tmp,arrcpy);//again i.e 180
	 	ans++;
	if(valid(arrcpy))
	{
		fout<<ans<<"\n";
		return 0;
	}
	rot(tmp,arrcpy);//again i.e 270
	ans++;
	if(valid(arrcpy))
	{
		fout<<ans<<"\n";
		return 0;
	}
	refl(arrcpy);// ans 4
	ans++;
	if(valid(arrcpy))
	{
		fout<<ans<<"\n";
		return 0;
	}
	rot(tmp,arrcpy);//again i.e 90
	ans++;					// ans 5
	if(valid(arrcpy))
	{
		fout<<ans<<"\n";
		return 0;
	}
	 rot(tmp,arrcpy);//again i.e 180
	if(valid(arrcpy))
	{
		fout<<ans<<"\n";
		return 0;
	} 
	rot(tmp,arrcpy);//again i.e 270
	if(valid(arrcpy))
	{
		fout<<ans<<"\n";
		return 0;
	}
	ans++;
	
	
	if(valid(arr))
	{
		fout<<ans<<"\n";
	}
	else
	{
		fout<<++ans<<"\n";
	}
	/* for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arrcpy[i][j]<<"\t";
		}cout<<"\n";
	}*/
	//cout<<valid(arrcpy);
	return 0;
}