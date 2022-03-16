
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string s1[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string s2[11]={"","","shi","bai","qian","wan","shi","bai","qian","yi","shi"};
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0'&&s[i+1]!='0'&&i!=s.length()-1)//要输出零的情况
		{
			cout<<" ling";
		}
		else if(s[i]=='0'&&s[i+1]=='0'&&i!=s.length()-1)//避免输出多余的零
		{
			continue;
		}
		else if(i==s.length()-1&&s[i]=='0')//末尾为零的情况
			continue;
		else
		{
			if(i!=0)
				cout<<' ';
			if(s1[s[i]-'0']=="yi"&&s2[s.length()-i]=="shi")//yishi的情况
			{
                for(int j=i-1;j>=0;j--) if(s[j]!='0') {cout<<s1[1]<<" ";break;}
				cout<<s2[s.length()-i];
			}
			else
			{
				cout<<s1[s[i]-'0'];
				if(s2[s.length()-i]!="")
					cout<<' '<<s2[s.length()-i];
			}
		}
	}
    return 0;
}