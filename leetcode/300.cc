#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int maxval,res=1;
        for(int i=1;i<nums.size();i++){
            maxval=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]&&dp[j]>maxval) maxval=dp[j];
            }
            dp[i]=maxval+1;
            res=max(res,dp[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v={10,9,2,5,3,7,101,18};
    cout<<s.lengthOfLIS(v);
    return 0;
}