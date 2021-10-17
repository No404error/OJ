#include<bits/stdc++.h> //二分思想？ 有一点想法的water
using namespace std;
set<string> s;
int main(){
    string t;
    while(cin>>t) s.insert(t); //输入单词
    for(string t:s){
        for(int i=1;i<t.size();i++) //题意为寻找由两个词构成的复合词，把单词分为两部分在库中寻找
            if(s.find(t.substr(0,i))!=s.end()&&s.find(t.substr(i))!=s.end()) {
                cout<<t<<endl; //当同时存在两份时就输出，结束本单词的寻找
                break;
            }
    }
    return 0;
}