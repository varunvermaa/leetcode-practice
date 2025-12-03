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
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode* ta = list1;
        ListNode* tb = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* d = dummy;
        while(ta!=NULL && tb!=NULL){
            if(ta->val < tb->val){
                ListNode* a = new ListNode(ta->val);
                d->next=a;;
                d=d->next;
                ta = ta->next;
            } else {
                ListNode* a = new ListNode(tb->val);
                d->next=a;
                d=d->next;
                tb = tb->next;
            }
        }
        if(ta==NULL){
                d->next = tb;
            } else{
                d->next = ta;
            }
        return dummy->next;
         
    }
};