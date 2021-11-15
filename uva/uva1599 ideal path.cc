#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
struct Edge{
    int u,v,c;
    Edge(int u,int v,int c):u(u),v(v),c(c){};
};
vector<Edge> edge; //存边
vector<int> G[maxn]; //存关系
int d[maxn]; //与目标的距离
bool vis[maxn]; //访问标记
int n,m,a,b,c,u,v,minc;
inline int get(int G_s,int edge_s){ //得到图节点的后继节点
    return edge[edge_s].u==G_s? edge[edge_s].v:edge[edge_s].u;
}
void revbfs(){ //求最小距离
    memset(d,0,sizeof(d)); memset(vis,false,sizeof(vis)); //bfs初始化
    queue<int> q;
    q.push(n);vis[n]=true; //终点入队
    while(!q.empty()){
        u=q.front();q.pop(); //队首出队
        for(int e:G[u]){ //遍历u的后继
            v=get(u,e); //获得后继节点
            if(!vis[v]){ //给未访问的节点更新状态
                d[v]=d[u]+1; //距离
                vis[v]=true; //访问过
                q.push(v);//入队
            }
        }
    }
}
void bfs(){ //寻找最小字典序路径
    memset(vis,false,sizeof(vis));
    printf("%d\n",d[1]);
    vector<int> ans,pray{1},prayt;
    for(int i=d[1];i>0;i--){
        minc=INT_MAX;
        for(int u:pray){ //层次遍历
            for(int e:G[u]){ //遍历边
                v=get(u,e); //获得后继节点
                if(d[u]==d[v]+1&&minc>=edge[e].c) minc=edge[e].c; //寻找最小颜色
            }
        }
        ans.push_back(minc);
        prayt.clear();
        for(int u:pray){ //层次遍历
            for(int e:G[u]){ //遍历边
                v=get(u,e); //获得后继节点
                if(d[u]==d[v]+1&&!vis[v]&&minc==edge[e].c){ //给最小颜色点标记为访问过
                    vis[v]=true;
                    prayt.push_back(v);
                }
            }
        }
        pray=prayt;
    }
    for(int i=0;i<ans.size();i++) printf("%d%s",ans[i],i==ans.size()-1?"\n":" ");
}
int main(){
    while(scanf("%d%d",&n,&m)==2){
         edge.clear(); fill(G,G+maxn,vector<int>{}); //初始化
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            if(a==b) continue;
            G[a].push_back(edge.size());
            G[b].push_back(edge.size());
            edge.push_back({a,b,c});
        }
        revbfs();
        bfs();
    }
    return 0;
}