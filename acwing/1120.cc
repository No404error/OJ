#include<iostream>
#include<cstring>

using namespace std;

typedef long long LL;
const int maxn=1000;
LL ans[maxn],v[maxn];
int maxd;

bool better(int d){
    for(int i=d;i>=0;i--) if(v[i]!=ans[i]) {
        return ans[i]==-1||ans[i]>v[i];
    }
    return false;
}
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
LL get_first(LL a,LL b){
    return b/a+1;
}
bool dfs(int d,LL from,LL aa,LL bb){

    //base case
    if(d==maxd){
        if(bb%aa||bb>1e7) return false;
        v[d]=bb/aa;
        if(better(d)) memcpy(ans,v,sizeof(LL)*(d+1));
        return true;
    }
    
    bool flag=false;
    from=max(from,get_first(aa,bb));
    for(int i=from;;i++){
        if(bb*(maxd-d+1)<=i*aa) break;
        v[d]=i;
        LL b2=bb*i;
        LL a2=aa*i-bb;
        LL g=gcd(a2,b2);
        if(dfs(d+1,i+1,a2/g,b2/g)) flag=true;
    }
    return flag;
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(maxd=1;;maxd++){
        memset(ans,-1,sizeof(ans));
        if(dfs(0,get_first(a,b),a,b)) break;
    }
    for(int i=0;i<=maxd;i++) printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}