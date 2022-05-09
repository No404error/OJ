#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int val[maxn],dp[maxn][2];
int mxp[maxn];
bool np[maxn];
vector<int> son[maxn];
set<int> s[maxn];

void init(int n){
    memset(np,1,sizeof(np));
    for(int i=2;i*i<=n;i++) if(np[i]) for(int j=i;j<=n;j+=i) {
        np[j]=0;
        mxp[j]=i;
    }
}

void dfs(int u,int p){
    s[u].insert(p);
    int cnt=0,temp=val[u],sum1=0,sum0=0;
    while(temp%p==0){
        temp/=p;cnt++;
    }
    for(auto v:son[u]) {
        if(!s[v].count(p)&&val[v]%p==0){
            dfs(v,p);
            sum0=min(dp[v][0],dp[v][1]);
            sum1=dp[v][1];
        }
    }
    dp[u][0]=sum1;
    dp[u][1]=cnt+sum0;
}

int main(){
    int n;
    scanf("%d",&n);
    init(1e5);
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    int u,v;
    for(int i=1;i<n;i++) scanf("%d%d",&u,&v),son[u].push_back(v),son[v].push_back(u);
    long long res=0;
    for(int i=1;i<=n;i++){
        while(val[i]!=1){
            int p=mxp[val[i]];
            if(!s[i].count(p)){
                dfs(i,p);
                res+=min(dp[i][0],dp[i][1]);
            }
            while(val[i]%p==0) val[i]/=p;
        }
    }
    printf("%lld",res);
    return 0;
}