// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

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
    bool isPalindrome(ListNode* head) {
        stack<int> elements;
        ListNode* dupHead = head;
        while (head != NULL) {
            elements.push(head->val);
            if (head -> next != NULL)
                head = head -> next;
            else break;
        }
        while (!elements.empty() && dupHead != NULL) {
            if(elements.top() != dupHead->val) return false;
            elements.pop();
            if (dupHead -> next != NULL)
                dupHead = dupHead -> next;
            else break;
        }
        return true;
    }
};