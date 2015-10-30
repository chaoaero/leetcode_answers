/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     reverse_nodes_in_k_group.cc
 *   author:       Meng Weichao
 *   created:      2015/10/29
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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(head == NULL || head->next == NULL || k <= 1)
                return head;
            ListNode* virt = new ListNode(-1);
            virt->next = head;
            ListNode *pre = virt;
            ListNode *p = head, *q = head, *next = NULL, *temp = NULL, *sub_pre = NULL, *sub_next = NULL;
            int count = 1;
            while(p != NULL) {
                q = p;
                count = 1;
                while(q != NULL && count < k) {
                    q = q->next;
                    count++;
                }
                if(q == NULL) {
                    pre->next = p;
                    break;
                }
                temp = p;
                sub_pre = NULL;
                sub_next = q->next;
                while(temp != sub_next) {
                    next = temp->next;
                    temp->next = sub_pre;
                    sub_pre = temp;
                    temp = next;
                }
                pre->next = q;
                pre = p;
                p = sub_next;
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
    for(int i =2; i<= 5; i++) {
        ListNode *p = new ListNode(i);
        tag->next = p;
        tag = tag->next;
    }
    
    sol.printList(head);    
    tag = sol.reverseKGroup(head, 2);
    sol.printList(tag);    
    return 0;




}
