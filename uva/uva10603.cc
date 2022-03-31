#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

const int maxn=201;
int a,b,c,d;
struct Node
{
    int v[3],dist;
    bool operator<(const Node& u) const {
        return dist>u.dist;
    }
};
int ans[maxn],cup[3];
bool vis[maxn][maxn];

void update(const Node& u){
    for(int i=0;i<3;i++){
        int d=u.v[i];
        if(ans[d]<0||u.dist<ans[d]) ans[d]=u.dist;
    }
}

void bfs(){
    cup[0]=a,cup[1]=b,cup[2]=c;
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    priority_queue<Node> q;

    Node start;
    start.dist=0;start.v[0]=0;start.v[1]=0;start.v[2]=c;
    q.push(start);
    vis[0][0]=true;

    Node u,u2;
    while (!q.empty())
    {
        u=q.top();q.pop();
        update(u);
        if(ans[d]>=0) break;

        //规定倒水流程为i杯向j杯倒
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i!=j){
            if(!u.v[i]||u.v[j]==cup[j]) continue;
            int dis=min(cup[j]-u.v[j],u.v[i]);
            memcpy(&u2,&u,sizeof(u));
            u2.dist+=dis;u2.v[i]-=dis;u2.v[j]+=dis;
            
            if(vis[u2.v[0]][u2.v[1]]) continue;
            vis[u2.v[0]][u2.v[1]]=true;
            q.push(u2);
        }
    }
    while (true)
    {
        if(ans[d]>=0){
            printf("%d %d\n",ans[d],d);
            return;
        }
        d--;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        bfs();
    }
    return 0;
}