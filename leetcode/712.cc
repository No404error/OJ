#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1=s1.size(),len2=s2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,2550000));
        dp[0][0]=0;
        for(int i=1;i<=len1;i++) dp[i][0]=dp[i-1][0]+s1[i-1];
        for(int i=1;i<=len2;i++) dp[0][i]=dp[0][i-1]+s2[i-1];

        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
            }
        return dp[len1][len2];
    }
};

int main(){
    Solution s;
    string s1="sea";
    string s2="eat";
    cout<<s.minimumDeleteSum(s1,s2);
    return 0;
}