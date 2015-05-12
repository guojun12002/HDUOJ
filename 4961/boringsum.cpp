#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	const int max=100001;
	while(cin>>n)
	{
		if(!n) break;
		int a[max],b[max],c[max],h1[max]={},h2[max]={};
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			if(h1[a[i]])
				b[i]=h1[a[i]];
			else
				b[i]=a[i];
			if(h2[a[n-i+1]])
				c[n-i+1]=h2[a[n-i+1]];
			else
				c[n-i+1]=a[n-i+1];
			for(int j=1;j<sqrt(a[i])+1;j++)
				if(a[i]%j==0)
				{
					h1[j]=a[i];
					h1[a[i]/j]=a[i];
				}
			for(int j=1;j<sqrt(a[n-i+1])+1;j++)
				if(a[n-i+1]%j==0)
				{
					h2[j]=a[n-i+1];
					h2[a[n-i+1]/j]=a[n-i+1];
				}

		}
		long long sum=0;
		for(int i=1;i<=n;i++)
			sum+=(long long)b[i]*c[i];
		cout<<sum<<endl;
	}
	return 0;
}