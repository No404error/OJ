#include<bits/stdc++.h>
using namespace std;

struct block
{
    int l,r,h;
    bool operator<(const block& b) const{
        if(l<b.l&&r<b.r) return true;
        else return false;
    }
    bool operator==(const block& b)const{
        return l==b.l&&r==b.r&&h==b.h;
    }
    block(int i,int j,int k): l(i),r(j),h(k){};
    block(){};
};

const int maxn=190;
block blocks[maxn];
bool vis[maxn];
int dp[maxn];
int cnt;

int dps(int i){
    if(vis[i]) return dp[i];
    vis[i]=1;
    dp[i]=blocks[i].h;
    for(int j=1;j<=cnt;j++) if(blocks[j]<blocks[i]) dp[i]=max(dp[i],dps(j)+blocks[i].h);
    return dp[i];
}

int main(){
    int n;
    int l,r,h;
    int kase=1;
    while(~scanf("%d",&n)&&n){
        cnt=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&l,&r,&h);
            blocks[cnt++]={l,r,h};
            blocks[cnt++]={l,h,r};
            blocks[cnt++]={r,l,h};
            blocks[cnt++]={r,h,l};
            blocks[cnt++]={h,r,l};
            blocks[cnt++]={h,l,r};
        }
        sort(blocks+1,blocks+cnt);
        cnt=unique(blocks+1,blocks+cnt)-blocks-1;
        
        // printf("");
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=cnt;i++){
            dps(i);
        }
        
        int res=0;
        for(int i=1;i<=cnt;i++) res=max(res,dp[i]);
        printf("Case %d: maximum height = %d\n",kase++,res);
    }
    return 0;
}