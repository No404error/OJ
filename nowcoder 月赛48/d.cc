#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll mod=1e9+7;
ll a[maxn],b[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        if(i%2) b[i]=a[n/2+(i+1)/2];
        else b[i]=a[n/2-(i/2-1)];
    ll res=b[1]+b[2];
    for(int i=3;i<=n;i++) 
        if(i%2) res=res*b[i]%mod;
        else res=(res+b[i])%mod;
    printf("%lld",res);
    return 0;
}