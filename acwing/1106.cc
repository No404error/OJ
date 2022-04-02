#include<iostream>
#include<queue>
using namespace std;
const int maxn=1000+2;
const int dx[]={-1,1,0,0,-1,1,1,-1};
const int dy[]={0,0,-1,1,-1,1,-1,1};
int buf[maxn][maxn];
bool vis[maxn][maxn];
bool up,down;
int res1,res2,N;
void dfs(int x,int y,int h){
    if(buf[x][y]!=h||vis[x][y]){
        if(buf[x][y]>h) up=true;
        else if(buf[x][y]<h) down=true;
        return;
    }
    vis[x][y]=true;
    for(int i=0;i<8;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||nx>=N||ny<0||ny>=N) continue;
        dfs(nx,ny,h);
    }
    return;
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%d",&buf[i][j]);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(!vis[i][j]){
        up=false;down=false;
        dfs(i,j,buf[i][j]);
        if(!up) res1++;
        if(!down) res2++;
    }
    printf("%d %d",res1,res2);
    return 0;
}