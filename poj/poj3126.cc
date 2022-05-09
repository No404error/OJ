#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=10000;
int prime[maxn];
bool primes[maxn];
int vis[maxn];
void getprime(int n){
    memset(prime,0,n);
    for(int i=2;i<=n;i++){
        if(!primes[i]) prime[++prime[0]]=i;
        for(int j=1,t;j<=prime[0];j++){
            if((t=prime[j]*i)>n) break;
            primes[t]=1;
            if(i%prime[j]==0) break;
        } 
    }
}
int bfs(int start,int end){
    if(start==end) return 0;
    int lis[4];
    int pow[]={1,10,100,1000};
    int now,cmp;
    queue<int> q;
    q.push(start);
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        now=cmp=q.front();q.pop();
        for(int i=0;i<4;i++){
            lis[i]=cmp%10;cmp/=10;
        }
        for(int i=0;i<4;i++){
            cmp=now-lis[i]*pow[i];
            for(int j=0;j<10;j++,cmp+=pow[i]){
                if(i==3&&j==0||cmp==start) continue;
                if(!vis[cmp]&&!primes[cmp]) {
                    vis[cmp]=vis[now]+1;
                    if(cmp==end) return vis[cmp];
                    q.push(cmp);
                }
            }
        }
    }
    return -1;
}
int main(){
    getprime(10000);
    int T;scanf("%d",&T);while(T--){
        int st,en,ans;
        scanf("%d%d",&st,&en);
        ans=bfs(st,en);
        if(ans==-1) printf("Impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}