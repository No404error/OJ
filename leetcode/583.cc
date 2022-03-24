#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*longestCommonSubsequence(word1,word2);
    }
private:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.size(),len2=text2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++) 
            for(int j=1;j<=len2;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        return dp[len1][len2];
    }
};

int main(){
    Solution s;
    string s1="sea";
    string s2="eat";
    cout<<s.minDistance(s1,s2);
    return 0;
}