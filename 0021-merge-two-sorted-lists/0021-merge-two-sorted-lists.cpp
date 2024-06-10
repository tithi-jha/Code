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
    ListNode* solve(ListNode* list1, ListNode* list2){
        //if first list has only one node then point its next to the entire second list
        if(list1->next==NULL){
           list1->next=list2;
           return list1;
        }

        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp1next=temp1->next;
        ListNode* temp2next=temp2->next;

        while(temp1next!=NULL && temp2!=NULL){
            if((temp1->val<=temp2->val) && (temp2->val<=temp1next->val)){
                //assigning pointers
                temp1->next=temp2;
                temp2next=temp2->next;
                temp2->next=temp1next;
                //updating poinet
                temp1=temp2;
                temp2=temp2next;
            }  

            else{
            temp1=temp1next;
            temp1next=temp1next->next;
            }
            if(temp1next==NULL){
                temp1->next=temp2;
                return list1;
            }
        }
        return list1;
    }
    

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         if(list1==NULL)
         return list2;

         if(list2==NULL)
         return list1;

         if(list1->val<=list2->val){
             return solve(list1,list2);
         }
         else{
             return solve(list2,list1);
         }
      }    
};













