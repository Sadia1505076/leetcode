// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// This is basically merge part of the mergeSort algorithm

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) return NULL;
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* merged_head = new ListNode(-9999);
        ListNode* merged_pointer = new ListNode(-9999);

        while (list1 != NULL) {
            if (list2 == NULL) break;
            ListNode* temp = new ListNode(-9999);
            temp -> next = NULL;
            if (list1 -> val < list2 -> val) {
                temp -> val = list1 -> val;
                list1 = list1 -> next;
            }
            else {
                temp -> val = list2 -> val;
                list2 = list2 -> next;
            }
            if (merged_pointer -> val == -9999) {
                merged_head = temp;
            }
            merged_pointer -> next = temp;
            merged_pointer = temp;
        }
        if (list1 != NULL) merged_pointer -> next = list1;
        else if (list2 != NULL) merged_pointer -> next = list2;
        return merged_head;
    }
};