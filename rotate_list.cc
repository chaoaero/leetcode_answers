/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     rotate_list.cc
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
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL || head->next == NULL)
                return head;
            int len = length(head);
            int mod_k = k % len;
            if(mod_k == 0)
                return head;
            int prefix = len - mod_k;
            int count = 0;
            ListNode *p = head;
            while(count < prefix - 1) {
                count++;
                p = p->next;
            }
            ListNode *new_head = p->next;
            ListNode *q = new_head;
            while(q->next != NULL)
                q = q->next;
            q->next = head;
            p->next = NULL;
            return new_head;

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
    for(int i =2; i<= 3; i++) {
        ListNode *p = new ListNode(i);
        tag->next = p;
        tag = tag->next;
    }
    
    sol.printList(head);    
    tag = sol.rotateRight(head, 4);
    sol.printList(tag);    
    return 0;
}
    

