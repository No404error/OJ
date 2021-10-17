#include<bits/stdc++.h> //比较 water （可以用哈希数组实现）
using namespace std;
vector<int> v1,v2; //定义两个待比较的队列
int main(){
    int t,a,b;while(cin>>t&&t){
        for(int i=0;i<t;i++){
            cin>>a>>b;
            v1.push_back(a);
            v2.push_back(b);
        }
        sort(v1.begin(),v1.end()); //排序
        sort(v2.begin(),v2.end()); 
        if(v1==v2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        v1.clear();v2.clear();
    }
    return 0;
}