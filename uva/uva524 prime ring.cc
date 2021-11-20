#include<bits/stdc++.h>
using namespace std;
const int maxn=18; //环中数的上限
bool isp[maxn*2]; //素数表
bool vis[maxn]; //是否被访问过
int cases=1,ans[maxn],n;
bool is_prime(int i){ //是否是素数
    for(int j=2;j*j<=i;j++){
        if(!(i%j)) return false;
    }
    return true;
}
void init_isp(){ //画出素数表
    for(int i=1;i<=maxn*2;i++) isp[i]=is_prime(i);
}
void dfs(int cur){ //回溯法dfs
    if(cur==n+1&&isp[ans[1]+ans[n]]){ //结束条件
        for(int i=1;i<=n;i++) printf("%d%s",ans[i],i==n?"\n":" "); //结尾和其他的分割符不同
    }
    else for(int i=2;i<=n;i++){ //继续向深dfs
        if(!vis[i]&&isp[i+ans[cur-1]]){
            ans[cur]=i;
            vis[i]=true; //做标记
            dfs(cur+1);
            vis[i]=false; //取消标记
        }
    }
}
void test(){ //访问初始化
    memset(vis,false,sizeof(vis));
    ans[1]=1;
    dfs(2);
}
int main(){
    init_isp();
    int t;while(scanf("%d",&t)==1){ //输入至eof
        n=t; //截止位数t
        if(cases!=1) printf("\n"); //输出空行
        printf("Case %d:\n",cases++);
        test(); //dfs
    }
    return 0;
}