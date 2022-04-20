#include<bits/stdc++.h>
using namespace std;

const int maxn=100+5;
char s[maxn];
int dp[maxn][maxn];

bool match(char a,char b){
    return (a=='('&&b==')')||(a=='['&&b==']');
}

void print(int i,int j){
    if(i>j) return;
    if(i==j){
        if(s[i]=='('||s[i]==')') printf("()");
        else printf("[]");
        return;
    }
    int ans=dp[i][j];
    if(match(s[i],s[j])&&ans==dp[i+1][j-1]){
        printf("%c",s[i]);print(i+1,j-1);printf("%c",s[j]);
        return;
    }
    for(int k=i;k<j;k++){
        if(ans==dp[i][k]+dp[k+1][j]){
            print(i,k),print(k+1,j);
            return;
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        getchar();
        fgets(s,maxn,stdin);
        if(s[0]=='\n'){
            printf("\n\n");
            continue;
        }

        int n=strlen(s)-1;

        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<n;i++) {
            dp[i+1][i]=0;
            dp[i][i]=1;
        }
        for(int i=n-2;i>=0;i--) for(int j=i+1;j<n;j++){
            if(match(s[i],s[j])) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            for(int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }

        print(0,n-1);
        puts("");
        if(T) puts("");
    }
    return 0;
}