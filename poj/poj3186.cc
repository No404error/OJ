#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=2e4+5;
int dp[maxn][maxn];
int val[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    for(int i=1;i<=n;i++) dp[i][i-1]=dp[i-1][i]=0;
    for(int d=1;d<=n;d++){
        int p=n-d+1;
        for(int i=1;i+d-1<=n;i++){
            int j=i+d-1;
            dp[i][j]=max(p*val[i]+dp[i+1][j],p*val[j]+dp[i][j-1]);
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}