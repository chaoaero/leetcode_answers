/*==================================================================
*   Copyright (C) 2015 All rights reserved.
*   
*   filename:     Palindrome_link_list.cc
*   author:       Meng Weichao
*   created:      2015/10/19
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
        bool isPalindrome(ListNode* head) {
            if(head == NULL)
                return true;
            ListNode *fake_head = new ListNode(-1);
            ListNode *p = new ListNode(-1);
            ListNode *q = new ListNode(-1);
            ListNode *pre = NULL;
            ListNode *next = new ListNode(-1);
            p = head;
            q = fake_head;
            while(p != NULL) {
                q->next = new ListNode(p->val); 
                p = p->next;
                q = q->next;
            }
            fake_head = fake_head->next;
            p = head;
            q = fake_head;
            while( q != NULL) {
                cout<<q->val<<endl;
                next = q->next;
                q->next = pre;
                pre = q;
                q = next;
            }
            printList(pre);            
            q = pre;
            while(p != NULL && q != NULL) {
                if(p->val != q->val) 
                    return false;
                p = p->next;
                q = q->next;
            }
            return true;

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
        void deleteNode(ListNode* node) {
            ListNode *p = node->next;
            node->val = node->next->val;
            node->next = node->next->next;
            delete p;

        }

};
int main() {

    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *tag;
    tag = head;
    int n,m;
    cin>>n;
    cout<<"input number"<<endl;
    while(n--) {
        cin>>m;
        ListNode *p =  new ListNode(m);
        tag->next = p;
        tag =tag->next;
    }
    sol.printList(head);

    cout<<"res   "<<sol.isPalindrome(head)<<endl;
    return 0;

}
