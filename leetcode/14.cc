#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=205;
        for(int i=0;i<strs.size();i++) len=min(len,int(strs[i].size()));
        int i;
        char ch;
        for(i=0;i<len;i++){
            bool flag=false;
            ch=strs[0][i];
            for(int j=1;j<strs.size();j++) if(ch!=strs[j][i]) {flag=true;break;}
            if(flag) break;
        }
        return strs[0].substr(0,i?i-1:0);
    }
};
