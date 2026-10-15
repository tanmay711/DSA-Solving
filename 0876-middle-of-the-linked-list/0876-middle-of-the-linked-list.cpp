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
        ListNode* dummy = head;
        int count=0;
        while(dummy != NULL)
        {
            count++;
            dummy = dummy->next;

        }
        count = count/2;
        ListNode* dummy2 = head;
        int i=0;
        while(i<count)
        {
            dummy2 = dummy2->next;
            i++;
        }
        return dummy2;
    }
};