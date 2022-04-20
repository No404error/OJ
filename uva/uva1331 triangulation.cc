#include<bits/stdc++.h>
using namespace std;

const double eps=1e-6;
const int maxn=55;
double dp[maxn][maxn];
int N;
struct point
{
    double x,y;
} A[maxn];

double e_distance(const point& p1,const point& p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double Area(const point& p1,const point& p2,const point& p3){
    double a=e_distance(p1,p2);
    double b=e_distance(p1,p3);
    double c=e_distance(p2,p3);
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
bool check(int a,int b,int c){
    double areas=Area(A[a],A[b],A[c]);
    for(int i=1;i<=N;i++) if(i!=a&&i!=b&&i!=c) 
        if(fabs(areas-Area(A[i],A[a],A[b])-Area(A[i],A[a],A[c])-Area(A[i],A[c],A[b]))<eps)
            return false;
    return true; 
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++) scanf("%lf%lf",&A[i].x,&A[i].y);
        for(int i=1;i<N;i++) dp[i][i+1]=0;
        for(int i=1;i<=N;i++) dp[i][i]=0;
        for(int d=2;d<=N-1;d++) for(int i=1;i+d<=N;i++){
            int j=i+d;
            dp[i][j]=1e11;
            for(int k=i+1;k<j;k++) 
                if(check(i,j,k))
                dp[i][j]=min(max(max(dp[i][k],dp[k][j]),Area(A[i],A[j],A[k])),dp[i][j]);
        }
        printf("%.1lf\n",dp[1][N]);
    }
    return 0;
}