#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
double f[maxn],p[maxn]; //f为生存天数表，p为概率表
int main(){
    int T,n,k,m;scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(f,0,sizeof(f));
        scanf("%d%d%d",&n,&k,&m); //状态表的初始化 m=0,f=0 m=1,f=p[0]
        for(int i=0;i<n;i++) scanf("%lf",&p[i]); 
        f[1]=p[0]; //递推方程：用一个麻团的族群彻底消失的时间角度考虑
        for(int i=2;i<=m;i++) for(int j=0;j<n;j++) f[i]+=p[j]*pow(f[i-1],j); 
        printf("Case #%d: %.7lf\n",t,pow(f[m],k));
    }
    return 0;
}