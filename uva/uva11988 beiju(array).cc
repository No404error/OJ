#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int last,cur,nex[maxn]; //链表结构的尾，当前位置，和容器 
char s[maxn]; //装载字符串
int main(){
    while(scanf("%s",s+1)==1){
        int n=strlen(s+1);
        char ch;
        last=cur=0; //头位置
        nex[0]=0; //初始化 防止第一位为[
        for(int i=1;i<=n;i++){
            ch=s[i];
            if(ch=='[') cur=0; //把当前位置调整到0
            else if(ch==']') cur=last; //把当前位置调整到尾
            else{
                nex[i]=nex[cur]; //用来控制跳转的，把原位置的指针继承过来
                nex[cur]=i; //顺序继承
                if(cur==last) last=i; //更改尾位置
                cur=i; //调整当前位置
            }
        }
        for(int i=nex[0];i!=0;i=nex[i])    printf("%c",s[i]); //输出
        printf("\n");
    }
    return 0;
}