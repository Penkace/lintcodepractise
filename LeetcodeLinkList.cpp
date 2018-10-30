/************************************************************
  >File Name: Leetcode上关于LinkList的基础问题
  >Author: Peng Kai
  >Date: 2018-10-30
  >idea:关于链表的问题，可以设多个指针索引，这样在移动的时候能够快速的找到头和尾，在连接问题、大小比较、链表划分问题上都是非常实用的。
************************************************************/

struct ListNode {
  int val;
  ListNode *next;
};

/*********************** 328. Odd Even Linked List / 86. Partition List *************************/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenstart=new ListNode(0);
        ListNode* oddstart=new ListNode(0);
        ListNode* even=evenstart;
        ListNode* odd=oddstart;
        int i=1;
        while(head!=NULL){
            if(i%2==0){
                evenstart->next=head;
                evenstart=head;
            }
            else{
                oddstart->next=head;
                oddstart=head;
            }
            head=head->next;
            i++;
        }
        oddstart->next=even->next;
        evenstart->next=NULL;
        return odd->next;
    }  
    
    ListNode* partition(ListNode* head, int x) {
        ListNode* front=new ListNode(-1);
        ListNode* pre=front;
        ListNode* lesscur=new ListNode(0);
        ListNode* leftstart=lesscur;
        while(head!=NULL){
            if(head->val>=x){
                front->next=head;
                front=head;
            }else{
                lesscur->next=head;
                lesscur=head;
            }
            head=head->next;
        }
        
        lesscur->next=pre->next;
        front->next=NULL;
        return leftstart->next;
    }
};
