#include<iostream>
#define black 2
#define white 1
#define none 0
using namespace std;
int list[9][9];    
int v[9][9];
int n;
int res=0;
bool available(int x,int y,int color){
    if(!list[x][y]) return false;
    // int color=v[x][y];
    for(int i=x-1;i>0;i--) if(color==v[i][y]) return false; //x向
    for(int i=1;x-i>0&&y-i>0;i++) if(color==v[x-i][y-i]) return false; //左上
    for(int i=1;x-i>0&&y+i<=n;i++) if(color==v[x-i][y+i]) return false; //右上
    return true;
}
void dfs(int floor){
    if(floor==n+1) {
        res++;
        return;
    }

    for(int bpos=1;bpos<=n;bpos++)
        for(int wpos=1;wpos<=n;wpos++){
            if(bpos==wpos) continue;
            if(available(floor,bpos,black)&&available(floor,wpos,white)){
                v[floor][bpos]=black,v[floor][wpos]=white;
                dfs(floor+1);
                v[floor][bpos]=none,v[floor][wpos]=none;
            }
        }

    return;
}
int main(){

    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>list[i][j];
    
    dfs(1);
    printf("%d",res);
    return 0;
}