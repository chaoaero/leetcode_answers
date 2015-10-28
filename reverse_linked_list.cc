/*==================================================================
*   Copyright (C) 2015 All rights reserved.
*   
*   filename:     reverse_linked_list.cc
*   author:       Meng Weichao
*   created:      2015/10/14
*   description:  
*
================================================================*/
#include<iostream>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;
class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if(m == n ) 
                return head;
            ListNode *virt_head = new ListNode(0);
            virt_head->next = head;
            ListNode *cur = new ListNode(0);
            ListNode *trunc = new ListNode(0);
            ListNode *trunc_next = new ListNode(0);
            ListNode *pre = NULL;
            ListNode *next = NULL;
            cur =virt_head;
            int count = 0;
            while(count < m) {
                trunc = cur;
                cur = cur->next;
                count++;
            }
            trunc_next = cur;
            while(count <= n) {
                next = cur->next;                
                cur->next = pre;
                pre = cur;
                cur = next;
                count++;
            }
            trunc_next->next = cur;
            trunc->next = pre;
            cur = virt_head->next;
            delete virt_head, trunc, trunc_next, pre, next;
            return cur;
        }
        void printList(ListNode* head) {
            ListNode *tag = new ListNode(0);
            tag = head;
            cout<<"output the result"<<endl;
            while(tag != NULL){
                cout<<tag->val<<"\t";
                tag = tag->next;
            }
            cout<<endl;       
        }
};

int main() {

    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *tag;
    tag = head;
    for(int i =2; i<= 5; i++) {
        ListNode *p = new ListNode(i);
        tag->next = p;
        tag = tag->next;
    }
    
    sol.printList(head);    
    tag = sol.reverseBetween(head, 2, 4);
    sol.printList(tag);    
    return 0;
    
}
