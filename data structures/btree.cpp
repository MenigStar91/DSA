#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  class Btree *left=nullptr;
  class Btree *right=nullptr;
};

class Btree{
  int degree=3;
  public :
    struct node *arr;
    int count;
    Btree(){
      this->arr=  (struct node*)malloc(sizeof(struct node) * degree);
      this->count =0;
    }
    Btree(node *root){
      this->arr=  (struct node*)malloc(sizeof(struct node) * degree);
      arr[0]=*root;
      this->count =1;
    }
    
    Btree *input(node *root);
    node *insert(node *root);
    node *split();
    void push(node *root);
    void traverse();
    bool search(int element);
};

Btree *Btree::input(node *root){
  node *temp=this->insert(root);
  if(temp==nullptr){
    return nullptr;
  }else{
    Btree *k=new Btree(temp);
    Btree *ptr;
    ptr=k;
    return ptr;
  }
}

node *Btree::insert(node *root){
  if(arr[0].left ==nullptr){
    this->push(root);
    if(count==degree){
      node *r=this->split();
      return r;
    }
    return nullptr;
  }else{
    int pos=0;
    node *r=nullptr;
    int flag=1;
    for(pos;pos<count;pos++){
        if(root->data<arr[pos].data){
            r=(arr[pos].left)->insert(root);
            flag=0;
            break;
        }
    }
    if(flag){
        r=arr[--pos].right->insert(root);
    }
    
    if(r==nullptr)return nullptr;
    else {
      this->push(r);
      if(count==degree){
        node *k=this->split();
        return k;
      }
      return nullptr;
    }
    
    return nullptr;
  }
}

node *Btree::split(){
   Btree *left =new Btree(&arr[0]);
   Btree *right = new Btree(&arr[2]);
   arr[1].left= left;
   arr[1].right= right;
  return &arr[1];
}

void Btree::push(node *root){
  int i=0;
  for(i ;i<count;i++){
    if(root->data< arr[i].data){
      break;
    }
  }
  for(int j=count++; j>i; j--)
    arr[j] = arr[j-1];
  arr[i] = *root;
  
  if(i==0){
      if (count>1)
      arr[1].left=arr[0].right;
  }else if (i==2){
      arr[1].right=arr[0].left;
  }else{
      arr[0].right=arr[1].left;
      if(count==3)
      arr[2].left=arr[1].right;
  }
  
  
  return;
}

void Btree::traverse(){
  if(count ==0)return;
  else{
    for(int i=0;i<count;i++){
      cout <<  arr[i].data << ' ';
    }
    int k=0;
    if(arr[0].left ==nullptr)return;
    arr[0].left->traverse();
    while(k<count){
      arr[k].right->traverse();
      k++;
    }
    return;
  }
}

bool Btree::search(int element){
  if(count==0){
    return 0;
  }else{
    for(int i=0;i<count;i++){
      if(arr[i].data==element){
        return 1;
      }
    }
    int k=0, res=0;
    if(arr[0].left ==nullptr)return 0;
    res=res^arr[0].left->search(element);
    while(k<count){
      res=res^arr[k].right->search(element);
      k++;
    }
    return res;
  }
}

void print(Btree *root){
  for(int i=0;i<root->count;i++){
    cout<<root->arr[i].data<<" ";
  }
  return ;
}

void traverse(Btree *root){
  queue <Btree*> que;
  Btree *var;
  que.push(root);
  
  while(!que.empty()){
    var=que.front();
    print(var);
    if(var->arr[0].left!=nullptr){
      for(int i=0;i<var->count;i++){
        que.push(var->arr[i].left);
      }
      que.push(var->arr[root->count-1].right);
    }
    que.pop();
  }
  return ;
}


class Btree TREE;
Btree *ptr=&TREE;


int main(){
  Btree *temp;
  int element;
  cin >>element;
  node *Node=(struct node*)malloc(sizeof(struct node));\
  Node->data=element;
  temp=ptr->input(Node);
  if(temp!=nullptr){
    ptr=temp;
  }
  return 0;
}


