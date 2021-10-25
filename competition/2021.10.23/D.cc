#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,mi,la,ans;
int T;
int main(){
    cin>>T;while(T--){
        ans=0;
        scanf("%lld%lld%lld%lld",&n,&m,&x,&y); //输入
        n--,m--; //步数
        mi=min(n,m); //找出最小值
        la=abs(n-m); //找出差值
        if(mi==0) ans=la*x; //列为1，一步一步走
        else if(y>=2*x) ans=(n+m)*x; //y>=2x 斜着走不如走左下走两步，那就全都一步一步来
        else if(y>=x) ans=mi*y+la*x; //x<=y<2x 先斜着走到头，在一步一步来
        else if(la&1) ans =x+(mi+la-1)*y; //y<x 先斜着走到头，还想跳两步，需要看差值的奇偶
        else ans=(la+mi)*y; //偶数 就全跳着来，奇数 就剩一步正常走，其他跳着来
        printf("%lld\n",ans);
    }
    return 0;
}