#include<bits/stdc++.h> 
using namespace std;
const int len=32; //其实这题可以用一颗带有层次信息的树来表示，在数据量更大的时候效率会比直接绘图效率要高
const int maxn=2000; //但是绘图的书写复杂度低（很难想），更加直接，刘神yyds
int gra[len][len],cnt; //很多树的问题在没有明确规定需要建树时都可以用递归的过程来表述
char s[maxn]; //关于maxn还要考虑灰色值的空间,所以要开大一点
void draw(int& p,int x,int y,int w){ //记录图上某块的黑像素的数量
    char ch=s[p++]; //取出一个指令
    if(ch=='p'){ //四分画图
        draw(p,x,y+w/2,w/2); //右上
        draw(p,x,y,w/2); //左上
        draw(p,x+w/2,y,w/2); //左下
        draw(p,x+w/2,y+w/2,w/2); //右下
    }
    else if(ch=='f'){ //全黑就开画
        for(int i=x;i<x+w;i++) for(int j=y;j<y+w;j++){
            if(!gra[i][j]) {gra[i][j]=1;cnt++;} //边画边记录
        }
    }
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        memset(gra,0,sizeof(gra)); //清理记录
        cnt=0; //计数器归零
        for(int i=0;i<2;i++){
            int p=0;
            scanf("%s",s);
            draw(p,0,0,len); //画两次
        }
        printf("There are %d black pixels.\n",cnt);
    }
    return 0;
}