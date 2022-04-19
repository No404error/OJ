#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
bool huiwen[maxn][maxn];
int dp[maxn];
char str[maxn];
int main(){
    int T;scanf("%d",&T);
    getchar();
    while (T--){
        fgets(str+1,1000,stdin);
        memset(huiwen,0,sizeof(huiwen));
        memset(dp,0x3f,sizeof(dp));

        int n=strlen(str+1)-1;
        for(int i=1;i<=n;i++){
            int maxk1=min(i-1,n-i);
            int maxk2=min(i-1,n-i-1);
            for(int k=0;k<=maxk1;k++){
                if(str[i-k]==str[i+k]) huiwen[i-k][i+k]=1;
                else break; 
            }
            for(int k=0;k<=maxk2;k++){
                if(str[i-k]==str[i+1+k]) huiwen[i-k][i+1+k]=1;
                else break;
            }
        }
        dp[1]=1;
        for(int i=2;i<=n;i++) {
            if(huiwen[1][i]) {dp[i]=1;continue;}
            for(int j=1;j<i;j++)
            if(huiwen[j+1][i]) dp[i]=min(dp[j]+1,dp[i]);
        }
        printf("%d\n",dp[n]);
    }   
    return 0;
}