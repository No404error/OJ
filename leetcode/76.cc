#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tMap;

        for(char ch:t)
            tMap[ch]++;

        int minSize=s.size()+1;
        unordered_map<char,int> tmpMap;
        tmpMap[s[0]]++;

        int left=0,right=0,ansLeft=-1,tmpSize=0;
        while(right<s.size()){
            if(isContain(tmpMap,tMap)){
                //修正res
                tmpSize=right-left+1;
                if(tmpSize<minSize){
                    minSize=tmpSize;
                    ansLeft=left;
                    //理论最小值
                    if(minSize==t.size())
                        return s.substr(ansLeft,minSize);
                }

                tmpMap[s[left]]--;
                left++;
            }
            else{
                right++;
                tmpMap[s[right]]++;
            }
        }
        return ansLeft==-1?"":s.substr(ansLeft,minSize);
    }

    bool isContain(unordered_map<char,int>& s,unordered_map<char,int>& t){
        for(auto pair:t){
            if(s.count(pair.first)&&s[pair.first]>=pair.second)
                continue;
            else
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.minWindow("s","ss");
    return 0;
}