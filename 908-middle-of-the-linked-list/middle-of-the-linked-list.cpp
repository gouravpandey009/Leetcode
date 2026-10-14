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
    ListNode* middleNode(ListNode* head) {

        //brute force

        int count = 0;
        ListNode* curr = head;

        //total nodes

        while(curr != NULL){
            count++;
            curr = curr -> next;
        }

        //middle value

        int mid = count / 2;
        curr = head;

        //find middle node

        while(mid > 0){
            curr = curr -> next;
            mid--;
        }

        return curr;

        
    }
};