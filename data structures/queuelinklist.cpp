#include <bits/stdc++.h>
using namespace std;


struct node{
  int data;
  struct node* next;
};
struct node* front;
struct node* rear;

class QUEUE{
  node *front, *rear;
  
  public:
  QUEUE(){
    front=NULL;
    rear=NULL;
  }
  
  void enque(int element);
  void display();
  void peek();
  void deque();
  void reverse();

};


void QUEUE :: enque(int element){
    node * Node=new node;
    Node->data=element;
    Node->next = NULL;
    
    if(front==NULL){
      front=Node;
      rear=Node;
    }else{
      rear->next=Node;
      rear=rear->next;
    }
    return;
}

void QUEUE :: display(){
    node* temp=front;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<"\n";
    return;
}

void QUEUE :: peek(){
    cout<<front->data<<"\n";
}

void QUEUE :: deque(){
    node *ptr= front;
    front=front->next;
    free(ptr);
    return ;
}

void QUEUE:: reverse(){
  node *temp = front; 
  node *prev=NULL, *next=NULL;
  while(temp){
      next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
  }
  
  front=prev;
  return;
}


int main(){ 
    return 0;
}
