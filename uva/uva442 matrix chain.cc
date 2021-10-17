#include<bits/stdc++.h>
using namespace std;
struct matrix{ //定义一个记录矩阵行列的结构
    int a,b;
    matrix(int a=0,int b=0):a(a),b(b){} //初始化
    void in(int c,int d){a=c,b=d;} //赋值
} m[26];
int main(){
    string s;
    int t1,t2;
    int t;cin>>t;
    for(int i=0;i<t;i++) { //输入字母的值
        cin>>s>>t1>>t2;
        m[s[0]-'A'].in(t1,t2);
    }
    while(cin>>s){ 
        int len=s.size(),ans=0; 
        bool error=false;
        stack<matrix> stk;
        for(int i=0;i<len;i++){
            if(isalpha(s[i])) stk.push(m[s[i]-'A']); //是字母就入栈
            else if(s[i]==')') { //是')'就出栈操作
                matrix x1,x2;
                x2=stk.top();stk.pop();
                x1=stk.top();stk.pop();
                if(x1.b!=x2.a) {error=true;break;}
                ans+=x1.a*x1.b*x2.b;
                stk.push(matrix(x1.a,x2.b)); //再把新产生的结构放回栈中
            }
        }
        if(error) cout<<"error"<<endl; else cout<<ans<<endl; 
    }
    return 0;
}