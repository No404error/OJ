#include<bits/stdc++.h>
using namespace std;
long long lis[]={127,32767,2147483647,9223372036854775807},test;
string st[]={"byte","short","int","long","BigInteger"}; 
int main(){
    string s,ans;
    while(cin>>s){
       if(s.size()>19) ans=st[4];
       else{
           stringstream p(s.substr(0,19));
           p>>test;
           if(s.size()==19) {
                if(test<0) ans=st[4];
                else ans=st[3];
           }
           else{
               if(test<=lis[0]) ans=st[0];
               else if(test<=lis[1]) ans=st[1];
               else if(test<=lis[2]) ans=st[2];
               else ans=st[3];
           }
       }
       cout<<ans<<endl;
    }
    return 0;
}