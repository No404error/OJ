#include<iostream>
#include<algorithm>

using namespace std;
//i是放完第i块积木，高度差为j的最大塔高，k是第k个塔较高些
int dp[105][10005][2];
int a[105];
int n,sum=0;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    for(int i=0;i<=n;i++) for(int j=0;j<=sum;j++) for(int k=0;k<=1;k++) dp[i][j][k]=-1;
    dp[0][0][0]=dp[0][0][1]=0;

    int another;
    for(int i=1;i<=n;i++) for(int j=sum;j>=0;j--) for(int k=0;k<=1;k++){
        //另一个塔的编号
        another=k^1;

        //原本是k塔较高，将第i块继续放在k塔上，仍是k塔较高
        if(j>=a[i]&&dp[i-1][j-a[i]][k]>=0) //限制条件，剪枝
            dp[i][j][k]=max(dp[i-1][j-a[i]][k]+a[i],dp[i][j][k]);

        //原本是另一个塔较高，将第i块放在k塔上，最后k塔较高
        if(a[i]>j&&dp[i-1][a[i]-j][another]>=0)
            dp[i][j][k]=max(dp[i-1][a[i]-j][another]+j,dp[i][j][k]);

        //原本是k塔较高，将第i块放在另一个塔上，仍是k塔较高
        if(a[i]+j<=sum&&dp[i-1][a[i]+j][k]>=0)
            dp[i][j][k]=max(dp[i-1][a[i]+j][k],dp[i][j][k]);

        //不放第i块
        if(dp[i-1][j][k]>=0)
            dp[i][j][k]=max(dp[i-1][j][k],dp[i][j][k]);
    }
    cout<<max(dp[n][0][0],dp[n][0][1]);
    return 0;
}