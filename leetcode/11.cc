#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=int(height.size())-1;
        int leftH=height[left],rightH=height[right];
        int res=-1;
        int w,h,area;
        while(left<right){
            w=right-left;
            h=min(leftH,rightH);
            area=w*h;
            if(res<area)
                res=area;
            
            if(leftH>rightH){
                while(true){
                    right--;
                    if(left>=right)
                        break;
                    if(height[right]>rightH){
                        rightH=height[right];
                        break;
                    }
                }
            }
            else{
                while(true){
                    left++;
                    if(left>=right)
                        break;
                    if(height[left]>leftH){
                        leftH=height[left];
                        break;
                    }
                }
            }

        }
        return res;
    }
};

int main(){
    vector<int> v={1,8,6,2,5,4,8,3,7};
    Solution s;
    cout<<s.maxArea(v);
    return 0;
}