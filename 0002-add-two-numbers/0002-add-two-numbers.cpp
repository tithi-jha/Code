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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummy=new ListNode();
//         ListNode* temp=dummy;
//         ListNode* head1=l1;
//         ListNode* head2=l2;
//         int count=0;
//         int sum1=0;
//         int sum2=0;

//        while(head1!=NULL){
//            count++;
//            head1=head1->next;
//        }
//        head1=l1;
//        int count1=count;
//        int count2=count;

//        while(count1>0){
//            sum1+=head1->val*(pow(10,count1-1));
//            count1--;
//            head1=head1->next;
//        }

//        while(count2>0){
//            sum1+=head2->val*(pow(10,count2-1));
//            count2--;
//            head2=head2->next;
//        }

//        int sum=sum1+sum2;
//        int i=1;
//        while(i<=count){
//            int data = (sum % static_cast<int>(pow(10, i))) / static_cast<int>(pow(10, i - 1));
//            ListNode* newnode=new ListNode(data);
//            temp->next=newnode;
//            temp=temp->next;
//            i++;
//            count--;
//        }
//        return dummy->next;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();//output linked list
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=0;
            //lets take first example
            if(l1!=NULL){
                sum+=l1->val;//sum=2
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;//sum=2+5=7
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;//carry=0
            ListNode* newnode=new ListNode(sum%10);//new node is created with 7%10=7
            //we are using mod cuz if there is carry then 18%10=8 is inserted in node
            temp->next=newnode;//dummy->next=newnode, dummy node(1st node) is empty
            temp=temp->next;
        }
        temp = dummy;//since the first node is empty we delete it
        dummy = dummy->next;   
        delete temp;   
        return dummy; 
    }
};
