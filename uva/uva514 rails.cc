#include<bits/stdc++.h>
using namespace std;
int N[1005]; //存放输入的状态
int main(){
    int t;
    while(cin>>t&&t){
        while(cin>>N[1]&&N[1]){ //当第一位为零时退出
            for(int i=2;i<=t;i++) cin>>N[i];
            stack<int> s;
            bool ok=true; //是否符合要求
            for(int i=1,j=1;i<=t;){ //j为一个1 2 3 4...的排列
                if(j==N[i]) {i++,j++;} //排列的元素和储存的元素一致时不入栈
                else if(!s.empty()&&s.top()==N[i]) {s.pop();i++;} //栈不为空，栈顶的元素与排列的元素一致时相互抵消
                else if(j<=t) s.push(j++); //排列没到头时向栈中存放
                else {ok=false;break;} //都不行就是不行了
            }
            printf("%s\n",ok?"Yes":"No");
        }
        cout<<endl;
    }
    return 0;
}