/*
You have a stack with push, pop and stack top functionality. Assume that you have a sequence of n integers 1,2,3,....,n in this order. Using the given stack and the built-in functionality as mentioned already, state whether it is possible to construct a given output sequence or not. If yes, then show the sequence.

(You can read the input only sequentially. Similarly, you can write on the output only

sequentially, and once the output is written, you can’t read or modify it later.)

Example 1: Given input n = 3. (i.e. sequence available to you is 1,2,3). And given sequence:

2,1,3.

Answer: Yes. It is possible by the following sequence of operations:

push(1), push(2), pop(), pop(), push(3), pop().

(i.e., we can create sequences 2,1,3 using a stack.)

Example 2: Given input n=3. Given sequence: 3,1,2.

Answer: Not possible.

Your program should first read a given n from the user. And then read a sequence of length

The user will provide the sequence  That is, for sequences 1,2,3, you will get 1 2 3

The program should output Yes/No, 
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int k=1;
  for(int i=1;i<n;i++){
    if (arr[i-1]-arr[i]>1){
      k=-1;
    }
  }
  
  if(k==-1){cout<<"No";}
  else{cout<<"Yes";}
  return 0;
  
}