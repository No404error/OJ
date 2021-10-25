#include<bits/stdc++.h>
using namespace std;
const int maxn=10+3;
bool have[maxn];
int cnt[maxn];
int main(){
    int T,t,a;scanf("%d",&T);while(T--){
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&t);for(int i=0;i<t;i++){
            scanf("%d",&a);
            cnt[a]++;
        }
        for(int i=0;i<maxn;i++) have[i]=cnt[i]?true:false;
        int maxt=0,mint=INT_MAX,tem=0;
        for(int i=0;i<maxn-2;){
           if(have[i+2]) {
               tem+=cnt[i]+cnt[i+1];
               i+=2;
           }
           else if(have[i+1]){
               tem+=cnt[i];
               i++;
           }
           else{
               tem+=cnt[i];
               if(tem) maxt=max(maxt,tem);
               if(tem) mint=min(mint,tem);
               tem=0;
               i+=2;
           }
        }
        printf("%d %d\n",mint,maxt);
    }
    return 0;
}