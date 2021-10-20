#include<bits/stdc++.h>
using namespace std;
const int maxn=1000; 
int sumt[maxn];
void build(int p){ //建树
    int t;cin>>t;
    if(t==-1) return; //无树
    sumt[p]+=t; //添加值
    build(p-1);build(p+1); //建左子树和右子树
}
bool init(){ 
    int t;cin>>t;
    if(t==-1) return false; //-1为结束条件
    memset(sumt,0,sizeof(sumt)); //重置
    int pos=maxn/2; //合理利用内存
    sumt[pos]=t; //根
    build(pos-1);build(pos+1); //左子树和右子树
    return true;
}
int main(){
    int kase=1,p;
    while(init()){
        p=0;
        while(!sumt[p]) p++;
        cout<<"Case "<<kase++<<":\n"<<sumt[p++];
        while(sumt[p]!=0) cout<<" "<<sumt[p++];
        cout<<"\n\n";
    }
    return 0;
}