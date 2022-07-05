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
  link_list(){
    head=NULL;
    tail=NULL;
  }
  
  void insert(int element);
  void display();
  void reverse();
  void swap();
  void del();
  int show(int n);
};

// insertion
void link_list:: insert(int element){
    node * Node=new node;
    Node->data=element;
    Node->next = NULL;
    
    if(head==NULL){
      head=Node;
      tail=Node;
    }else{

      // to maintain link list of only unique elements (aka delete repeating elements)
      /*
      while(ptr !=tail){
        if(ptr ->data ==element){
          return;
        }
        else {
          ptr=ptr->next;
        }
      }
      if(ptr->data == element)return;
      */

      tail->next=Node;
      tail=tail->next;
    }
    return;
}

// print from head node to tail
void link_list:: display(){
    node* temp=head;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<"\n";
    return;
}

// reverse the direction of arrow (head and tail)
void link_list:: reverse(){
  node *temp = head; 
  node *prev=NULL, *next=NULL;
  while(temp){
      next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
  }
  
  head=prev;
  return;
}

// swaps the alternative nodes
void link_list:: swap(){
  node *temp = head; 
  int var; 
  while(temp!=NULL && temp->next !=NULL){
    var= temp->data;
    temp->data=temp->next->data;
    temp->next->data=var;
    temp=temp->next->next;
  }
  return;
}

// deletes every alternative node from position 0 {(1,8,3,5,7)=>(1,3,7)}
void link_list:: del(){
  node *ptr=head, *var;
  
  while(head!=NULL && head->next!=NULL){
    var=head->next;
    head->next=head->next->next;
    free(var);
    head=head->next;
  }
  head=ptr;
  return;
}

// display the nth node 
int link_list:: show(int n){
  if(n<=0)return -1;
  
  node *temp = head, *var; 
  for(int i=1;i<n;i++){
    temp=temp->next;
  }
  return temp->data;
}


int main(){
    return 0;
}

// to delete every element occuring more the once : modify insert function