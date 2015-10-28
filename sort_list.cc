/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     sort_list.cc
 *   author:       Meng Weichao
 *   created:      2015/10/26
 *   description:  
 *
 ================================================================*/
#include<iostream>
#include<climits>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(0);
    ListNode *p = new ListNode();
    ListNode *q = new ListNode();
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

ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *slow = head, *fast = head, *righthead;
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    righthead = slow->next;
    slow->next = NULL;
    ListNode *left = sortList(head);
    ListNode *right = sortList(righthead);
    ListNode *new_head = mergeTwoLists(left, right);
    return new_head;
}

int main() {

}
