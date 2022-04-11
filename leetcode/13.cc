#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        int nums[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string srg[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int pos=0,size=1;
        for(int i=0;i<13;i++){
            size=srg[i].size();
            bool ok=true;
            while(ok){
                for(int j=0;j<size;j++) if(pos+j>=s.size()||[i][j]!=s[pos+j]) {ok=false;break;}
                if(ok) {
                    res+=nums[i];
                    pos+=size;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    s.romanToInt("III");
    return 0;
}