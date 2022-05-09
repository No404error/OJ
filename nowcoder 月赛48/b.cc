#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    ll n,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&a,&b);
        int res=0;
        if(a>b) res=0;
        else if(a<b) res=1;
        else{
            ll l=1,r=1e9,mid;
            while(l<r){
                mid=l+(r-l)/2;
                if(mid*(mid+1)<=2*n) l=mid+1;
                else r=mid;
            }
            if(l%2) res=0;
            else res=1;
        }
        if(res==0) printf("niuniu\n");
        else printf("niumei\n");
    }
    return 0;
}