#include<bits/stdc++.h>
using namespace std;
const int maxn=102;
bool G[maxn][maxn]; //邻接表
int c[maxn],topo[maxn],t;
int n,m,x,y;
bool dfs(int u){
    c[u]=-1; //正在访问
    for(int v=1;v<=n;v++) if(G[u][v]) {
        if(c[v]<0) return false; //存在有向环
        else if(!c[v]&&!dfs(v)) return false; //向下dfs
    }
    c[u]=1; //访问完成 
    topo[t--]=u; //置后 所以是优先级小的在后
    return true;
}
bool toposort(){
    t=n;
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++) if(!c[i]) 
        if(!dfs(i)) return false;
    return true;
}
int main(){
    while(cin>>n>>m&&n){
        memset(G,false,sizeof(G));
        for(int i=0;i<m;i++){ //输入
            cin>>x>>y;
            G[x][y]=true;
        }
        toposort(); //排序
        int i=1;
        cout<<topo[i++];  //输出
        for(;i<=n;i++){
            cout<<" "<<topo[i];
        }
        cout<<endl;
    }
    return 0;
}