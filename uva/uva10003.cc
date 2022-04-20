#include<bits/stdc++.h>
using namespace std;

const int maxn=55;
int pos[maxn];
int dp[maxn][maxn];

int main(){
    int len,n;
    while(cin>>len&&len){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>pos[i];
        pos[0]=0;pos[n+1]=len;
        memset(dp,0x3f,sizeof(dp));

        for(int i=0;i<=n+1;i++) dp[i][i]=0;
        for(int i=0;i<=n;i++) dp[i][i+1]=0;

        for(int d=2;d<=n+1;d++) for(int i=0;i+d<=n+1;i++){
            int j=i+d;
            for(int k=i+1;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+pos[j]-pos[i]);
        }
        printf("The minimum cutting is %d.\n",dp[0][n+1]);
    }
    return 0;
}