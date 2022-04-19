#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
struct node{
    int v,k,c,l;
    bool operator<(const node& t) const{
        return v<t.v;
    }
} light[maxn];
int s[maxn];
int dp[maxn];
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        int a,b,c,d;
        for(int i=1;i<=n;i++) scanf("%d%d%d%d",&light[i].v,&light[i].k,&light[i].c,&light[i].l);

        sort(light+1,light+n+1);
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n;i++) s[i]=s[i-1]+light[i].l;
        for(int i=1;i<=n;i++) for(int j=0;j<=i;j++){
            dp[i]=min(dp[i],dp[j]+(s[i]-s[j])*light[i].c+light[i].k);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}