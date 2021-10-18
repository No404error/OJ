#include<bits/stdc++.h>
using namespace std;
const int maxn=100050;
int n,m,kase=0,op,a,b;
int rig[maxn],lef[maxn];
void link(int L,int R){ //把L和R节点相连
    rig[L]=R;lef[R]=L;
}
int main(){
    while(scanf("%d%d",&n,&m)==2){ //输入
        for(int i=1;i<=n;i++) {
            lef[i]=i-1; //左减一
            rig[i]=(i+1)%(n+1); //右需要加一，到了尽头要归零
        }
        rig[0]=1,lef[0]=n; //初始化0
        int inv=0; //inv放在内层里，每次都为0
        while(m--){
            scanf("%d",&op); 
            if(op==4) inv=!inv; //记录反转次数
            else{
                scanf("%d%d",&a,&b);
                if(op==3&&rig[b]==a) swap(a,b); //将反转的一种相邻关系转为另一种（为统一），后续可以用一个表达式表示两种情况
                if(op!=3&&inv) op=3-op; //操作反转
                if(op==1&&a==lef[b]) continue; //无需操作的情况
                if(op==2&&a==rig[b]) continue;
                int La=lef[a],Ra=rig[a],Lb=lef[b],Rb=rig[b]; //预先设置
                if(op==1){
                    link(La,Ra);link(Lb,a);link(a,b); //a左右相接，a再置于b左和b之间
                } 
                else if(op==2){
                    link(La,Ra);link(b,a);link(a,Rb); //a左右相接，a再置于b右和b之间
                }
                else if(op==3){
                    if(rig[a]==b) {link(La,b);link(b,a);link(a,Rb);} //相邻情况下，a左与b相接，b与a相接，a与b右相接
                    else {link(La,b);link(b,Ra);link(Lb,a);link(a,Rb);} //不相邻，a置于b右和b左之间，b置于a左和a右之间
                } 
            }
        }
        int i=0;
        long long ans=0;
        for(int j=1;j<=n;j++){ //计算奇数和
            i=rig[i]; 
            if(j&1) ans+=i;
        } //当总数为奇数个数时奇数和等于反转后的奇数和，偶数还反转时需要求奇数和的补数
        printf("Case %d: %lld\n",++kase,(inv&&!(n&1))?(long long)n*(n+1)/2-ans:ans); 
    }
    return 0;
}