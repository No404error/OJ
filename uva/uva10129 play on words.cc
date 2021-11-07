#include<bits/stdc++.h>
using namespace std;
int de[30][2]; //先出度，后入度
bool G[30][30],vis[30]; //G是连通矩阵，vis是访问
char s[1005];
void dfs(int u){ //dfs
    vis[u]=true;
    for(int i=0;i<26;i++){
        if(!vis[i]&&(G[u][i]||G[i][u])) dfs(i);
    }
    return;
}
bool connect(){ //测试连通性
    for(int i=0;i<26;i++) if(de[i][0]>0){
        dfs(i);
        break;
    }
    for(int i=0;i<26;i++){
        if((de[i][0]>0||de[i][1]>0)&&!vis[i]) return false; //出现不连通情况
    }
    return true;
}
bool deg(){ //度数是否正确
    int st=0,en=0;
    for(int i=0;i<26;i++){
        if(de[i][0]!=de[i][1]){ //入度与出度不同
            if(de[i][0]==de[i][1]+1) st++; //出度大入度1个，为起点
            else if(de[i][0]+1==de[i][1]) en++; //出度小入度1个，为终点
            else return false; //不成立
        }
        if(st>1||en>1) return false; //起点，终点数量超额了
    }
    return true;
}
int main(){
    int T,t,fir,las;scanf("%d",&T);while(T--){
        scanf("%d",&t);
        memset(de,0,sizeof(de));
        memset(G,false,sizeof(G));
        memset(vis,false,sizeof(vis));
        while(t--) { //输入
            scanf("%s",s);
            fir=s[0]-'a',las=s[strlen(s)-1]-'a';
            de[fir][0]++,de[las][1]++; //入度和出度调整
            if(!G[fir][las]) G[fir][las]=true; //连通矩阵
        }
        if(connect()&&deg()) //输出
         printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}