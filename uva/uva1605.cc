#include<iostream>
using namespace std;

char Id(int id){
    return id<26?id+'a':(id-26)+'A';
}
void print(int n,int tag){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%c",Id((tag==1)?i:j));
        puts("");
    }
}
int main(){
    int N,flag=0;
    while(scanf("%d",&N)==1){
        if(flag++!=0) puts("");
        printf("%d %d %d\n",2,N,N);
        print(N,1);puts("");print(N,2);
    }
    return 0;
}