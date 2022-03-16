#include<iostream>
using namespace std;

const int N = 12000;
char val[N];
int n;
int pos;
int upt,sum;

int main(){
    val[N-1]=1;
    pos=N-1;
    cin>>n;
    if (n==1) printf("1");
    else {
        for(int i=2;i<=n;i++){
            upt=0;
            for(int j=N-1;j>=pos||upt!=0;j--){
                sum=val[j]*i+upt;
                upt=sum/10;
                val[j]=sum%10;
                if(j<pos) pos=j;
            }
        }
        // for(int j=pos;j<=N-1;j++) printf("%d",val[j]);
        printf("%d",sizeof(val));
    }
    return 0;
}