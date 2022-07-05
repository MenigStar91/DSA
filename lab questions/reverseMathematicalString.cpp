# include <bits/stdc++.h>
using namespace std;

// import stack 
// Input : "20-a+5*2"
// Output : "2*5+a-20"

int main(){
  class STACK S;
  string k;
  cin>>k;
  for(int i=0;i<k.length();i++){
    
    string temp(1,k[i]);
    
    if(i==0){
      S.push(temp);
    }else if(isdigit(k[i])){
      string var=S.pop();
      S.push(var+temp);
    }else{
      if(temp==")"){
        S.push(temp);
      }else{
        S.push(temp);
        string temp2(1,k[i+1]);
        if(temp2!="("){
          S.push(temp2);
          i++;
        }
      }
    }
  }
  
  S.display();
 
  return 0;
}