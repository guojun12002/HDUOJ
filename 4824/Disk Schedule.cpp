#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int MAX=1001*1001;
int least[1001][1001]={};
int dist[1001][1001]={};
int disk[1001]={};
int main()
{
    freopen("input.txt","r",stdin);
    int M;
    cin>>M;
    while(M--)
    {
        int N;
        cin>>N;
        int T,S;
        int time=0;
        for(int i=1;i<=N;i++)
        {
            cin>>T>>disk[i];
            time+=10;
        }
        time+=T*400*2;
        for(int i=1;i<=N;i++)
            for(int j=0;j<i;j++)
            {
                int d=abs(disk[i]-disk[j]);
                dist[i][j]=dist[j][i]=d>180?360-d:d;
            }
        least[0][1]=least[1][0]=dist[0][1];
        for(int i=2;i<=N;i++)
            least[0][i]=least[i][0]=least[0][i-1]+dist[i-1][i];
        for(int i=1;i<N;i++)
        {
            int min=MAX;
            for(int k=0;k<i;k++)
            {
                int temp=least[i][k]+dist[k][i+1];
                min=min>temp?temp:min;
            }
            least[i+1][i]=least[i][i+1]=min;
            for(int j=i+2;j<=N;j++)
                least[i][j]=least[j][i]=least[i][j-1]+dist[j-1][j];
        }
        least[N][N]=least[N][N-1]+dist[N-1][N];
        time+=least[N][N];
        cout<<time<<endl;
    }
    return 0;
}