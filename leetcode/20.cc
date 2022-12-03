#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char,char> map;
        map['(']=')';
        map['[']=']';
        map['{']='}';
        stack<char> st;
        for(char ch:s){
            if(ch=='('||ch=='['||ch=='{')
                st.push(ch);
            else if(st.size()==0)
                return false;
            else if(map[st.top()]==ch)
                st.pop();
            else if(st.top()!=ch)
                return false;
        }
        if(!st.empty())
            return false;
        else
            return true;
    }
};

int main(){
    Solution s;
    cout<<s.isValid("(())");
    return 0;
}