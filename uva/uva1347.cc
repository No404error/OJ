#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int maxn=1050;
double dp[maxn][maxn];
pair<int,int> pos[maxn];

double dist(int i,int j){
    double dx=pos[i].x-pos[j].x;
    double dy=pos[i].y-pos[j].y;
    return sqrt(dx*dx+dy*dy);
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++) scanf("%d%d",&pos[i].x,&pos[i].y);

        for(int i=1;i<n-1;i++) dp[n-1][i]=dist(n-1,n)+dist(i,n);
        for(int i=n-2;i>=2;i--) for(int j=1;j<i;j++){
            dp[i][j]=min(dp[i+1][i]+dist(i+1,j),dp[i+1][j]+dist(i+1,i));
        }
        printf("%.2lf\n",dist(1,2)+dp[2][1]);
    }
    return 0;
}