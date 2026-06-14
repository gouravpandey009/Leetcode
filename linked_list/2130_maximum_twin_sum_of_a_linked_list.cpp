#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x)
        : val(x), next(nullptr) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;

        while (slow) {

            ListNode* nextNode = slow->next;

            slow->next = prev;
            prev = slow;

            slow = nextNode;
        }

        int answer = 0;

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {

            answer = max(
                answer,
                first->val + second->val
            );

            first = first->next;
            second = second->next;
        }

        return answer;
    }
};

int main() {

    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution obj;

    cout << obj.pairSum(head);

    return 0;
}