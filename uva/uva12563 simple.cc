#include<bits/stdc++.h>
using namespace std;

const int maxn=10005;
const int maxt=55;
int dp[maxt][maxn];
int tim[maxt][maxn];
int song[maxt];
int main(){
    int T;scanf("%d",&T);
    int n,m;
    for(int kase=1;kase<=T;kase++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&song[i]);
        memset(dp,0,sizeof(dp));
        memset(tim,0,sizeof(tim));
        for(int i=n;i>=1;i--) for(int j=m;j>=1;j--){
            dp[i][j]=dp[i+1][j],tim[i][j]=tim[i+1][j];
            if(j-song[i]>=1&&(dp[i+1][j-song[i]]+1>dp[i][j]||(dp[i+1][j-song[i]]+1==dp[i][j]&&tim[i+1][j-song[i]]+song[i]>tim[i][j])))
                dp[i][j]=dp[i+1][j-song[i]]+1,tim[i][j]=tim[i+1][j-song[i]]+song[i];
        }
        printf("Case %d: %d %d\n",kase,dp[1][m]+1,tim[1][m]+678); 
    }
    return 0;
}