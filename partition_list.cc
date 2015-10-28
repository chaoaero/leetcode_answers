/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     partition_list.cc
 *   author:       Meng Weichao
 *   created:      2015/10/21
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
        ListNode* partition(ListNode* head, int x) {
            if(head == NULL || head->next == NULL)        
                return head;
            ListNode *virt = new ListNode(-1); 
            virt->next = head;
            ListNode *pre = virt, *p_next;
            ListNode *p,*q, *next, *r = head;
            p = pre;
            q = pre;
            while(r) {
                next = r->next;
                int m = r->val;
                if( m >= x ) {
                    q = r;
                    r = next;
                } else {
                    p_next = p->next; 
                    if(p_next == r) {
                        p = r;
                        q = r;
                        r = next;
                    } else {
                        p->next = r;
                        r->next = p_next;
                        p = p_next;
                        p = r;
                        q->next = next;
                        r = next;
                    }
                }
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
    int m, n;
    cin>>n;
    while(n--) {
   cin>>m;
   ListNode *p = new ListNode(m);
   tag->next = p;
   tag = tag->next;
    }
    //for(int i =2; i<= 5; i++) {
    //    ListNode *p = new ListNode(i);
    //    tag->next = p;
    //    tag = tag->next;
    //}
    
    sol.printList(head);    
    tag = sol.partition(head, 3 );
    sol.printList(tag);    
    return 0;
    
}
