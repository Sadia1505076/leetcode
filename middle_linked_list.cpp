// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

//--------------- my solution ----------------------
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* middle_pointer = head;
        int count = 1;
        while (head -> next != NULL) {
            head = head -> next;
            count++;
            if (count % 2 == 0) middle_pointer = middle_pointer -> next;
        }
        return middle_pointer;
    }
};


//------------- better one -------------------------
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
}