# include <bits/stdc++.h>
using namespace std;

// import stack

bool check(string s){
  class STACK Stack;
  int i=0;
  while(i<s.length()){
    if(s[i]=='[' || s[i]=='{' || s[i]=='('){
      Stack.push(s[i]);
    }
    else{
      if(s[i]==']'){
        if(Stack.Top()!='['){return 0;}
        else Stack.pop();
      }else if(s[i]=='}'){
        if(Stack.Top()!='{'){return 0;}
        else Stack.pop();
      }else if(s[i]==')'){
        if(Stack.Top()!='('){return 0;}
        else Stack.pop();
      }
    }
    i++;
  }
  if (Stack.Top()!=' ') {return 0;}
  
  return 1;
}


int mian(){
    return 0;
}