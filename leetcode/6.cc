#include<bits/stdc++.h>
using namespace std;

string arr[100];

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        bool isAdd=true;
        //string* arr=new string[numRows+1];
        for(int i=0,lis=0;i<s.length();i++){
            arr[lis]+=s[i];
            lis=isAdd?lis+1:lis-1;
            if(lis==numRows){
                isAdd=false;
                lis-=2;
            }
                
            if(lis==-1){
                isAdd=true;
                lis+=2;
            }
                
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+=arr[i];
        }
        return ans;

    }
};

int main(){
    Solution s;
    cout<<s.convert("PAYPALISHIRING",3);
    return 0;
}