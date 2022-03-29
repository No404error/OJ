#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int maxn=6;

struct Tree{
    double r,l;
};

int T,s;
double maxs;
double w[maxn],sum[1<<maxn];
//记录i的子集
vector<Tree> tree[1<<maxn];
//记录
bool vis[1<<maxn];

void dfs(int set){
    if(vis[set]) return;
    vis[set]=true;
    int left,right;
    //base case
    if(((set-1)&set)==0) {
        tree[set].push_back(Tree{});
        return;
    }

    for(left=(set-1)&set;left>0;left=(left-1)&set){
        right=set^left;
        dfs(right);dfs(left);
        double dl=sum[right]/sum[set];
        double dr=sum[left]/sum[set];
        for(auto tr:tree[right]) for(auto tl:tree[left]){
            Tree t;
            t.r=max(tr.r+dr,tl.r-dl);
            t.l=max(tl.l+dl,tr.l-dr);
            if(t.r+t.l<maxs) tree[set].push_back(t);
        }
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        scanf("%lf %d",&maxs,&s);
        for(int i=0;i<s;i++)    scanf("%lf",&w[i]);
        for(int i=0;i<(1<<s);i++){
            tree[i].clear();
            sum[i]=0;
            for(int j=0;j<s;j++) if(i&(1<<j)) sum[i]+=w[j];
        }
        int root=(1<<s)-1;
        dfs(root);
        double ans=-1;
        for(auto tre:tree[root]) ans=max(tre.l+tre.r,ans);
        if(ans+1<1e-5) printf("-1\n");
        else printf("%.16lf\n",ans);
    }
    return 0;
}