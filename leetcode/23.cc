#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> vec=lists;
        ListNode *head=new ListNode(0,nullptr);
        ListNode *tempNode=head;

        map<int,int> order;
        for(auto list:vec){
            while(list!=nullptr){
                order[list->val]++;
                list=list->next;
            }
        }

        for(map<int,int>::iterator iter=order.begin();iter!=order.end();iter++){
            int val= (*iter).first;
            int times=(*iter).second;

            for(int i=0;i<times;i++){
                ListNode* node=new ListNode(val);
                tempNode->next=node;
                tempNode=tempNode->next;
            }

        }
        return head->next;
    }
};

int main(){
    Solution solution;
    vector<ListNode*> vec={new ListNode(21)};
    solution.mergeKLists(vec);
    return 0;
}