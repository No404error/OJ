#include<bits/stdc++.h>
using namespace std;

const int maxr=15;
const int maxc=105;
int dp[maxr][maxc],nex[maxr][maxc],a[maxr][maxc];
const int inf=0xfffffff;
const int dx[]={0,-1,1};
int nx[3];
int main(){
    int r,c;
    while(~scanf("%d%d",&r,&c)){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                scanf("%d",&a[i][j]);
            }
        }

        for(int i=1;i<=r;i++) dp[i][c]=a[i][c];
        for(int i=c-1;i>=1;i--) for(int j=1;j<=r;j++){
            for(int k=0;k<3;k++) nx[k]=dx[k]+j;
            if(j==1) nx[1]=r;
            if(j==r) nx[2]=1;
            sort(nx,nx+3);
            dp[j][i]=inf;
            for(int k=0;k<3;k++){
                int v=dp[nx[k]][i+1]+a[j][i];
                if(v<dp[j][i]) {dp[j][i]=v;nex[j][i]=nx[k];}
            }
        }
        int first,val=inf;
        for(int i=1;i<=r;i++) if(val>dp[i][1]) {val=dp[i][1];first=i;}
        printf("%d",first);
        for(int i=nex[first][1],j=2;j<=c;i=nex[i][j],j++)
            printf(" %d",i);
        printf("\n%d\n",val);
    }
    return 0;
}