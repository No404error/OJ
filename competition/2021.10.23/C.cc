#include<bits/stdc++.h>
using namespace std;
const int maxn=10+3;
int cnt[maxn];
int main(){
    int T,t,a;scanf("%d",&T);while(T--){
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&t);for(int i=0;i<t;i++){ //输入某位置的人数
            scanf("%d",&a); 
            cnt[a]++;
        }
        int maxt=0,mint=INT_MAX,tem=0; //tem记录当前的值，maxt记录max值，mint记录min值
        for(int i=0;i<maxn-2;){
           if(cnt[i+2]) { //当第二继位有值，直接跳到第二继位,添加本位和第一继位的值
               tem+=cnt[i]+cnt[i+1];
               i+=2;
           }
           else if(cnt[i+1]){ //第二继位无值，第一继位有值时，跳到第一继位，添加本位的值
               tem+=cnt[i];
               i++;
           }
           else{ //后两位都无值，添加本位的值进行运算，跳到第二继位
               tem+=cnt[i];
               if(tem) maxt=max(maxt,tem); //tem可能为0
               if(tem) mint=min(mint,tem);
               tem=0;
               i+=2;
           }
        }
        printf("%d %d\n",mint,maxt);
    }
    return 0;
}