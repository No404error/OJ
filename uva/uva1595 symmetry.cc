#include<bits/stdc++.h> //思考题,对称问题
using namespace std;
map<int,vector<int>> mp; //做一个以y为索引的映射(用x为映射亦可以，需要考虑轴上及轴下
int main(){
    int a,b,t1,t2,half;scanf("%d",&a);while(a--){
        scanf("%d",&b);for(int i=0;i<b;i++){ //输入
            scanf("%d%d",&t1,&t2);
            mp[t2].push_back(t1);
        }
        set<int> s;
        for(auto p:mp){ 
            sort(p.second.begin(),p.second.end());
            half=p.second.size()&1?p.second.size()/2+1:p.second.size()/2; //为奇数个算上中间值
            for(int i=0;i<half;i++){
                s.insert(p.second[i]+p.second[p.second.size()-i-1]);
            }
        }
        printf("%s\n",s.size()==1?"YES":"NO");
        mp.clear();
    }
    return 0; 
}