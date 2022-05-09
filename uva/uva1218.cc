#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
const int maxt=1e6;
int d[maxn][3];

vector<int> son[maxn];

void dfs(int u,int fa){
    d[u][0]=1;
    d[u][1]=0;

    for(auto v:son[u]) if(v!=fa) dfs(v,u);

    int res=0;

    for(auto v:son[u]) if(v!=fa) res+=min(d[v][0],d[v][1]);
    d[u][0]+=res;
    res=0;

    for(auto v:son[u]) if(v!=fa) res+=d[v][2];
    d[u][1]+=res;

    res=maxt;
    for(auto v:son[u]) if(v!=fa) res=min(res,d[u][1]-d[v][2]+d[v][0]);
    d[u][2]=res;
}

int main(){
    int N,end;
    int a,b;
    while(~scanf("%d",&N)){
        for(int i=1;i<=N;i++) son[i].clear();
        for(int i=1;i<N;i++) {
            scanf("%d%d",&a,&b);
            son[a].push_back(b);
            son[b].push_back(a);
        }
        dfs(1,-1);
        printf("%d\n",min(d[1][0],d[1][2]));

        scanf("%d",&end);
        if(end==-1) break;
    }
    return 0;
}