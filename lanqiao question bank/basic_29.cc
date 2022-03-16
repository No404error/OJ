#include<iostream>
using namespace std;

const int N=105;
char v1[N],v2[N],res[N];
int start1,start2;
int maxsize;
int upt,sum;
int pos;
int main()
{
    scanf("%s%s",&v1,&v2);

    for(start1=0;v1[start1];start1++) v1[start1]-='0';
    for(start2=0;v2[start2];start2++) v2[start2]-='0';
    
    start1--;
    start2--;
    maxsize=max(start1,start2);

    upt=0;
    for(int i=0;i<=maxsize||upt!=0;i++){
        pos=N-1-i;
        sum=0;
        if(start1-i>=0) sum+=v1[start1-i];
        if(start2-i>=0) sum+=v2[start2-i];
        sum+=upt;
        res[pos]=sum%10;
        upt=sum/10;
    }
    for(int i=pos;i<N;i++) 
        printf("%d",res[i]);

    return 0;
}