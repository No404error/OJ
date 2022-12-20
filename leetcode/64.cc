#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
            dp[0][i]=dp[0][i-1]+grid[0][i];
        
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++){
                if(j==0)
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                else
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        return dp[n-1][m-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> p={{1,1,1},{1,1,1}};
    s.minPathSum(p);
    return 0;
}