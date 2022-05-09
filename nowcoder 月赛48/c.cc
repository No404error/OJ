#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<int> L[maxn],R[maxn];
pii now;
void in(int u){
    if(u>5e6) return;
    now.first+=(ll)L[u].size();
    for(int i=0;i<L[u].size();i++) now.second+=(ll)L[u][i];
    return;
}
void out(int u){
    if(u>5e6) return;
    now.first-=(ll)R[u].size();
    for(int i=0;i<R[u].size();i++) now.second-=(ll)R[u][i];
    return;
}
int main(){
    int n,len,l,r;
    scanf("%d%d",&n,&len);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        L[l].push_back(i);
        R[r].push_back(i);
    }
    now={0,0};
    for(int i=1;i<=len;i++) in(i);
    pii maxs=now;
    int ans=1;
    for(int i=2;i+len-1<=5e6;i++){
        out(i-1);
        in(len+i-1);
        if(maxs<now) maxs=now,ans=1;
        else if(maxs==now) ans++;
    }
    printf("%d\n",ans);
    return 0;
}