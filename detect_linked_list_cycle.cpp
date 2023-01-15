// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
// Do not modify the linked list.

// Example:
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// Time and memory complexity both O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> valueWithAccessCount;
        while(head != NULL && head -> next != NULL) {
            auto keyValue = valueWithAccessCount.find(head);
            if (keyValue == valueWithAccessCount.end()) {
                // not found
                valueWithAccessCount.insert({head, 1});
                head = head -> next;
                continue;
            }
            return head;
        }
        return NULL;
    }
};

// Floyd's algorithm - also called the hare and tortoise algo - gives O(1) space complexity
//https://youtu.be/PvrxZaH_eZ4