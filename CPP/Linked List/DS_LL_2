//Reverse Linked List using Recursion

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
  ListNode* reverseList(ListNode * head){
       //base case
       if(head == NULL || head->next == NULL){
          return head;
       }
       
       ListNode* smallList(head->next);
       ListNode* temp = smallList;
       while(temp != NULL){
       temp = temp->next;
       }
       
       temp->next = head;
       head->next = NULL;
       
       return smallList;

}


