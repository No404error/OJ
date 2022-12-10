#include<bits/stdc++.h>
using namespace std;

    class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int point=nums.size()-2;
            for(;point>=0;point--){
                if(nums[point]<nums[point+1])
                    break;
            }
            if(point!=-1){
                for(int j=nums.size()-1;j>point;j--)
                    if(nums[j]>nums[point]){
                        swap(nums[point],nums[j]);
                        break;
                    }
            }
            
            reverse(nums.begin()+point+1,nums.end());
        }
    };

int main(){
    vector<int> v={1,2};
    Solution s;
    s.nextPermutation(v);
    return 0;
}