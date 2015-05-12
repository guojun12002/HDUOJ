#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int_fast64_t conversion(int_fast64_t n,int_fast64_t m,int_fast64_t v,int_fast64_t k)
{
    if(n<=m) return 0;
    else if(m<v || m>=(m-v)*k) return -1;
    else return 1+conversion(n,(m-v)*k,v,k);
}
int main()
{
    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int_fast64_t N,M,V,K;
        cin>>N>>M>>V>>K;
        cout<<conversion(N,M,V,K)<<endl;
    }
    return 0;
}
