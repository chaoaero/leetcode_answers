/*==================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename:     lru_cache.cc
*   author:       Meng Weichao
*   created:      2016/03/15
*   description:  
*
================================================================*/
#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;
class LRUCache{
public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
    };
    typedef struct Node Node;
private:
    int cap_;
    Node* head_;
    int usage_;
    map<int, Node*> cache_map_;
public:
    LRUCache(int capacity) {
        cap_ = capacity;
        usage_ = 0;
        head_ = (Node *)malloc(sizeof(Node));
        head_->next = head_;
        head_->prev = head_;
    }

    void node_remove(Node* p) {
        p->next->prev = p->prev;
        p->prev->next = p->next;
    }
    
    void node_append(Node *p) {
        p->next = head_;
        p->prev = head_->prev;
        p->prev->next = p;
        p->next->prev = p;
    }
    
    int get(int key) {
        if(cache_map_.count(key) > 0) {
            Node* tmp = cache_map_[key];
            node_remove(tmp);
            node_append(tmp);
            //int res = tmp->val;
            return tmp->val;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(cache_map_.count(key) > 0) {
            Node* tmp = cache_map_[key];
            tmp->val = value;
            node_remove(tmp);
            node_append(tmp);
            return;
        }
        Node *p = (Node *)malloc(sizeof(Node));
        p->key = key;
        p->val = value;
        node_append(p);
        cache_map_[key] = p;
        usage_++;
        if(usage_ > cap_) {
            Node* tmp = head_->next;
            node_remove(tmp);
            cache_map_.erase(tmp->key);
            usage_--;
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.set(2,1);
    cache.set(1,1);
    cache.set(2,3);
    cache.set(4,1);
    cout<<cache.get(1)<<endl;
    cout<<cache.get(2)<<endl;
    return 0;
}
