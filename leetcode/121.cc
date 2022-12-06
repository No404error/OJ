#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal=INT_MAX;
        int res=0;
        for(int i=0;i<prices.size();i++){
            if(minVal>prices[i]){
                minVal=prices[i];
            }
            if(prices[i]-minVal>res)
                res=prices[i]-minVal;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v={2,1,4};
    cout<<s.maxProfit(v);
    return 0;
}