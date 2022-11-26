#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string ans_s,tmp_s,cin_s;
int n,k,dif,ans_cost,tmp_cost;
int count[10];

/**
 * 贪心
 * 从k个0的靓号开始测试,到k个1...规定构成靓号的位值为x
 * 转变时要注意最小代价,字典序
 * 最小代价:可由delta=1(距离x的远近)开始修改,再delta=2...直到满足k个x的条件
 * 字典序:在修改比x大的值时从数的右侧开始(保证字典序向小变换的最多),再修改比x小的时候从数的左边开始(保证字典序向大变换的最少)
*/

//将串的所有值为beChange的位改为will值，并记录转变后的cost
void changeAllBitValue(string& s,int will,int beChange){
    for(int i=0;i<n;i++){
        if(s[i]==beChange+'0'){
            dif--;
            s[i]=will+'0';
            tmp_cost+=abs(will-beChange);
        }
        if(dif==0)
            break;
    }
}

int main(){
    cin>>n>>k>>cin_s;
    ans_cost=int(10e9);
    ans_s=cin_s;

    //记录所有位出现的个数
    for(int i=0;i<n;i++)
        count[cin_s[i]-'0']++;

    for(int i=0;i<10;i++){
        dif=k-count[i];
        tmp_s=cin_s;
        tmp_cost=0;
        if(dif>0)
            for(int delta=1;delta<=9;delta++){
                if(i+delta<10)
                    changeAllBitValue(tmp_s,i,i+delta);
                if(dif==0)
                    break;
                if(i-delta>=0)
                    changeAllBitValue(tmp_s,i,i-delta);
                if(dif==0)
                    break;
            }
        if(tmp_cost<ans_cost){
            ans_cost=tmp_cost;
            ans_s=tmp_s;
        }
        else if(tmp_cost==ans_cost&&tmp_s<ans_s){
            ans_s=tmp_s;
        }
        
    }
    cout<<ans_cost<<endl;
    cout<<ans_s;
    return 0;
}
