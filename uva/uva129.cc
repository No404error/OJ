#include<iostream>

using namespace std;

int n,L,cnt=0;
int ans[100];

bool dfs(int cur){
    //base case
    if(cnt++==n){
        int len=cur-1;
        for(int i=1;i<=len;i++) {
            printf("%c",'A'+ans[i]);
            if(len>64&&i==64) {printf("\n");continue;}
            if(i%4==0&&i<len) printf(" ");
        }
        printf("\n%d\n",len);
        return true;
    }

    for(int i=0;i<L;i++){
        ans[cur]=i;
        bool ok=true;
        for(int length=1;2*length<=cur;length++){
            bool equal=true;
            for(int j=0;j<length;j++) if(ans[cur-j]!=ans[cur-length-j]) {equal=false;break;}
            if(equal) {ok=false;break;}
        }
        if(ok) if(dfs(cur+1)) return true;
    }
    return false;
}

int main(){
    while(scanf("%d%d",&n,&L)==2&&n){
        cnt=0;
        dfs(1);
    }
    return 0;
}