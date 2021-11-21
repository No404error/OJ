#include<bits/stdc++.h>
using namespace std;
char ans[82];
int n; //第n个子串
int l; //子串由前l个字母构成
int cur_pos; //当前是第pos个子串
bool flag1,flag2;
bool dfs(int cur_len) { //len：当前的子串长段
    if(cur_pos==n) { //输出
        //每组4个，一行16组
        for(int i=0;i<cur_len;i++){
            printf("%c",ans[i]);
            //换行就不输出空格
            if((i+1)%64==0) puts("");
            else if((i+1)%4==0&&i<cur_len-1) printf(" ");
        }
        if(cur_len%64) puts("");
        printf("%d\n",cur_len);
        return true;
    }
    for(int i=0;i<l;i++){ 
        flag1=true;
        ans[cur_len]='A'+i;
        for(int j=1;2*j<=cur_len+1;j++){ //j是单个对比子串的长度
            flag2=false;
            for(int k=cur_len+1-2*j;k<cur_len+1-j;k++) if(ans[k]!=ans[k+j]) {flag2=true;break;}
            if(!flag2) {flag1=false;break;}
        }
        if(flag1) {
            cur_pos++;
            if(dfs(cur_len+1)) return true;
        }
    }
    return false;
}
void test(){ //dfs初始化
    cur_pos=0;
    dfs(0);
}
int main(){
    while(scanf("%d%d",&n,&l)==2&&n){
        test(); //dfs
    }
    return 0;
}