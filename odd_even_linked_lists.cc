/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     odd_even_linked_lists.cc
 *   author:       Meng Weichao
 *   created:      2016/07/06
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

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *p = head, *q = head->next;
    ListNode *r = head->next, *s;
    while(q->next && q->next->next) {
        p->next = q->next;
        p = q->next;
        q->next = q->next->next;
        q = p->next;
    }
    if(q->next) {
        p->next = q->next;
        p = q->next;
        q->next = NULL;
    }
    p->next = r;
    return head;
}
void printList(ListNode* head) {
    ListNode *tag ;
    tag = head;
    cout<<"output the result"<<endl;
    while(tag != NULL){
        cout<<tag->val<<"\t";
        tag = tag->next;
    }
    cout<<endl;       
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *tag = head;
    for(int i = 2; i <= 8; i++) {
        ListNode *p = new ListNode(i);
        tag->next = p;
        tag = tag->next;
    }
    printList(head);
    ListNode *mm = oddEvenList(head);
    cout<<"res";
    printList(mm);
    return 0;
}
