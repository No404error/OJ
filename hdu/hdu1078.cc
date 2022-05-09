#include<bits/stdc++.h>
using namespace std;
const int maxn=105;

int g[maxn][maxn];
int dp[maxn][maxn];
int n,k;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int dfs(int i,int j){
    if(dp[i][j]) return dp[i][j];
    dp[i][j]=g[i][j];
    int maxsum=0;
    for(int p=0;p<4;p++) for(int s=1;s<=k;s++){
        int ni=i+dx[p]*s;
        int nj=j+dy[p]*s;
        if(ni<1||ni>n||nj<1||nj>n) continue;
        if(g[i][j]<g[ni][nj]) maxsum=max(maxsum,dfs(ni,nj));
    }
    dp[i][j]+=maxsum;
    return dp[i][j];
}
int main(){
    while(~scanf("%d%d",&n,&k)&&n!=-1){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&g[i][j]);
        memset(dp,0,sizeof(dp));
        int res=0;
        printf("%d\n",dfs(1,1));
    }
    return 0;
}