#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int dp[maxn];
int main(){
    int T;scanf("%d",&T);
    int n,t,tim;
    for(int kase=1;kase<=T;kase++){
        memset(dp,0xcf,sizeof(dp));
        scanf("%d%d",&n,&t);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&tim);
            for(int j=t-1;j>=tim;j--) dp[j]=max(dp[j],dp[j-tim]+1);
        }
        int ans=t-1;
        for(int i=t-1;i>=0;i--) if(dp[ans]<dp[i]) ans=i;
        printf("Case %d: %d %d\n",kase,dp[ans]+1,ans+678);
    }

    return 0;
}