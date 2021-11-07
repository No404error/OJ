#include<bits/stdc++.h>
using namespace std;
const int N=210;
int n;
char buf[N][N];
void dfs(int r,int c){
    printf("%c(",buf[r][c]);
    if(r+1<n&&buf[r+1][c]=='|'){ //有子树
        int i=c;
        while(i-1>=0&&buf[r+2][i-1]=='-') i--; //寻找左边界
        while(buf[r+2][i]=='-'&&buf[r+3][i]!='\0'){
            if(!isspace(buf[r+3][i])) dfs(r+3,i);
            i++;
        }
    }
    printf(")");
}
void solve(){
    n=0;
    for(;;n++){
        fgets(buf[n],N,stdin);
        if(buf[n][0]=='#') break;
    }
    printf("(");
    if(n){
        for(int j=0;j<strlen(buf[0]);j++) if(buf[0][j]!=' ') {  dfs(0,j);break; }
    }
    printf(")\n");
}
int main(){
    int T;
    fgets(buf[0],N,stdin);
    sscanf(buf[0],"%d",&T);
    while(T--) solve();
    return 0;
}