#include<bits/stdc++.h>
using namespace std;
const int N=50*100000; //二维数组字典树的最最最大层数，甚至没有考虑重复的共同前缀
const int M=50; //斐波那契数的最大储存前缀
int trie[N][10],pos[N],cnt=0; //字典树本体，最小出现位置，cnt为当前树的层数
int a[2][52]={{1},{1}}; //用两个数组储存两个斐波那契数（尾巴为大端）
void ins(int* s,int _pos){ //用数组向字典树中储存出现位置
    int p=0,i=M,t; //p为树的层数，i为斐波那契数位在数组中的位置
    while(!s[i]) i--; //找到数的头
    for(;i>=0;i--){ //遍历
        t=s[i];
        if(!trie[p][t]) trie[p][t]=++cnt; //未储存过该序列，添加记录
        p=trie[p][t];
        if(pos[p]==-1) pos[p]=_pos; //未出现过该序列时记录 
    }
}
int fin(char* s){ //用字符串寻找字典树的记录
    int p=0,t;
    for(int i=0;s[i];i++){
        t=s[i]-'0';
        if(!trie[p][t]) return -1; //字典树中没有该序列返回-1
        p=trie[p][t]; //继续向下寻找
    }
    return pos[p];
}
void del(int* s) { //数组左移一位，实际上是给数组代表的数向左移一位
    for(int i=0;i<=M;i++) s[i]=s[i+1];
}
int main(){
    //memset(trie,0,sizeof(trie));
    memset(pos,-1,sizeof(pos)); //位值初始化为-1
    ins(a[0],0); //第0，1的值都是1，记录最小值0就够了
    for(int i=2;i<100000;i++){
        if(a[0][M]||a[1][M]) del(a[0]),del(a[1]); //当有斐波那契数出现超过50位的数时，左移一位
        int now =i&1; //当前修改的数组号(以i的奇偶为参照，交替循环)
        for(int j=0;j<M;j++){
            a[now][j]+=a[1-now][j]; //加上另一个数组的值
            a[now][j+1]+=a[now][j]>=10; //算进位
            a[now][j]%=10;
        }
        ins(a[now],i);
    }
    int T;
    char s[50];
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%s",s);
        printf("Case #%d: %d\n",i,fin(s));
    }
    return 0;
}