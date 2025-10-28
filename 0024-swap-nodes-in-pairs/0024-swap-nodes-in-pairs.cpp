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
    ListNode* swapPairs(ListNode* head) {
        if(!head || head->next == NULL) return head;
        ListNode* p = NULL;
        ListNode* m = head;
        ListNode* n = head->next;
        ListNode* t = n->next;

        while(m && n){
            n->next = m;
            m->next = t;
            if(p!=NULL) p->next = n;
            else head = n;
            p = m;
            m = t;
            if(m!=NULL) n = m->next;
            else n = m;
            if(n!=NULL) t = n->next;
            else m = NULL;
        }
        return head;
    }
};