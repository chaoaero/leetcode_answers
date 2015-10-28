/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     add_two_numbers.cc
 *   author:       Meng Weichao
 *   created:      2015/10/23
 *   description:  
 *
 ================================================================*/
// big number add ,subtract
#include<iostream>
#include<cmath>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;
            ListNode *p, *q;
            ListNode *virt = new ListNode(-1);
            while(p && q) {
                int sum = p->val + q->val + carry;
                ListNode *temp = new ListNode(p->val + q->val + ca);
            }
        }

        int ListToNum(ListNode *head) {
            int count = 0;
            int base = 0;
            ListNode *p = head, *next;
            while(p) {
                count += p->val * pow(10, base++);
                p = p->next;
            }
            return count;
        }
        ListNode *NumToList(int m) {
            int count;
            if(m == 0) {
                ListNode *head = new ListNode(0);
                return head;
            }
            ListNode *virt = new ListNode(-1);
            ListNode *p = virt;
            while(m) {
                int res = m % 10;
                ListNode *temp = new ListNode(res); 
                p->next = temp;
                p = temp;
                m = m / 10;
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
    ListNode *virt = new ListNode(-1);
    ListNode *tag;
    tag = virt;
    int m, n;
    cin>>n;
    while(n--) {
        cin>>m;
        ListNode *p = new ListNode(m);
        tag->next = p;
        tag = tag->next;
    }
    ListNode *head = virt->next;
    sol.printList(head);    
    int ff = sol.ListToNum(head);
    cout<<ff<<endl;
    ListNode *ggg = sol.NumToList(10);
    sol.printList(ggg);
    return 0;

}
