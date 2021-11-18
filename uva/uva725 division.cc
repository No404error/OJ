#include<bits/stdc++.h>
using namespace std;
string s1,s2;
bool is_ok(int i,int j){ //两个数是否成立
    s1=to_string(i),s2=to_string(j);
    if(s1.length()<5) s1="0"+s1;
    if(s2.length()<5) s2+="0"+s2;
    bool check[10]={false};
    for(int t=0;t<5;t++){
       check[s1[t]-'0']=true;
       check[s2[t]-'0']=true;
    }
    for(int t=0;t<10;t++){
        if(!check[t]) return false;
    }
    return true;
}
int main(){
    int divisor,dividend,n,cnt=0;
    bool flag;
    while(cin>>n&&n){
        if(cnt) puts("");cnt++; //空行输出
        flag=false;
        for(divisor=1234;divisor<=98765;divisor++){ //遍历
            dividend=divisor*n;
            if(dividend>99999) break; //被除数越界
            if(is_ok(divisor,dividend)) cout<<s2<<" / "<<s1<<" = "<<n<<endl,flag=true; //输出
        }
        if(!flag)   cout<<"There are no solutions for "<<n<<"."<<endl; //输出
    }
    return 0;
}