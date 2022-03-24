#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre,post,res;
        pre=0;post=res=nums[0];
        for(int i=1;i<nums.size();i++){
            pre=post;
            post=pre>0?nums[i]+pre:nums[i];
            if(post>res) res=post;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v={5,4,-1,7,8};
    cout<<s.maxSubArray(v);
    return 0;
}