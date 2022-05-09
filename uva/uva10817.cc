#include<bits/stdc++.h>
using namespace std;
const int maxn=120+5;
const int maxs=(1<<8)+5;
const int inf=0x3f3f3f3f;
int m,n,s,c[maxn],st[maxn],d[maxn][maxs][maxs];

int dp(int i,int s0,int s1,int s2){
    if(i==m+n) return s2==(1<<s)-1?0:inf;
    int &ans=d[i][s1][s2];
    if(ans>=0) return ans;
    ans=inf;
    if(i>=m) ans=dp(i+1,s0,s1,s2);
    int to1=st[i]&s0,to2=st[i]&s1;
    s0^=to1,s1=(s1^to2)|to1,s2|=to2;
    ans=min(ans,c[i]+dp(i+1,s0,s1,s2));
    return ans;
}


int main(){
    while(~scanf("%d%d%d",&s,&m,&n)&&s){
        memset(st,0,sizeof(st));
        getchar();
        for(int i=0;i<m+n;i++){
            stringstream ss;
            string str;
            getline(cin,str);
            ss<<str;
            ss>>c[i];
            int cost;
            while(ss>>cost) st[i]+=1<<(cost-1);
        }
        memset(d,-1,sizeof(d));
        printf("%d\n",dp(0,(1<<s)-1,0,0));
    }
    return 0;
}