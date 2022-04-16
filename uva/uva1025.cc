#include<bits/stdc++.h>
using namespace std;

const int maxn=60;
const int maxt=220;
const int inf=225;
int t[maxn],lefts[maxn],rights[maxn];
bool have_train[maxt][maxn][2];
int dp[maxt][maxn];
int N,T;

int main(){
    int size1,size2,train_t;
    int kase=0;
    while(scanf("%d",&N)!=EOF&&N){
        memset(have_train,0,sizeof(have_train));

        scanf("%d",&T);
        for(int i=1;i<N;i++) scanf("%d",&t[i]);
        scanf("%d",&size1);
        for(int i=1;i<=size1;i++) scanf("%d",&rights[i]);
        scanf("%d",&size2);
        for(int i=1;i<=size2;i++) scanf("%d",&lefts[i]);

        for(int i=1;i<=size1;i++){
            train_t=rights[i];
            have_train[train_t][1][0]=true;
            for(int j=1;j<N-1;j++) {
                train_t+=t[j];
                if(train_t>T) break;
                have_train[train_t][1+j][0]=true;
            }
        }
        for(int i=1;i<=size2;i++){
            train_t=lefts[i];
            have_train[train_t][N][1]=true;
            for(int j=N-1;j>1;j--) {
                train_t+=t[j];
                if(train_t>T) break;
                have_train[train_t][j][1]=true;
            }
        }

        // printf("c");
        for(int i=1;i<N;i++) dp[T][i]=inf;
        dp[T][N]=0;

        for(int i=T-1;i>=0;i--) for(int j=1;j<=N;j++){
            dp[i][j]=dp[i+1][j]+1;
            //右
            if(j<N&&i+t[j]<=T&&have_train[i][j][0]) dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
            //左
            if(j>1&&i+t[j-1]<=T&&have_train[i][j][1]) dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
        }

        printf("Case Number %d: ",++kase);
        if(dp[0][1]>=inf) printf("impossible\n");
        else printf("%d\n",dp[0][1]);
    }
    return 0;
}