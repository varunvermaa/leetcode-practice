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
        if(head == NULL) return NULL;
        if(head->next == head) return head;
        else if(head->next == NULL) return NULL;
        
        ListNode* s = head;
        ListNode* f = head;
         while(f){
            
            s = s->next;
            if(f->next == NULL) return NULL;
            f = f->next->next;
            if(s == f) break;
        }
        if (s != f) return NULL; 
        ListNode* temp = head;
        while(temp!=s){
            temp = temp->next;
            if(s->next != NULL)
            s = s->next;
        }
        return temp;
    }
    
};