#include<bits/stdc++.h> //队列的应用 water
using namespace std;
int main(){
    int t;while(cin>>t&&t){ //输入
        queue<int> q,l;
        for(int i=1;i<=t;i++) q.push(i); //构造序列
        for(int i=t;i>=2;i--) { //处理
            int tmp=q.front();q.pop();l.push(tmp); //先把q顶拿出来放在l中
            tmp=q.front();q.pop();q.push(tmp); //再把q现在的顶放在q尾上
        }
        cout<<"Discarded cards:"; //输出格式 将换行和输出的数字分开，在l队列没有值时第一行无数字输出
        while(!l.empty()) {
            cout<<" "<<l.front(); l.pop();
            if(!l.empty()) cout<<",";
        }
        cout<<endl<<"Remaining card: "<<q.front()<<endl;
    }
    return 0;
}