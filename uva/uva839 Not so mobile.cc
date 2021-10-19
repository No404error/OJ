#include<bits/stdc++.h>
using namespace std;
bool solve(int& w){
    int w1,d1,w2,d2; //定义当前臂长，质量等
    bool b1=true,b2=true;
    cin>>w1>>d1>>w2>>d2;
    if(!w1) b1=solve(w1); //有左臂
    if(!w2) b2=solve(w2); //有右臂
    w=w1+w2; //修改质量，因为天平是递归定义的，在计算所有下层时在计算本层的质量
    return b1&&b2&&(w1*d1==w2*d2);
}
int main(){
    int t,w;
    cin>>t;
    while(t--){
        if(solve(w)) cout<<"YES\n";else cout<<"NO\n";
        if(t) cout<<"\n";
    }
    return 0;
}