#include<iostream>
#include<algorithm>
using namespace std;
int cost[100];
int pos=0;
int sum=0;
int main(){
    cin>>pos;
    for(int i=0;i<pos;i++){
        cin>>cost[i];
    }

    sort(cost,cost+pos);

    for(int i=1;i<pos;i++){
        sum+=cost[i]+cost[i-1];
        cost[i]+=cost[i-1];
        sort(cost+i,cost+pos);
    }
    printf("%d",sum);
    return 0;
}