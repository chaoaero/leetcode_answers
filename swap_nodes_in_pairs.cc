/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     swap_nodes_in_pairs.cc
 *   author:       Meng Weichao
 *   created:      2015/10/22
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
        ListNode* swapPairs(ListNode* head) {
            if(head == NULL || head->next == NULL)
                return head;
            ListNode *p = head;
            ListNode *q = head->next;
            ListNode *virt = new ListNode(0);
            virt->next = head;
            ListNode *pre = virt;
            ListNode *r, *s, *next;
            while(p && q) {
               r = q->next;
               pre->next = q;
               pre = p;
               p->next = NULL;
               q->next = p;
               if(r == NULL) {
                    break;
               }
               s = r->next;
               if(s == NULL ) {
                 pre->next = r;
                 break;
               }
               p = r;
               q = s;
            }
            p = virt->next;
            delete virt;
            return p;

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
    for(int i =2; i<= 2; i++) {
        ListNode *p = new ListNode(i);
        tag->next = p;
        tag = tag->next;
    }
    
    sol.printList(head);    
    tag = sol.swapPairs(head);
    sol.printList(tag);    
    return 0;
    
}
