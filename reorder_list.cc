/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     reorder_list.cc
 *   author:       Meng Weichao
 *   created:      2015/10/20
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
        void reorderList(ListNode* head) {
            if(head == NULL || head->next == NULL)
                return;
            int len = length(head);
            int half_len;
            if(len %2 == 0)
                half_len = len/2;
            else
                half_len = len/2 + 1;
            ListNode *p = head;
            int count = 0;
            while(count < half_len -1) {
                count++;
                p = p->next;
            }
            ListNode *q = p->next;
            p->next = NULL;
            // revert the second half link list
            ListNode *next;
            ListNode *pre = NULL;
            while(q != NULL) {
                next = q->next;
                q->next = pre;
                pre = q;
                q = next;
            }
            ListNode *r = pre;
            p = head;
            ListNode *p_next, *r_next;
            while(p != NULL && r != NULL) {
                p_next = p->next;
                r_next = r->next;
                p->next = r;
                r->next = p_next;
                r = r_next;
                p = p_next;
            }
            return;
        }

        int length(ListNode *head) {
            int count = 0;
            ListNode *p = head;
            while(p != NULL) {
                count++;
                p = p->next;
            }
            return count;
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
    sol.reorderList(head);
    sol.printList(head);    
    return 0;
    
}
