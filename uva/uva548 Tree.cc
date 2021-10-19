#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int in_order[maxn],post_order[maxn],lch[maxn],rch[maxn],ans,anst,n;
bool read(int* a){ //读操作，向数组中写入节点值
    string s;
    if(!getline(cin,s)) return false; //没有可读的行,返回false
    stringstream ss(s); //写入值
    for(n=0;ss>>a[n];n++);
    return true; 
}
int build(int L1,int R1,int L2,int R2){
    if(L1>R1) return 0; //空树就返回
    int root=post_order[R2];
    int p=L1; 
    while(in_order[p]!=root) p++; //寻找root位置
    int cnt=p-L1;//左子树的节点数
    lch[root]=build(L1,p-1,L2,L2+cnt-1); //建左子树
    rch[root]=build(p+1,R1,L2+cnt,R2-1); //建右子树
    return root;
}
void dfs(int u,int sum){
    sum+=u;
    if(!rch[u]&&!lch[u]){ //到达叶子
        if(ans>sum||(ans==sum&&anst>u)) {ans=sum;anst=u;}
    }
    if(rch[u]) dfs(rch[u],sum);
    if(lch[u]) dfs(lch[u],sum);
}
int main(){
    while(read(in_order)){
        read(post_order);
        build(0,n-1,0,n-1);
        ans=INT_MAX;
        dfs(post_order[n-1],0);
        cout<<anst<<endl;
    }
    return 0;
}