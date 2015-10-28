/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     remove_nth_node_from_end_of_list.cc
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            int count = 0, dis = n;
            ListNode *virt = new ListNode(-1);
            ListNode *p, *q, *r;
            virt->next = head;
            p = head;
            q = head;
            r = virt;
            while(dis > 1) {
                q = q->next;
                dis--;
            }
            while(q->next != NULL) {
                r = r->next;
                q = q->next;
                p = p->next;
            }
            if(n == 1) {
                r->next = NULL;
            } else
                deleteNode(p);
            if(virt->next == NULL) {
                delete virt;
                delete p, q, r;
                return NULL;
            } 
            delete virt, p, q, r;
            return head;
        }
        void deleteNode(ListNode* node) {
            ListNode *p = node->next;
            node->val = node->next->val;
            node->next = node->next->next;
            delete p;

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
    tag = sol.removeNthFromEnd(head, 2);
    sol.printList(tag);    
    return 0;

}
