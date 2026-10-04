/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *c = head, *p = nullptr, *n = nullptr;
        while(c != nullptr) n = c->next, c->next = p, p = c, c = n;
        return p;
    }

    void reorderList(ListNode* h1) {
        if (!h1 || !h1->next) return;

        ListNode *s = h1, *f = h1;
        while (f->next && f->next->next) s = s->next, f = f->next->next;

        ListNode *h2 = reverse(s->next);
        s->next = nullptr;

        ListNode *t1 = h1, *t2 = h2;

        while (t1 != nullptr && t2 != nullptr) {
            ListNode *n1 = t1->next;
            ListNode *n2 = t2->next;

            t1->next = t2;
            t2->next = n1;

            t1 = n1;
            t2 = n2;
        }
    }
};
