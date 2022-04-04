#include <iostream>
#include <cstring>
using namespace std;
const int maxn=10;
int pos[maxn];
int n;

bool ok(){
    for(int i=1;i<=n;i++) if(pos[i]!=i) return false;
    return true;
}
inline int hs(){
    int cnt=0;
    for(int i=1;i<n;i++) if(pos[i+1]!=pos[i]+1) cnt++;
    return cnt;
}

bool dfs(int h,int maxh){
    if(3*h+hs()>3*maxh) return false;
    if(ok()) return true;
    int npos[maxn],least[maxn];
    memcpy(npos,pos,sizeof(int)*maxn);

     for(int i=1;i<=n;i++) for(int j=i;j<=n;j++){
         int cnt=1;
         for(int k=1;k<=n;k++) if(k<i||k>j) least[cnt++]=npos[k];
         for(int k=0;k<cnt;k++) {
             int cnt2=1;
             for(int g=1;g<=k;g++) pos[cnt2++]=least[g];
             for(int g=i;g<=j;g++) pos[cnt2++]=npos[g];
             for(int g=k+1;g<cnt;g++) pos[cnt2++]=least[g];
             if(dfs(h+1,maxh)) return true;
         }
     }
    return false;
}

int solve(){
    if(ok()) return 0;
    for(int res=1;res<9;res++)
        if(dfs(0,res)) return res;
    return 8;
}

int main(){
    int kase=1;
    while(scanf("%d",&n)==1&&n){
        for(int i=1;i<=n;i++) scanf("%d",&pos[i]);
        printf("Case %d: %d\n",kase++,solve());
    }
    return 0;
}