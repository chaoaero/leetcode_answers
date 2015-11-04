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
#include<vector>
#include<stdlib.h>
#include<queue>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
} ListNode;

typedef ListNode* heap_elem_t;

typedef struct heap_t {
    int size;
    int capacity;
    heap_elem_t *elems;
    int (*cmp)(const heap_elem_t*, const heap_elem_t*);
} heap_t;

int cmp_list_node(const ListNode* a, const ListNode *b) {
    const int sub = a->val - b->val;
    if(sub > 0) {
        return 1;
    } else if(sub < 0){
        return -1;
    } else {
        return 0;
    }
}

heap_t* heap_create(const int capacity, int (*cmp)(const heap_elem_t*, const heap_elem_t*)) {
    heap_t *h = (heap_t*)malloc(sizeof(heap_t));
    h->size = 0;
    h->capacity = capacity;
    h->elems = (heap_elem_t*)malloc(capacity * sizeof(heap_elem_t));
    h->cmp = cmp;
}

void heap_destroy(heap_t *h) {
    free(h->elems);
    free(h);
}

int heap_empty(const heap_t *h) {
    return h->size == 0;
}

int heap_size(const heap_t *h) {
    return h->size;
}

void heap_sift_down(const heap_t *h, const int start) {
    int i = start;
    int j;
    const heap_elem_t tmp  = h->elems[start];
    for(j = 2 * i + 1; j < h->size; j = 2 * j + 1) {
        if(j < (h->size - 1) && h->cmp(&(h->elems[j]), &(h->elems[j + 1]) ) > 0) {
            j++;
        }
        if(h->cmp(&tmp, &(h->elems[j])) <= 0) {
            break;
        } else {
            h->elems[i] = h->elems[j];
            i = j;
        }
    }
    h->elems[i] = tmp;
}

void heap_sift_up(const heap_t *h, const int start) {
    int j = start;
    int i = j / 2;
    const heap_elem_t tmp = h->elems[start];
    while(j > 0) {
        if(h->cmp(&(h->elems[j]), &tmp) <= 0 ) {
            break;
        } else {
            h->elems[j] = h->elems[i];
            j = i;
            i = (i - 1) / 2;
        }
        h->elems[j] = tmp;

    }
}

void heap_push(heap_t *h, const heap_elem_t x) {
    if(h->size == h->capacity) {
        heap_elem_t* tmp = (heap_elem_t*)realloc(h->elems, h->capacity * 2 * sizeof(heap_elem_t));
        h->elems = tmp;
        h->capacity *= 2;
    }
    h->elems[h->size] = x;
    h->size++;
    heap_sift_up(h, h->size - 1);
}

void heap_pop(heap_t *h) {
    h->elems[0] = h->elems[h->size - 1];
    h->size--;
    heap_sift_down(h, 0);
}

heap_elem_t heap_top(const heap_t *h) {
    return h->elems[0];
}


class Solution {
    public:
        class Compare {
            public:
                bool operator() (const ListNode* a, const ListNode* b) {
                    if(a->val > b->val) {
                        return true;
                    } else if(a->val < b->val) {
                        return false;
                    } else
                        return false;
                }
        };
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int size = lists.size();
            if(size == 0 )
                return NULL;
            else if(size == 1) {
                return lists.front();
            }

            ListNode *head = new ListNode(-1);
            ListNode *pre, *tmp, *next;
            pre = head;
            priority_queue<ListNode*, vector<ListNode*> , Compare> pq;
            for(vector<ListNode*>::const_iterator iter = lists.begin(); iter != lists.end(); iter++) {
                if((*iter) != NULL)
                    pq.push(*iter);
            }
            while(!pq.empty()) {
                tmp = pq.top();
                next = tmp->next;
                pre->next = tmp;
                tmp->next = NULL;
                pre = tmp;
                pq.pop();
                if(next != NULL)
                    pq.push(next);
            }
            tmp = head->next;
            delete head;
            return tmp;

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
    ListNode *new_head = new ListNode(2);
    tag = new_head;
    for(int i=2;i<=8; i++) {
        ListNode *p = new ListNode(i);
        tag->next = p;
        tag = tag->next;
    }
    vector<ListNode*> woca;
    sol.printList(head);
    sol.printList(new_head);
    woca.push_back(head);
    woca.push_back(new_head);
    ListNode *ff = sol.mergeKLists(woca);
    sol.printList(ff);    
    return 0;
}
