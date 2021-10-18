#include<bits/stdc++.h>
using namespace std;
int main(){
    int D,I,T;
    scanf("%d",&T);while(T--){
        scanf("%d%d",&D,&I);
        int ans=1;
        for(int i=0;i<D-1;i++){ //1->D层
            if(I&1) {ans*=2;I=(I+1)/2;} //奇数和偶数的规律
            else {ans=ans*2+1;I/=2;}
        }
        printf("%d\n",ans);
    }
    return 0;
}