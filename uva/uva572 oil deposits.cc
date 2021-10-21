#include<bits/stdc++.h> //dfs求连通块
using namespace std;
const int maxn=105;
char buf[maxn][maxn]; //存放字符串
int idx[maxn][maxn],m,n,cnt; //记录图上各点的状态
void dfs(int x,int y,int id){ 
    if(x<0||x>m||y<0||y>n) return; //越界
    if(idx[x][y]>0||buf[x][y]!='@') return; //当前位置被赋值或不是有效位置
    idx[x][y]=id; 
    for(int dx=-1;dx<=1;dx++) for(int dy=-1;dy<=1;dy++) { //向四周蔓延
        if(dx!=0||dy!=0) dfs(x+dx,y+dy,id);
    }
}
int main(){
    while(scanf("%d%d",&m,&n)==2&&m){
        for(int i=0;i<m;i++) scanf("%s",buf[i]); //输入
        memset(idx,0,sizeof(idx)); //记录置零
        cnt=0; //计数器归零
        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
            if(!idx[i][j]&&buf[i][j]=='@') dfs(i,j,++cnt); //逐个位置试探
        printf("%d\n",cnt);
    }
    return 0;
}