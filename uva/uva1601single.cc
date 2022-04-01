#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=20+2;
const int maxm=200+5;

//原地图
char buf[maxn][maxn];

//稀疏图
int G[maxm][5]; 

//地图规模
int w,h,n;

//由原地图转为稀疏矩阵的条件:节点个数,节点对应原图的x,y坐标,原图节点对应id,节点对应出度
int cnt,x[maxm],y[maxm],id[maxn][maxn],deg[maxm];

//距离数组
int dis[maxm][maxm][maxm];

//起点终点的位置组
int s[3],t[3];

//偏移量,包括自己
const int dx[]={-1,1,0,0,0};
const int dy[]={0,0,-1,1,0};

//encoding
inline int ID(int a,int b,int c){
    return (a<<16)|(b<<8)|c;
}
inline bool conflict(int a,int b,int a1,int b1){
    return ((a1==b1)||(a==b1&&b==a1));
}

int bfs(){
    int u,a,b,c,a1,b1,c1;
    queue<int> q;
    q.push(ID(s[0],s[1],s[2]));
    dis[s[0]][s[1]][s[2]]=0;
    while (!q.empty())
    {
        u=q.front();q.pop();

        //decoding
        a=(u>>16)&255;b=(u>>8)&255;c=u&255;

        //base case
        if(a==t[0]&&b==t[1]&&c==t[2]) return dis[a][b][c];

        for(int i=0;i<deg[a];i++){
            a1=G[a][i];
            for(int j=0;j<deg[b];j++){
                b1=G[b][j];
                if(conflict(a,b,a1,b1)) continue;
                for(int k=0;k<deg[c];k++){
                    c1=G[c][k];
                    if(conflict(a,c,a1,c1)||conflict(b,c,b1,c1)) continue;

                    if(dis[a1][b1][c1]==-1){
                        dis[a1][b1][c1]=dis[a][b][c]+1;
                        q.push(ID(a1,b1,c1));
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    while (scanf("%d%d%d\n",&w,&h,&n)&&n)
    {
        for(int i=0;i<h;i++) fgets(buf[i],20,stdin);

        //初始化变量
        cnt=0;
        memset(dis,-1,sizeof(dis));
        
        //记录节点
        for(int i=0;i<h;i++) for(int j=0;j<w;j++) if(buf[i][j]!='#') {
            x[cnt]=i,y[cnt]=j,id[i][j]=cnt;
            if(islower(buf[i][j])) s[buf[i][j]-'a']=cnt;
            else if(isupper(buf[i][j])) t[buf[i][j]-'A']=cnt;
            cnt++;
        }
        
        //由节点填充关系
        for(int i=0;i<cnt;i++){
            deg[i]=0;
            for(int j=0;j<5;j++){
                int nx=x[i]+dx[j];
                int ny=y[i]+dy[j];
                if(buf[nx][ny]!='#') G[i][deg[i]++]=id[nx][ny];
            }
        }

        //处理ghost数量问题
        if(n<=2) {deg[cnt]=1;G[cnt][0]=cnt;s[2]=t[2]=cnt++;}
        if(n<=1) {deg[cnt]=1;G[cnt][0]=cnt;s[1]=t[1]=cnt++;}
        printf("%d\n",bfs());
    }
    return 0;
}