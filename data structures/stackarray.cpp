#include <bits/stdc++.h>
using namespace std;
 
#define MAX 1000
class STACK{ 
  int top;
  
  public: 
  
  int arr[MAX];
  STACK(){top=-1;} 

  void push_min(int element);
  void push_max(int element);
  void push(int element);
  int pop();
  int Top();
};


// insert in decreasing order (minimum elem at the top)
void STACK:: push_min(int element){
  if (top>=(MAX-1)){
    cout<<"overflow \n";
  }else{
    if(top==-1){
      arr[++top]=element;
    }else if(arr[top]>element){
      arr[++top]=element;
    }else{
      int temp= arr[top];
      arr[top]=element;
      arr[++top]=temp;
    }
  }
  return;
}

// insert in increasing order (maximum element at the top)
void STACK:: push_max(int element){
  if (top>=(MAX-1)){
    cout<<"overflow \n";
  }else{
    if(top==-1){
      arr[++top]=element;
    }else if(arr[top]<element){
      arr[++top]=element;
    }else{
      int temp= arr[top];
      arr[top]=element;
      arr[++top]=temp;
    }
  }
  return;
}

// insert element
void STACK:: push(int element){
  if (top>=(MAX-1)){
    cout<<"overflow \n";
  }else{
    arr[++top]=element;
  }
  return;
}

// remove and return top most element
int STACK:: pop(){
  if (top==-1){
    cout<<"underflow";
    return -1;
  }
  return arr[top--];
}
 
// return last entered element 
int STACK:: Top(){
  if (top==-1){
    cout<<"empty\n";
    return 0;
  }
  else{
    return arr[top]; 
  }
}




int main(){
    return 0;
}