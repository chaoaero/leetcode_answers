/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     merge_two_list.cc
 *   author:       Meng Weichao
 *   created:      2015/10/16
 *   description:  
 *
 ================================================================*/
#include<iostream>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
} ListNode;
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {

        }
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *head = new ListNode(0);
            ListNode *p = new ListNode(0);
            ListNode *q = new ListNode(0);
            ListNode *cur = head;
            p = l1;
            q = l2;
            while(p != NULL && q != NULL) {
                if(p->val < q->val) {
                    cur->next = p;
                    p = p->next;
                } else {
                    cur->next = q;
                    q = q->next;
                }
                cur = cur->next;
            }
            if(p == NULL)
                cur->next = q;
            else
                cur->next = p;
            cur = head->next;
            delete head;
            return cur;
        }
        void printList(ListNode* head) {
            ListNode *tag = new ListNode();
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

}
