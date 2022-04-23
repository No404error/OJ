#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> sons[maxn];
int T;
int dp(int s){
    if(sons[s].size()==0) return 1;
    int k=sons[s].size();
    vector<int> d;
    for(int i=0;i<k;i++) d.push_back(dp(sons[s][i]));
    sort(d.begin(),d.end());
    int c=(k*T-1)/100+1;
    int res=0;
    for(int i=0;i<c;i++) res+=d[i];
    return res;
}

int main(){
    int n,t;
    while(~scanf("%d%d",&n,&T)&&n){
        for(int i=0;i<=n;i++) sons[i].clear();
        for(int i=1;i<=n;i++) {
            scanf("%d",&t);
            sons[t].push_back(i);
        }
        printf("%d\n",dp(0));
    }
    return 0;
}