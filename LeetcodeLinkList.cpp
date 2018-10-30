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

/*********************** 328. Odd Even Linked List / 86. Partition List /445. Add Two Numbers II *************************/
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
  
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1,s2;
        ListNode* res=NULL;
        ListNode* result=NULL;
        int flag=0;
        int temp=0;
        int i,j;
        while(l1!=NULL){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            s2.push(l2->val);
            l2=l2->next;
        }
        while(!s1.empty()&&!s2.empty()){
            i=s1.top();
            j=s2.top();
            s1.pop();
            s2.pop();
            temp=i+j+flag;
            flag=temp/10;
            res=new ListNode(temp%10);
            res->next=result;
            result=res;
        }
        while(!s1.empty()){
            i=s1.top();
            s1.pop();
            temp=i+flag;
            flag=temp/10;
            res=new ListNode(temp%10);
            res->next=result;
            result=res;
        }
        while(!s2.empty()){
            j=s2.top();
            s2.pop();
            temp=j+flag;
            flag=temp/10;
            res=new ListNode(temp%10);
            res->next=result;
            result=res;
        }
        if(flag!=0){
            res=new ListNode(flag);
            res->next=result;
            result=res;
        }
        return result;
    }
};
