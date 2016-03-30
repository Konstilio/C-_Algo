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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* next = head->next->next;    
        ListNode *newHead = head->next;
        newHead->next = head;
        head->next = next;
        
        ListNode* it = head;
        
        while (it->next && it->next->next)
        {
           ListNode* mid = it->next;
           ListNode* last = it->next->next->next;
           
           it->next = it->next->next;
           it->next->next = mid;
           mid->next = last;
           it = it->next->next;
        }
        
        return newHead;
        
        
    }