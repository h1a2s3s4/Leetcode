/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<stack>
class Solution {
public:
    stack<ListNode*>s;
    ListNode* swapPairs(ListNode* head) {
    if(head==NULL||head->next==NULL) {
        return head;
    }
    ListNode*p=head;
    ListNode*u=NULL;
    while(p!=NULL){
        s.push(p);
        p=p->next;
        if(s.size()==2){
            if(u==NULL){
                u=s.top();
                head=u;
                s.pop();
            }
            while(!s.empty()){
                u->next=s.top();
                u=u->next;
                s.pop();
            }
        }
    }
    if(!s.empty()){
        u->next=s.top();
        u=u->next;
        s.pop();
    }
    if(u!=NULL){
        u->next=NULL;
    }
    return head;
        
    }
};