#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        int num,pos;
        for(int i=0;i<nums.size();i=find_next(i,nums)){
            if(nums[i]>0) break;
            for(int j=i+1;j<nums.size();j=find_next(j,nums)){
                num=-nums[i]-nums[j];
                if(num<nums[j]) break;
                pos=upper_bound(nums.begin(),nums.end(),num)-nums.begin()-1;
                if(nums[pos]==num&&pos>j) res.push_back({num,nums[i],nums[j]});
            }
        }
        return res;
    }
    int find_next(int index,vector<int>& nums){
        int val=nums[index];
        while(++index!=nums.size()&&nums[index]==val);
        return index;
    }
};
int main(){
    vector<int> v={0,0,0};
    Solution s;
    s.threeSum(v);
    return 0;
}