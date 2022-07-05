#include <bits/stdc++.h>
using namespace std;
 
#define MAX 1000

class STACK{ 
 
  public: 
  int top;
  char arr[MAX];
  
  STACK(){top=-1;} 
  void push(char element);
  char pop();
  char Top();
  void display();
};

void STACK:: push(char element){
  if (top>=(MAX-1)){
    cout<<"overflow \n";
  }else{
    arr[++top]=element;
  }
  return;
}

char STACK:: pop(){
  if (top==-1){
    cout<<"underflow";
    return -1;
  }
  return arr[top--];
}
 
char STACK:: Top(){
  if (top==-1){
    cout<<"empty\n";
    return 0;
  }
  else{
    return arr[top]; 
  }
};

void STACK:: display(){
  for(int j=0;j<this->top+1;j++){
    if(this->arr[j]!='/'){
      cout<<this->arr[j]<<" ";
    }else{
      cout<<">>"<<" ";
    }
  }
  return;
}

class STACK Stack;
class STACK temp;

void infix_to_postfix(char elem){
    if(elem=='('){
  	     temp.push(elem);
  	 }else if(elem=='+' || elem=='-' ){
	       while(temp.Top()!='('){
	           Stack.push(temp.pop());
	        }
	     temp.push(elem);
	   }else if(elem=='*' || elem=='/'){
	        while(temp.Top()=='^' || temp.Top()=='/' || temp.Top()=='*'){
	           Stack.push(Stack.pop());
	         }
	     temp.push(elem);
	   }else if(elem=='^'){
	       while(temp.Top()=='^'){
	           Stack.push(temp.pop());
	       }
	       temp.push(elem);
	   }else if(elem==')'){
	       while(temp.Top()!='('){
	           Stack.push(temp.pop());
	       }
	       temp.pop();
	   }else{
	       Stack.push(elem);
	   };
	return;
}

int eval(){
  class STACK prev;
  for(int i=0;i<Stack.top+1;i++){
    if(Stack.arr[i]>='0' && Stack.arr[i]<='9'){
      prev.push(Stack.arr[i]-'0');
    }
    else{
      int op1 = prev.pop();
      int op2 = prev.pop(); 
      switch (Stack.arr[i]){
        case '^': prev.push(pow(op2,op1));break;
        case '+': prev.push(op2 + op1); break;
        case '-': prev.push(op2 - op1); break;
        case '*': prev.push(op2 * op1); break;
        case '/': prev.push(op2/pow(2,op1)); break;
      }
    }
  }
  
  return prev.Top();
}


int main(){
  string S, Temp="";
  cin>>S;
	S = '('+S+')';
  for(int i=0;i<S.length();i++){
    if(i>0 && S[i]=='>' && S[i-1]!='>'){
      Temp += '/';
    }
    else if(i>0 && S[i]=='>' && S[i-1]=='>'){
      continue;
    }
    else{
      Temp += S[i];
    }
  }
  for(int i=0;i<Temp.length();i++){
    infix_to_postfix(Temp[i]);
  }
  Stack.display();
  cout<<"\n";
  int output=eval();
  cout<<output;
  return 0;
}
