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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        else if(list2==nullptr) return list1;
        else{
            if(list1->val<list2->val) {
                list1->next=mergeTwoLists(list1->next,list2);
                return list1;
            }
            else{
                list2->next=mergeTwoLists(list1,list2->next);
                return list2;
            }
        }
    }
};

int main(){
    ListNode l1(1),l2(2),l3(4);
    l1.next=&l2,l2.next=&l3;
    ListNode *p1=&l1;
    ListNode j1(1),j2(3),j3(4);
    j1.next=&j2,j2.next=&j3;
    ListNode *p2=&j1;
    Solution s;
    ListNode *r1=nullptr,*r2=nullptr;
    ListNode* p3=s.mergeTwoLists(p1,p2);
    return 0;
}