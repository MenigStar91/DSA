#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node* ptr;
};
struct node* top;

// insertion
void push(int element){
  struct node* temp;
  temp = new node();
  temp-> data=element;
  temp-> ptr=top;
  top=temp;
}

// deletion
int pop(){
  struct node* temp;
  int n;
  temp=top;
  top=top->ptr;
  temp-> ptr=NULL;
  n=temp->data;
  free(temp);
  return n;
}

// top most element returned
int Top(){
  return top->data;
}

// print element from bottom to top
void display(node* top){
  if(top==NULL){return;}
  else{
    display(top->ptr);
    cout<<top->data<<" ";
  }
  return ;
}


int main(){
  return 0;
}
