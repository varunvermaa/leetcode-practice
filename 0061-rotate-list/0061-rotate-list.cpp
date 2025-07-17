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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL) return head;
        if(k==0) return head;
        ListNode* temp = head;
        int c = 0;
        while(temp!=NULL){
            temp = temp -> next;
            c++;
        }
        
        cout<<c;
        k = k%(c);
        if(k==c || k==0) return head;
        temp = head;
        
        for(int i = 0; i<c-k-1; i++){
            temp = temp->next;
        }
        ListNode* a = temp->next;
        ListNode* b = a;
        temp->next = NULL;
        while(a->next != nullptr){
            a = a->next;
        }
        a->next = head;
        return b;
    }
};