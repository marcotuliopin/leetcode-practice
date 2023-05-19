struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode;
        ListNode *it = l3;
        ListNode *it1 = new ListNode(0, l3);
        int aux;

        while (l1 && l2) {
            it->val = l1->val + l2->val + it1->val/10;
            it1->val %= 10;

            l1 = l1->next;
            l2 = l2->next;
            if (l1 || l2) {
                it->next = new ListNode;
                it = it->next;
                it1 = it1->next;
            }

        }
        while (l1) {
            it->val = l1->val + it1->val/10;
            it1->val %= 10;

            l1 = l1->next;
            if (l1) {
                it->next = new ListNode;
                it = it->next;
                it1 = it1->next;
            }
        }
        while (l2) {
            it->val = l2->val + it1->val/10;
            it1->val %= 10;

            l2 = l2->next;
            if (l2) {
                it->next = new ListNode;
                it = it->next;
                it1 = it1->next;
            }
        }
        
        if (it->val >= 10)
        {
            it->next = new ListNode(it->val/10);
            it->val %= 10;
        }

        return l3;
    }
};