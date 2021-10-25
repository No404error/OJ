#include<bits/stdc++.h>
using namespace std;
const int maxn=32;
int comb[maxn][maxn],n,m,t;
int getcomb(int u,int d){ //解组合数
    if(u>d-u) u=d-u; //根据组合数对称的性质来降低复杂度
    comb[d][0]=1; //递推基
    for(int i=1;i<=u;i++){ 
        if(comb[d][i]) continue; //是否被访问过
        comb[d][i]=comb[d][i-1]*(d-i+1)/i; //递推公式
    }
    return comb[d][u]; //返回组合数
}
long long ans; 
int main(){
    ans=0;
    cin>>n>>m>>t;
    for(int i=1;t-i>=4;i++){ //从女生数量为1开始，到男生数量不足为止
        ans+=getcomb(i,m)*(long long)getcomb(t-i,n); 
    }
    cout<<ans<<endl;
    return 0;
}