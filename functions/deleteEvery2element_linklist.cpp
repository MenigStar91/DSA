#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

class link_list{
  node *head, *tail;
  
  public:
  int size;
  link_list(){
    head=NULL;
    tail=NULL;
    size=0;
  }
  
  void insert(int element){
    node * Node=new node;
    Node->data=element;
    Node->next = NULL;
    
    if(head==NULL){
      head=Node;
      tail=Node;
    }else{
      tail->next=Node;
      tail=tail->next;
    }
    size++;
    return;
  }
  
  void display(){
    node* temp=head;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<"\n";
    return;
  }
  
  
  int del(){
    node *temp=head;
    head=head->next;
    int x=temp->data;
    free(temp);
    size--;
    return x;
  }
};

int main(){
    return 0;
}

// Problems starting from 1 to N are put side by side; Now, the first problem from the list is taken out and inserted at the end of the list, then the next problem from the front is taken out and removed.