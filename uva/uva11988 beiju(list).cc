#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); //取消流同步
    string s; 
    int len;
    while(cin>>s){ 
        list<char> l; //建立一个双向链表
        auto p=l.begin(); //迭代器
        for(auto i:s){
            if(i=='[') p=l.begin(); //指向头
            else if(i==']') p=l.end();//指向尾
            else l.insert(p,i); //插入
        }
        for(auto i:l) cout<<i; //输出
        cout<<endl;
    }
    return 0;
}