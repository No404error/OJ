#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int sumt[maxn];
void build(int p){
    int t;cin>>t;
    if(t==-1) return;
    sumt[p]+=t;
    build(p-1);build(p+1);
}
bool init(){
    int t;cin>>t;
    if(t==-1) return false;
    memset(sumt,0,sizeof(sumt));
    int pos=maxn/2;
    sumt[pos]=t;
    build(pos-1);build(pos+1);
    return true;
}
int main(){
    int kase=1,p;
    while(init()){
        p=0;
        while(!sumt[p]) p++;
        cout<<"Case "<<kase++<<":\n"<<sumt[p++];
        while(sumt[p]!=0) cout<<" "<<sumt[p++];
        cout<<"\n\n";
    }
    return 0;
}