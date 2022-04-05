#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int* T=new int[nums.size()];
        int res=reversePairs(nums,0,nums.size(),T);
        delete []T;
        return res;
    }
    int reversePairs(vector<int>& nums,int x,int y,int* T){
        if(y-x>1){
            int m=x+(y-x)/2;
            int q=x,p=m,i=x;
            int cnt=0;
            cnt+=reversePairs(nums,x,m,T);
            cnt+=reversePairs(nums,m,y,T);
            while(q<m||p<y){
                if(p>=y||(q<m&&nums[q]<=nums[p])) T[i++]=nums[q++];
                else T[i++]=nums[p++],cnt+=m-q;
            }
            for(i=x;i<y;i++) nums[i]=T[i];
            return cnt;
        }
        return 0;
    }
};

int main(){
    vector<int> v={7,5,6,4};
    Solution s;
    cout<<s.reversePairs(v);
    return 0;
}