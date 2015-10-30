/*==================================================================
 *   Copyright (C) 2015 All rights reserved.
 *   
 *   filename:     copy_list_with_random_pointer.cc
 *   author:       Meng Weichao
 *   created:      2015/10/28
 *   description:  
 *
 ================================================================*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include<iostream>
#include <unordered_map>
using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            if(head == NULL) {
                return head;
            }
            RandomListNode *virt_head = new RandomListNode(-1);
            RandomListNode *p, *q;
            p = head;
            q = virt_head;
            unordered_map<RandomListNode*, RandomListNode*> node_map;
            while(p != NULL) {
                RandomListNode *temp = new RandomListNode(p->label);
                q->next = temp;
                q = temp;
                node_map[p] = q;
                p = p->next;
            }
            q = virt_head->next;
            p = head;
            while(p != NULL) {
                RandomListNode *t = p->random;
                if(t != NULL) {
                    q->random = node_map[t];
                }
                q = q->next;
                p = p->next;
            }
            q = virt_head->next;
            delete virt_head;
            return q;

        }
};
