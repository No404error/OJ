#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
vector<int> sons[maxn];
map<string,int> m;
int d[maxn][2];
bool f[maxn][2];
bool vis[maxn][2];
int dp(int u,int i){
    if(vis[u][i]) return d[u][i];
    vis[u][i]=1;
    int& ans=d[u][i];
    bool& ok=f[u][i];
    ans=0;
    ok=1;
    if(sons[u].size()==0) ans=i,ok=1;
    else{
        int k=sons[u].size();
        if(i==1){
            ans=1;
            for(int i=0;i<k;i++){
                ans+=dp(sons[u][i],0);
                if(f[sons[u][i]][0]==0) ok=0;
            }
        }
        else{
            for(int i=0;i<k;i++){
                if(dp(sons[u][i],0)==dp(sons[u][i],1)) ok=0;
                if((dp(sons[u][i],0)<dp(sons[u][i],1))&f[sons[u][i]][1]==0) ok=0;
                if((dp(sons[u][i],0)>dp(sons[u][i],1))&&f[sons[u][i]][0]==0) ok=0;
                ans+=max(dp(sons[u][i],0),dp(sons[u][i],1));
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    int n,res;
    int cnt=0;
    bool ok;
    string name1,name2;
    while(cin>>n&&n){
        res=-1;
        cnt=0;
        m.clear();
        for(int i=0;i<=n;i++) sons[i].clear();
        memset(vis,0,sizeof(vis));
        cin>>name1;
        m[name1]=++cnt;
        for(int i=1;i<n;i++){
            cin>>name2>>name1;
            if(!m[name1]) m[name1]=++cnt;
            if(!m[name2]) m[name2]=++cnt;
            sons[m[name1]].push_back(m[name2]);
        }
        for(int i=1;i<=n;i++) {
            dp(i,0);
            dp(i,1);
        }
        
        if(d[1][0]==d[1][1]) {
            ok=false;
            res=d[1][0];
        }
        else{
            if(d[1][0]>d[1][1]) ok=f[1][0],res=d[1][0];
            else ok=f[1][1],res=d[1][1];
        }

        cout<<res<<" ";
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}