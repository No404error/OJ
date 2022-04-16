#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> srg={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s;
        s.resize(digits.size());
        vector<string> res;
        if(!digits.size()) return res;
        dfs(s,digits,res,srg,0,digits.size());
        return res;
    }
    void dfs(string& s,string& t,vector<string>& v,vector<string>& srg,int floor,int tar){
        if(floor==tar) {v.push_back(s);return;}
        string& ss=srg[t[floor]-'2'];
        for(int i=0;i<ss.size();i++){
            s[floor]=ss[i];
            dfs(s,t,v,srg,floor+1,tar);
        }
        return;
    }
};

int main(){

    return 0;
}