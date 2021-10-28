#include<bits/stdc++.h>
using namespace std;
int apl[300005],n,m,ord,a,b;
int main(){
    scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&apl[i]); //输入
        while(m--){ //指令
            scanf("%d%d%d",&ord,&a,&b); 
            if(ord==1) apl[a]=b;
            else{
                int j;
                for(j=a+1;j<=b;j++) if(apl[j]<apl[j-1]) { //从a+1到b确保不重不漏
                    puts("No");
                    break;
                }
                if(j==b+1) puts("Yes"); //正确位置
            }
        }
    return 0;
}