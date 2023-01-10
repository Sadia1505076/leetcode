// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]



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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* previous = NULL;
        while (head -> next != NULL) {
            if (head -> next -> next == NULL) {
                head -> next -> next = head;
                ListNode* temp = head -> next;
                head -> next = previous;
                head = temp;
                break;
            }
            ListNode* temp1 = head -> next -> next;
            head -> next -> next = head;
            ListNode* temp2 = head -> next;
            head -> next = previous;
            previous = temp2;
            head = temp1;
        }
        if (head -> next == NULL) head -> next = previous;
        return head;
    }
};