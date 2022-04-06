#include<bits/stdc++.h>
using namespace std;
const int maxn=5000+5;
struct line{
    int l,r,id,ans;
};
bool cmp1(line& a,line& b){
    if(a.l==b.l) return a.r<b.r;
    return a.r<b.r;
}
bool cmp2(line& a,line& b){
    return a.id<b.id;
}

int N;
line R[maxn],C[maxn];
bool vis[maxn][2];
int main(){
    int a,b,c,d;
    while(scanf("%d",&N)&&N){
        for(int i=1;i<=N;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            R[i].l=a;R[i].r=c,R[i].id=i;
            C[i].l=b;C[i].r=d,C[i].id=i;  
        }
        sort(R+1,R+N+1,cmp1);sort(C+1,C+N+1,cmp1);
        memset(vis,0,sizeof(vis));
        int i,pos;
        for(i=1;i<=N;i++){
            for(pos=R[i].l;pos<=R[i].r;pos++){
                if(vis[pos][0]) continue;
                vis[pos][0]=true;
                R[i].ans=pos;
                break;
            }
            if(pos>R[i].r) break;

            for(pos=C[i].l;pos<=C[i].r;pos++){
                if(vis[pos][1]) continue;
                vis[pos][1]=true;
                C[i].ans=pos;
                break;
            }
            if(pos>C[i].r) break;
        }

        if(i<=N) printf("IMPOSSIBLE\n");
        else{
            sort(R+1,R+N+1,cmp2);sort(C+1,C+N+1,cmp2);
            for(int i=1;i<=N;i++) printf("%d %d\n",R[i].ans,C[i].ans);
        }
    }
    return 0;
}