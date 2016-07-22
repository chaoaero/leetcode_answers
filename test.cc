/*==================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename:     test.cc
*   author:       Meng Weichao
*   created:      2016/01/08
*   description:  
*
================================================================*/
#include<iostream>
#include<queue>
#include<stdint.h>
using namespace std;

class Stack {
private:
    queue<int> a_;
    queue<int> b_;
    queue<int> *p; 
    queue<int> *q;
public:
    Stack() {
        p = &a_;
        q = &b_;
    }
    void swap(queue<int> *m, queue<int> *n) {
        queue<int> *temp;
        temp = m;
        m = n;
        n = temp;
    }
    // Push element x onto stack.
    void push(int x) {
        p->push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(p->size() > 1) {
            int temp = p->front();
            p->pop();
            q->push(temp);
        }
        p->pop();
        swap(p, q);
    }

    // Get the top element.
    int top() {
        while(p->size() > 1) {
            int temp = p->front();
            p->pop();
            q->push(temp);
        }
        int res = p->front();
        q->push(res);
        p->pop();
        swap(p, q);
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return p->empty() && q->empty();
    }
};
int main() {
    uint32_t m = 1;
    cout<<(m|0)<<endl;
    int *p;
    int **q;
    cout<<sizeof(p)<<sizeof(q)<<endl;
    return 0;

}
