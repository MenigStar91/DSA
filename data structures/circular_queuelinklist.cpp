#include <bits/stdc++.h>
using namespace std;

struct node {
   int data;
   struct node *next;
};
struct node *List = NULL;

// creates normal link list
void insert(int data) {
  struct node *link = (struct node*) malloc(sizeof(struct node));
  struct node *current;
  link->data = data;
  link->next = NULL;
  
  if(List==NULL){
    List=link;
    List->next=link;
    return;
  }else{
    current = List;
    while(current->next !=List)
    current=current ->next;
  }current -> next=link;
  link->next=List;
  return ;
  
}

// print elements from kth node, in circular format
void display(struct node *head, int k, int n) {
    int temp;
    struct node *ptr = head;
    if(head == NULL) {
      printf("Linked List not initialized");
      return;
    }else{
      for(int i=1;i<k;i++){
        head=head->next;
      }for(int i=0;i<n;i++){
        cout<<head->data<<" ";
        head=head->next;
      }
    }
}

int main(){
    return 0;
}