#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];
        int sum,start,end;
        for(int i=0;i<nums.size();i++){
            start=i+1,end=nums.size()-1;
            while(start<end){
                sum=nums[i]+nums[start]+nums[end];
                if(abs(res-target)>abs(sum-target))
                    res=sum;
                if(sum>target) end--;
                else if(sum<target) start++;
                else return target;
            }
        }
        return res;
    }
};

int main(){

    return 0;
}