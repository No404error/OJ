#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,num[20],cnt=1; //储存项，计数器
    long long maxn,p; //最大值
    while(cin>>N){
        for(int i=0;i<N;i++) scanf("%d",&num[i]); //输入
        maxn=0; //初始化最大值
        for(int i=0;i<N;i++){ //起点
            p=1; 
            for(int j=i;j<N;j++){ //终点
                p*=(long long)num[j];
                if(p>maxn) maxn=p;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",cnt++,maxn); //输出
    }
    return 0;
}