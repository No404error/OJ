#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
//本题使用了变换思想，即将处于相同状态的点合为一块，即离散化
//还有逆向思维，求块不易，去求空气
const int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}}; //6个方向
const int N=55; //组号
const int X=1001; //坐标范围
int sx[N],sy[N],sz[N],ex[N],ey[N],ez[N]; //原始坐标
int sxt,ext,syt,eyt,szt,ezt; //变换中坐标
int dx[N*2],dy[N*2],dz[N*2],G[N*2][N*2][N*2]; //变换后坐标
void sorts(int* a,int& len){ //排序并返回排序去重的长度
    sort(a,a+len);
    len=unique(a,a+len)-a;
}
int getId(int* a,int len,int val){ //返回值在数组的位置
    return lower_bound(a,a+len,val)-a;
}
struct bc{ //矩形块
    int x,y,z;
    bc(int a,int b,int c):x(a),y(b),z(c){};
};
int main(){
    int T,t,lx,ly,lz,tx,ty,tz;scanf("%d",&T);while(T--){ 
        memset(G,0,sizeof(G));
        scanf("%d",&t);
        dx[0]=dy[0]=dz[0]=0;
        dx[1]=dy[1]=dz[1]=X;
        lx=ly=lz=2;
        for(int i=0;i<t;i++){ //输入t个块
            scanf("%d%d%d%d%d%d",&sx[i],&sy[i],&sz[i],&tx,&ty,&tz); //先是左下坐标，然后是偏移量
            ex[i]=sx[i]+tx;ey[i]=sy[i]+ty;ez[i]=sz[i]+tz; //再记录右上的坐标
            //将左下和右上坐标装在d数组里，将要变换
            dx[lx++]=sx[i];dx[lx++]=ex[i];dy[ly++]=sy[i];dy[ly++]=ey[i];dz[lz++]=sz[i];dz[lz++]=ez[i];
        }
        sorts(dx,lx);sorts(dy,ly);sorts(dz,lz); //对d数组排序，得到独立的节点值
        for(int i=0;i<t;i++){ //给变换后的空间标记状态
            //得到当前块在变换中的位置信息
            sxt=getId(dx,lx,sx[i]);ext=getId(dx,lx,ex[i]);syt=getId(dy,ly,sy[i]);eyt=getId(dy,ly,ey[i]);szt=getId(dz,lz,sz[i]);ezt=getId(dz,lz,ez[i]);
            for(int i=sxt;i<ext;i++) for(int j=syt;j<eyt;j++) for(int k=szt;k<ezt;k++){
                //将块标记为状态1
                G[i][j][k]=1;
            }
        }
        int vol=0,area=0; //体积和面积
        queue<bc> q;
        q.push(bc(0,0,0));
        G[0][0][0]=2; //标记为2，表示已经访问过
        while(!q.empty()){
            bc u=q.front();q.pop();
            vol+=(dx[u.x+1]-dx[u.x])*(dy[u.y+1]-dy[u.y])*(dz[u.z+1]-dz[u.z]); //空气体积
            for(int i=0;i<6;i++){
                tx=u.x+dir[i][0];ty=u.y+dir[i][1];tz=u.z+dir[i][2]; //计算相邻块
                if(tx<0||ty<0||tz<0||tx>=lx-1||ty>=ly-1||tz>=lz-1) continue; //越界
                if(G[tx][ty][tz]==1){ //相邻块不是空气，需要计算面积
                    if(dir[i][0]) area+=(dy[u.y+1]-dy[u.y])*(dz[u.z+1]-dz[u.z]); //x向，计算y*z，类推
                    if(dir[i][1]) area+=(dx[u.x+1]-dx[u.x])*(dz[u.z+1]-dz[u.z]); 
                    if(dir[i][2]) area+=(dx[u.x+1]-dx[u.x])*(dy[u.y+1]-dy[u.y]);
                } 
                else if(G[tx][ty][tz]==0){ //相邻块是空气，放入队列
                    G[tx][ty][tz]=2;
                    q.push(bc(tx,ty,tz));
                }
            }
        }
        vol=X*X*X-vol;
        printf("%d %d\n",area,vol);
    }
    return 0;
}