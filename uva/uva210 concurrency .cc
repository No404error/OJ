#include<bits/stdc++.h>
using namespace std;
int T,a[7];
string t,ans;
int main(){
    cin>>T;for(int p=0;p<T;p++){
        for(int i=0;i<7;i++) cin>>a[i]; //存放七位数
        queue<string> q[a[0]];deque<int> qr;queue<int> qb;map<string,string> mp;bool islock=false;
        getchar(); //定义存放指令的栈数组，存放运行程序的双端队列，储存变量值的映射，还有记录lock状态的bool
        for(int i=0;i<a[0];i++) {
            while(getline(cin,t)&&t!="end") q[i].push(t); //存放指令
            qr.push_back(i); 
        }
        if(p) cout<<endl; //输出格式
        while(!qr.empty()){ //运行队列不为空
            int k=qr.front();qr.pop_front(); //提取第一个程序号
            bool isBlock=false; //堵塞状态为false
            for(int i=0;i<a[6]&&!q[k].empty();){ //时间片未满，程序未运行完毕
                t=q[k].front(); //从程序中拿出第一个语句
                int j=t.find('=');
                if(j!=string::npos){ //是赋值语句
                    mp[t.substr(0,j-1)]=t.substr(j+2); //添加变量
                    i+=a[1]; //增加时间
                }
                else {
                    j=t.find(' ');
                    if(j!=string::npos) { //输出语句
                        ans="0";
                        if(mp[t.substr(j+1)]!="") ans=mp[t.substr(j+1)];
                        cout<<k+1<<": "<<ans<<endl;
                        i+=a[2];
                    }
                    else if(t[0]=='l'){ //锁语句
                        if(!islock){ //还没锁就锁上
                            islock=true;
                            i+=a[3];
                        }
                        else{ //已经锁了就进入堵塞状态，把程序放入等待队列，直接结束本次运行
                            qb.push(k); 
                            isBlock=true;
                            break;
                        }
                    }
                    else if(t[0]=='u'){ //解锁语句
                        islock=false; // 解锁
                        if(!qb.empty()){ //如果等待队列还有程序就把等待队列的头拿出来放在运行队列的头上
                            qr.push_front(qb.front());
                            qb.pop();
                        }
                        i+=a[4];
                    }
                }
                q[k].pop(); //放在这为了防止堵塞状态删除lock语句
            }
            if(!isBlock&&!q[k].empty()) qr.push_back(k); //在非堵塞状态和程序非空的情况下把程序号放到队列尾
        }
    }
    return 0;
}