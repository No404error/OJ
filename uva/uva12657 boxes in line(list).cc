#include<bits/stdc++.h>
using namespace std;
int m,n,inv,i,a,b,c,num=0;
int main(){
    while(scanf("%d%d",&m,&n)==2){
        list<int> l(m); //定义一个链表
        vector<list<int>::iterator> v(m+1); //定义一个存放链表位置的数组
        i=1,inv=0;
        for(auto p=l.begin();p!=l.end();p++,i++){ //链表用来存放数，数组来存放位置
            *p=i;
            v[i]=p;
        }
        for(i=0;i<n;i++){
            scanf("%d",&a);
            if(a==4)  inv=!inv; //inv是反转标志 分层考虑了输入位数
            else{
                scanf("%d%d",&b,&c);
                if(a==3) swap(*v[b],*v[c]),swap(v[b],v[c]); //无论是否反转，直接交换都是成立的
                else{
                    if(inv) a=3-a; //反转的话，1，2操作需要调换1->2,2->1;
                    l.erase(v[b]); //把被操作数删除
                    auto p=v[c];
                    if(a==2) p++; //调整插入位置
                    v[b]=l.insert(p,b); //插入，位置也随之改变
                }
            }
        }
        long long oddsum=0,cnt=1;
        for(auto p=l.begin();p!=l.end();p++,cnt++){ //计算奇数位上的总和
            if(cnt&1) oddsum+=*p; 
        } //当总数为奇数个数时奇数和等于反转后的奇数和，偶数还反转时需要求奇数和的补数
        printf("Case %d: %lld\n",++num,(inv&&!(m&1))?(long long)m*(m+1)/2-oddsum:oddsum);
    }
    return 0;
}