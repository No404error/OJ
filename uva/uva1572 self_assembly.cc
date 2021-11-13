#include<bits/stdc++.h>
using namespace std;
vector<set<int>> G;
int vis[52]; //标记访问数组
int getId(char a1,char a2){
    return (a1-'A')*2+(a2=='+'?0:1);
}
void link(char a1,char a2,char b1,char b2){
    if(a1=='0'||b1=='0') return;
    G[getId(a1,a2)^1].insert(getId(b1,b2));
}
bool dfs(int u){
    vis[u]=-1;
    for(int v:G[u])
        if(vis[v]==-1||(!vis[v]&&dfs(v))) return true;
    vis[u]=1;
    return false;
}
bool topo(){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<52;i++) if(!vis[i])
        if(dfs(i)) return true;
    return false;
}

int main(){
    int n;
    string s;
    while(cin>>n){
        G.clear();G.resize(52);
        while(n--){
            cin>>s;
            for(int i=0;i<4;i++) for(int j=0;j<4;j++){
                if(i!=j) link(s[i*2],s[i*2+1],s[j*2],s[j*2+1]);
            }
        }
        printf("%s\n",topo()?"unbounded":"bounded");
    }
    return 0;
}