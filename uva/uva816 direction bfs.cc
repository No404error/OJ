#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=10;
const char* dirs="NESW";
const char* turns="FLR";
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
char name[25];
struct node{
    int x,y,dir;
    node(int a,int b,int c):x(a),y(b),dir(c){};
    node():x(0),y(0),dir(0){};
};
bool vis[maxn][maxn][4][3];
int d[maxn][maxn][4];
node p[maxn][maxn][4];
int x0,y0,x1,y1,dr1,x2,y2,dr2;
int dir_id(char c) {return strchr(dirs,c)-dirs;} //相当于由字符到数的映射
int turn_id(char c) {return strchr(turns,c)-turns;}
bool input_dot(){ //输入迷宫信息
    int x,y,n,dir,turn;
    char s[10];
    scanf("%d",&x); //迷宫节点的x,y值
    if(!x) return false; //为零该迷宫输入完成
    scanf("%d",&y);  
    while(scanf("%s",s)&&s[0]!='*'){ //为'*'时结束
        n=strlen(s);
        dir=dir_id(s[0]);
        for(int i=1;i<n;i++){
            vis[x][y][dir][turn_id(s[i])]=true; //给通路做上标记
        }
    }
    return true;
}
node walk(const node& u,int turn){ //前进
    int dir=u.dir; 
    if(turn==1) dir=(dir+3)%4; //为L，向左，考虑到加-1可能会出现负数，那么加(-1+4)就很不错
    if(turn==2) dir=(dir+1)%4; //为R，向右，加1就行
    return node(u.x+dx[dir],u.y+dy[dir],dir);
}
void print(node u){ //输出格式
    vector<node> v;
    for(;;){ //先遍历到起点(x1,y1)
        v.push_back(u);
        if(d[u.x][u.y][u.dir]==0) break; //到达起点就结束
        u=p[u.x][u.y][u.dir]; //回溯
    }
    v.push_back(node(x0,y0,dr1)); //把(x0,y0)放入
    for(int i=1,now;i<=v.size();i++){ 
        now=v.size()-i; //逆向读取
        if(i%10==1) printf("  (%d,%d)",v[now].x,v[now].y); //行首有两个空格
        else printf(" (%d,%d)",v[now].x,v[now].y); //其他有一个空格
        if(i%10==0) printf("\n"); //行尾有换行
    }
    if(v.size()%10) printf("\n"); //不是行尾就换行
}
bool inside(int x,int y){
    return x>=1&&x<=9&&y>=0&&y<=9;
}
void bfs(){
    queue<node> q;
    memset(d,-1,sizeof(d)); //初始化为-1
    x1=x0+dx[dr1];y1=y0+dy[dr1]; //因为题中指定了起点的移动方向，所以不能把起点的所有移动方向全加入队列，故不可把(x0,y0)加入队列
    node u(x1,y1,dr1);
    d[x1][y1][dr1]=0; //初始化值为0，而不是代表未访问值的-1
    q.push(u); 
    while(!q.empty()){
        u=q.front();q.pop();
        if(u.x==x2&&u.y==y2) {print(u);return;} //到达终点就输出，并返回
        for(int i=0;i<3;i++){ //三种方向
            node v=walk(u,i);
            if(vis[u.x][u.y][u.dir][i]&&inside(v.x,v.y)&&d[v.x][v.y][v.dir]<0) { 
            //只有u： 能通过该方向进入v，v还在图中且v不曾被访问过
                d[v.x][v.y][v.dir]=d[u.x][u.y][u.dir]+1; //步数增加1
                p[v.x][v.y][v.dir]=u; //记录节点的前驱
                q.push(v);
            }
        }
    }
    printf("  No Solution Possible\n"); //无解，有两个空格
}

int main(){
    while(scanf("%s",name)&&strcmp("END",name)){
        char tmp;
        scanf("%d%d",&x0,&y0); //先行输入x0,y0
        getchar(); //吸收空格
        scanf("%c",&tmp); //输入字符
        dr1=dir_id(tmp); 
        scanf("%d%d",&x2,&y2);//再输入x2,y2
        memset(vis,false,sizeof(vis)); //清理vis数组
        while(input_dot()); //输入vis数据
        printf("%s\n",name); //输出名字
        bfs(); //遍历
    }
    return 0;
}