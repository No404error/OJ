#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m=ring.size(),n=key.size();
        for(int i=0;i<m;i++) CharPos[ring[i]].push_back(i);

        memset(dp,0x3f,sizeof(dp));
        for(auto i:CharPos[key[0]])  dp[0][i]=min(i,m-i)+1;

        for(int i=1;i<n;i++) for(auto j:CharPos[key[i]]) for(auto k:CharPos[key[i-1]]){
            dp[i][j]=min(dp[i][j],dp[i-1][k]+min(abs(j-k),m-abs(j-k))+1);
        }
        int res=66666;
        for(int i=0;i<m;i++) if(res>dp[n-1][i]) res=dp[n-1][i];
        return res;
}
private:
    map<char,vector<int>> CharPos;
    int dp[101][101];
};

int main(){
    Solution s;
    cout<<s.findRotateSteps("godding","gd");
    return 0;
}