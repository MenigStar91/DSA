/*
Q5. implement a queue using 2 stacks where dequeue operation can be performed in O(1) time. you have to calculate the count of push() and pop() needed in order to perform given enqueue() and dequeue() operations.

Input Format

First line of input will contain the number of operations n. Next n lines will contain a string describing the operation to be performed.
For Enqueue string will contain  “Ex”, where x is the element to be inserted.
For Dequeue string will contain a single character “D”.

Output Format

Print the count of push and pop operation in separate lines.

Example

Input:

6
E5
E4
D
E2
E3
D

Output:

12 
10

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
  int push=0,pop=0,len=0;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    char c;
    cin>>c;
    switch(c){
      case ('E'):
        int x;
        cin>>x;
        pop=pop+2*len;
        push=push+len*2+1;
        len++;
        break;
      case ('D'):
        pop++;
        len--;
        break;
      default:
        break;
    }
  }
  cout<<push<<"\n"<<pop;
  return 0;
}