/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     convert_sorted_list_to_binary_search_tree.cc
 *   author:       Meng Weichao
 *   created:      2015/10/27
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

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

TreeNode* sortedListToBST(ListNode* head) {
    if(head == NULL)
        return NULL;
    else if(head->next == NULL) {
        return new TreeNode(head->val);    
    }
    ListNode *fast = head, *slow = head, *pre = NULL;
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        pre = slow;
        slow = slow->next;
    }
    if(pre != NULL)
        pre->next = NULL;
    ListNode *right_head = slow->next;
    TreeNode *parent = new TreeNode(slow->val);
    slow->next = NULL;
    TreeNode *left_child = sortedListToBST((pre == NULL ? NULL : head));
    TreeNode *right_child = sortedListToBST(right_head);
    parent->left = left_child;
    parent->right = right_child;
    return parent;
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *tag;
    tag = head;
    for(int i =2; i<= 5; i++) {
        ListNode *p = new ListNode(i);
        tag->next = p;
        tag = tag->next;
    }
    
//    sol.printList(head);    
    TreeNode *woca = sortedListToBST(head);
    return 0;

}
