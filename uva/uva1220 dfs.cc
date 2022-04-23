#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
vector<int> son[maxn];
map<string,int> mp;
int d[maxn][2];
bool f[maxn][2];

void dfs(int u){
    d[u][0]=0;
    d[u][1]=1;
    if(son[u].size()==0){
        return;
    }
    else{
        for(auto v:son[u]){
            dfs(v);
        }
        for(auto v:son[u]){
            if(f[v][0]) f[u][1]=1;
            d[u][1]+=d[v][0];
        }
        for(auto v:son[u]){
            if(d[v][0]==d[v][1]) f[u][0]=1;
            else if(d[v][0]<d[v][1]&&f[v][1]) f[u][0]=1;
            else if(d[v][0]>d[v][1]&&f[v][0]) f[u][0]=1;
            d[u][0]+=max(d[v][1],d[v][0]);
        }
    }
    return;
}

int main(){
    // ios::sync_with_stdio(false);
    int n;
    string s1,s2;
    while(cin>>n&&n){
        mp.clear();
        for(int i=1;i<=n;i++) son[i].clear();
        memset(f,0,sizeof(f));
        cin>>s1;
        int cnt=0;
        mp[s1]=++cnt;
        for(int i=2;i<=n;i++){
            cin>>s2>>s1;
            if(!mp[s2]) mp[s2]=++cnt;
            if(!mp[s1]) mp[s1]=++cnt;
            son[mp[s1]].push_back(mp[s2]); 
        }
        dfs(1);
        bool ok;
        int res;
        if(d[1][0]==d[1][1]) ok=1,res=d[1][0];
        else if(d[1][0]<d[1][1]) ok=f[1][1],res=d[1][1];
        else ok=f[1][0],res=d[1][0];
        if(ok==0) cout<<res<<" "<<"Yes"<<endl;
        else cout<<res<<" "<<"No"<<endl;
    }
    return 0;
}