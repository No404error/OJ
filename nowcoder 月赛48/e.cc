#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
set<pii> s;
ll tar;
bool dfs(ll a,ll b){
    if(a<b) swap(a,b);
    if(a==tar||b==tar) return true;
    if(s.count({a,b})) return false;
    else s.insert({a,b});
    if(dfs(a|b,b)||dfs(a,a|b)||dfs(a&b,b)||dfs(a,a&b)||dfs(a^b,b)||dfs(a,a^b)) return true;
    return false;
}

int main(){
    int T;
    ll a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&a,&b,&tar);
        s.clear();
        if(dfs(a,b)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}