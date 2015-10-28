/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     remove_duplicates_from_sorted_list.cc
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
        ListNode* deleteDuplicates(ListNode* head) {
            if(head == NULL || head->next == NULL)
                return head;
            ListNode *p;
            ListNode *virt = new ListNode(-1);
            virt->next = head;
            ListNode *pre = virt;
            p = head;
            while(p && p->next ) {
                if(p->val == p->next->val) {
                    while(p->next && p->val == p->next->val)
                        p = p->next;
                    pre->next = p->next;
                    p = p->next;
                } else {
                    pre = p;
                    p = p->next;
                }
            }

            head = virt->next;
            delete virt;
            return head;
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
    ListNode *head = new ListNode(-3);
    ListNode *tag ;
    tag = head;
    int n,m;
    cin>>n;
    while(n--) {
    //for(int i =2; i<= 5; i++) {
        cout<<"\ninput numb:"<<endl;
        cin>>m;
        ListNode *p = new ListNode(m);
        tag->next = p;
        tag = tag->next;
    }

    sol.printList(head);    
    tag = sol.deleteDuplicates(head);
    sol.printList(tag);    
    return 0;

}
