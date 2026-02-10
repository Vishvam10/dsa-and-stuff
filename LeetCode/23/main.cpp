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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();

    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };

    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

    ListNode *head = new ListNode();
    ListNode *dummy = head;

    for (int i = 0; i < n; ++i) {
      ListNode *temp = lists[i];
      while (temp != nullptr) {
        pq.push(temp);
        temp = temp->next;
      }
    }

    while (!pq.empty()) {
      dummy->next = pq.top();
      pq.pop();
      dummy = dummy->next;
      dummy->next = nullptr;
    }

    return head->next;
  }
};