#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int mizz[102][102]={};
int getgold[102][102][3]={};
int M,N;
const int MAX=-1000000000;
int maxx(int a,int b)
{
    return a>b?a:b;
}
int gold(int m,int n,int flag)
{
    if(n==1) return mizz[m][n];
    else if(m<1 || m>M || n<1 || n>N) return MAX;
    else if(getgold[m][n][flag]!=MAX) return getgold[m][n][flag];
    switch(flag)
    {
        case 1:
            getgold[m][n][flag]=mizz[m][n]+maxx(gold(m,n-1,0),gold(m+1,n,1));
            return getgold[m][n][flag];
        case 0:
            getgold[m][n][flag]=mizz[m][n]+maxx(maxx(gold(m-1,n,-1),gold(m,n-1,0)),gold(m+1,n,1));
            return getgold[m][n][flag];
        case -1:
            getgold[m][n][flag]=mizz[m][n]+maxx(gold(m-1,n,-1),gold(m,n-1,0));
            return getgold[m][n][flag];
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        printf("Case #%d:\n",i);
        cin>>M>>N;
        for(int i=1;i<=M;i++)
            for(int j=1;j<=N;j++)
            {
                scanf("%d",&mizz[i][j]);
                getgold[i][j][0]=MAX;
                getgold[i][j][1]=MAX;
                getgold[i][j][2]=MAX;
                if(j==1) mizz[i][j]=mizz[i][j]+mizz[i-1][j];
            }
        cout<<gold(1,N,1)<<endl;
    }
    return 0;
}
