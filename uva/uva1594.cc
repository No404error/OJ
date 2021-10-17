#include<bits/stdc++.h>
using namespace std;
set<vector<int>> s;
int main(){
    int n,m,t;cin>>n; 
    while(n--){ //跑第n个例子
        cin>>m;
        vector<int> zeros(m,0),buf,v; //
        for(int i=0;i<m;i++){
            cin>>t;buf.push_back(t);
        }
        bool t1=false;
        while(!((t1=s.count(buf))||buf==zeros)){
            s.insert(buf);
            v=buf;
            for(int i=0;i<m;i++){
                if(i==m-1) buf[i]=abs(v[i]-v[0]);
                else buf[i]=abs(v[i]-v[i+1]);
            }
        }
        if(t1) cout<<"LOOP"<<endl;
        else cout<<"ZERO"<<endl;
    }
    return 0;
}