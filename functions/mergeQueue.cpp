# include <bits/stdc++.h>
using namespace std;

// import Queue link list

// to merge two queue - descending order (given the two queues are already in descending order)
void merge(QUEUE a, QUEUE b){
  class QUEUE M;
  while(a.front!=NULL && b.front!=NULL){
    if(a.peek()>b.peek()){
      M.enque(a.deque());
    }
    else if(a.peek()<b.peek()){
      M.enque(b.deque());
    }else{
      M.enque(a.peek());
      a.deque();
      b.deque();
    }
  }
  if(a.front!=NULL){
    while(a.front!=NULL){
      M.enque(a.deque());
    }
  }else if (b.front!=NULL){
    while(b.front!=NULL){
      M.enque(b.deque());
    }
  }
  M.display();
  return;
}

int main(){
  return 0;
}