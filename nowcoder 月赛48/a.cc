#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn=1e5+5;
LL a[maxn];
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int T;
    int i;
    scanf("%d",&T);
    for(i=0;i<T;i++) scanf("%lld",&a[i]);
    for(i=1;i<T;i++) if(gcd(a[i-1],a[i])!=1) break;
    if(i!=T) printf("-1\n");
    else printf("0\n");
    return 0;
}