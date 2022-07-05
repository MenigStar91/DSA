// Find the next immediate greater element for each element of the array. If any element does not have any next greater element,then print -1.
/*
Input
1 3 2 4

Output:
1->3
3->4
2->4
4->-1

*/

#include <bits/stdc++.h>
using namespace std;

class STACK{
  int top,max=-1;
  int size;
  
  int *arr;
  public:
  STACK(int n){
    arr=(int*)malloc(n*sizeof(int));
    top=-1;
    size=n;
  }
  
  void push(int i){
    if(top>=size){
      cout<<"Overflow";
      return ;
    }
    arr[++top]=i;
    return;
  }
  
  int Top(){
    return arr[top];
  }
  int pop(){
    return arr[top--];
  }
  
  void display(int n){
    pair<int,int> out[n];
    int i=0;
    while(top!=-1){
     
      int x=this->pop();
      out[i].first=x;
      out[i].second=max;
      if(x>this->Top()){
        max=x;
      }
      i++;
      
    }
    i--;
    while(i>-1){
      cout<<out[i].first<<"->"<<out[i].second<<"\n";
      i--;
    }
  }
};


int main(){
    return 0;
}