#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,t;
void update(vector<int>& inde,queue<int>& q){
    for(int i=1;i<=n;i++){
        if(!inde[i]){ //入度为零
            q.push(i);
            inde[i]=-1;//已访问
        }
    }
}
int main(){
    while(cin>>n>>m&&n){
        vector<vector<int>> adj(n+1); //邻接矩阵
        vector<int> inde(n+1),ans; //入度和答案
        for(int i=0;i<m;i++){ //输入
            cin>>x>>y;
            inde[y]++;
            adj[x].push_back(y);
        }
        queue<int> q; update(inde,q); //初始化
        while (!q.empty()){
            t=q.front(); q.pop(); ans.push_back(t);
            for(int v:adj[t]) inde[v]--; //减少相邻的节点的入度
            update(inde,q); //重置队列
        }
        for(int i=0;i<ans.size();i++) printf("%s%d",i?" ":"",ans[i]);
        puts("");
    }
    return 0;
}