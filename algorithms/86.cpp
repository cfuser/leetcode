//INNNoVation!!!
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h = head;
        //cout << head->val << endl;
        ListNode* big = new ListNode(0), *bh = big;
        ListNode* small = new ListNode(0), *sh = small;
        while (h != NULL)
        {
            if (h->val >= x)
            {
                ListNode* temp = new ListNode(h->val);
                big->next = temp;
                big = temp;
            }
            else
            {
                ListNode* temp = new ListNode(h->val);
                small->next = temp;
                small = temp;
            }
            h = h->next;
        }
        small->next = bh -> next;
        return sh->next;
    }
};