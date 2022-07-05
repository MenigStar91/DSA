/*
Using a linked list, write a program to add, multiply, subtract and evaluate polynomials: P1(x), P2(x), P3(x)

and P4(x) where P1(x) and P2(x) are input polynomials and P3(x) = P1(x) + P2(x) and

P4(x)=5 * {P3(x) - P1(X)} . Each node in the linked list corresponds to a term in the polynomial. So, in

your node structure - you may keep two data components – integers pow and coefficients; and one pointer to the next node.

Input Format:

First-line mentions K i.e. the number of test cases. Then there are three lines for each test case,

In the first  lines of a test case, the number indicates the highest degree of polynomials P1(x), in the second line indicates the highest degree of polynomials P2(x), then in the next two lines, there are  integers which are the coefficients of polynomial terms in descending order for P1(X) and P2(X) respectively

In the third (and last line) of a test case, there is one integer i.e. value of x for which you need to
evaluate the polynomials. (Constraints: 0≤K≤50, 0≤N≤9, -2≤x≤2, and Input coefficient terms
would be between -100 to +100; Assume you can safely do calculations for each polynomial
a term without worrying about underflow/overflow issues).

Sample Input 1:

1

7

3

1 0 0 0 10 -3 0 1

4 0 0 -2

2

Sample Output 1:

P1(x) : 1x^7 + 10x^3 - 3x^2 + 1

P2(x) : 4x^3 - 2

P3(x) = P1(x) + P2(x) : 1x^7 + 14x^3 - 3x^2 - 1

P4(x) =  5 * P2(x) : 20x^3  - 10

P1(2) = 197

P2(2) = 30

P3(2) = 227

P4(2) = 150
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node* next;
};
struct node* front;
struct node* rear;

class STACK{
  
  public:
  node *top;
  
  STACK(){
    top=NULL;
  }
  
  void push(int element){
    node * Node=new node;
    Node->data=element;
    Node->next = top;
    
    top=Node;
    return;
  }
  
  void display(){
    node* temp=top;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<"\n";
    return;
  }

  void Top(){
    cout<<top->data<<"\n";
  }
  
  int calc(int n){
    node * ptr=top;
    int output=0,k=0;
    while(ptr!=NULL){
      output=output+ptr->data *(pow(n, k) );
      k++;
      ptr=ptr->next;
    }
    return output;
  }
  
  void add(node *h1, node *h2);
  void diff(node *h1, node *h2);
};

void STACK:: add(node *h1, node *h2){
  if (h1 ==NULL && h2== NULL){
    return;
  }
  else if (h1==NULL){
    add(h1, h2->next);
    push(h2->data);
  }
  else if (h2==NULL){
    add(h1->next, h2);
    push (h1->data);
  }
  else{
    add(h1->next, h2->next);
    push(h1->data + h2->data);
  }
  return;
}

void STACK:: diff(node *h1, node *h2){
 if (h1 ==NULL && h2== NULL){
    return;
  }
  else if (h1==NULL){
    diff(h1, h2->next);
    push(h2->data);
  }
  else if (h2==NULL){
    diff(h1->next, h2);
    push(h1->data);
  }
  else{
    diff(h1->next, h2->next);
    push(5*(h1->data - h2->data));
  }
  return;
}

int main(){ 
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int a,b,var;
    cin>>a>>b;
    
    class STACK A,B;
    for(int i=0;i<a+1;i++){
      cin>>var;
      A.push(var);
    }
    for(int i=0;i<b+1;i++){
      cin>>var;
      B.push(var);
    }
    
    int x;
    cin>>x;
    cout<<A.calc(x)<<"\n";
    cout<<B.calc(x)<<"\n";

    class STACK C,D;
    C.add(A.top,B.top);
    D.diff(C.top,A.top);
    
    cout<<C.calc(x)<<"\n";
    cout<<D.calc(x)<<"\n";
  }
}
