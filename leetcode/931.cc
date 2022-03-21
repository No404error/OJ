#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int len=matrix.size();
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(!i) dp[i][j]=matrix[i][j];
                else{
                    if(j>0) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                    if(j<len-1) dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j]);
                    dp[i][j]+=matrix[i][j];
                }
            }
        }
        int val=10001;
        for(int i=0;i<len;i++) if(val>dp[len-1][i]) val=dp[len-1][i];
        return val;
    }
private:
    int dp[100][100];
};

int main(){
    Solution s;
    vector<vector<int>> mat={{17,82},{1,-44}};
    cout<<s.minFallingPathSum(mat);
    return 0;
}