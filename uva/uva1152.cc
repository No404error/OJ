#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=4000+5;
int A[maxn],B[maxn],C[maxn],D[maxn];
int sum1[maxn*maxn],sum2[maxn*maxn];

int main(){
    int N,n;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
        int cnt=0,res=0;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
            sum1[cnt]=A[i]+B[j];
            sum2[cnt]=C[i]+D[j];
            cnt++;
        }
        sort(sum1,sum1+cnt);
        sort(sum2,sum2+cnt);
        for(int i=0;i<cnt;i++){
            int dif=-1*sum1[i];
            int s1=lower_bound(sum2,sum2+cnt,dif)-sum2;
            int s2=upper_bound(sum2,sum2+cnt,dif)-sum2;
            res+=s2-s1;
        }
        printf("%d\n",res);
        if(N) puts("");
    }
    return 0;
}