#include<bits/stdc++.h>
using namespace std;

const int maxn=5005;
const int maxs=100;
int INF=INT_MAX;
int cnt[maxn][maxn],dp[maxn][maxn];
int s1[maxs],e1[maxs],s2[maxs],e2[maxs];
char str1[maxn],str2[maxn];
int main(){
    int T;
    char c;
    scanf("%d",&T);
    while(T--){
        scanf("%s %s",str1+1,str2+1);
        int n=strlen(str1+1),m=strlen(str2+1);
        for(int i='A';i<='Z';i++) s1[i]=s2[i]=INF,e1[i]=e2[i]=0;
        for(int i=1;i<=n;i++){
            c=str1[i];
            s1[c]=min(s1[c],i);
            e1[c]=i;
        }
        for(int i=1;i<=m;i++){
            c=str2[i];
            s2[c]=min(s2[c],i);
            e2[c]=i;
        }
        
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++){
            if(i){
                cnt[i][j]=cnt[i-1][j];
                c=str1[i];
                if(s1[c]==i&&s2[c]>j) cnt[i][j]++;
                if(e1[c]==i&&e2[c]<=j) cnt[i][j]--;
            }
            if(j){
                cnt[i][j]=cnt[i][j-1];
                c=str2[j];
                if(s2[c]==j&&s1[c]>i) cnt[i][j]++;
                if(e2[c]==j&&e1[c]<=i) cnt[i][j]--;
            }
        }
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++){
            if(!i&&!j) continue;
            dp[i][j]=INF;
            if(i) dp[i][j]=min(dp[i][j],dp[i-1][j]+cnt[i][j]);
            if(j) dp[i][j]=min(dp[i][j],dp[i][j-1]+cnt[i][j]);
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}