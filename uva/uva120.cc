#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<cstring>
using namespace std;

const int maxn=32;
int buf[maxn],lis[maxn];
int N,n,pos;
string line;
int main(){
    while(getline(cin,line)){
        cout<<line<<endl;
        stringstream s(line);
        for(n=0;s>>buf[n];n++);
        memcpy(lis,buf,sizeof(lis));
        sort(lis,lis+n,[](int a,int b){return a>b;});
        for(int i=0;i<n;i++){
            pos=find(buf,buf+n-i,lis[i])-buf;
            if(pos!=n-i-1){
                if(pos){
                    printf("%d ",n-pos);
                    reverse(buf,buf+pos+1);
                }
                printf("%d ",i+1);
                reverse(buf,buf+n-i);
            }
        }
        puts("0");
    }
    return 0;
}