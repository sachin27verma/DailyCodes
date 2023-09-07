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
    int getDecimalValue(ListNode* head) {
        
        int ct=0;
        ListNode * temp=head;
        while(temp)
        {
            ct++;
            temp=temp->next;
        }
        int ans=0;
        int i=1;

        while(head)
        {
            ans+=((head->val)*pow(2,(ct-i)));
            head=head->next;
            i++;
        }
        return ans;
    }
};