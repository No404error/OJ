#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    bool flag;
    while(cin>>s){
        flag=true; //立一个旗子，最开始是true
        for(int i=1;i<s.size();i++) if(s[i]<='z'&&s[i]>='a') {flag=false;break;} //条件中可以推出只需要考虑除第一位以外的大小写
        if(flag) for(int i=0;i<s.size();i++) { //如果符合就改变大小写
            if(s[i]<='z'&&s[i]>='a') s[i]=s[i]-'a'+'A';
            else s[i]=s[i]-'A'+'a';
        }
        cout<<s<<endl;
    }
    return 0;
}