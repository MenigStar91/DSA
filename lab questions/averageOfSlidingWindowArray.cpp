#include <bits/stdc++.h>
using namespace std;


// average of integers in a sliding window of size x.
int main(){
  int n,temp;
  cin>>n;
  int arr[n];
  
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
  int k,z=1,res=0, j=0;
  cin>>k;
  
  if(k<=n){
  int q=k;
  int out[n-k+2];
  for(int i=0;i<n;i++){
    if(z<k){
      res=res+arr[i];
      z++;
    }else{
      if(z==k){
        res=res+arr[i];
        out[j]=res/k;
        j++;
        z++;
      }
      else{
        res=res+arr[i]-arr[i-k];
        out[j]=res/k;
        j++;
      }
    } 
  }
  if(k!=1){
    res=res-arr[j-1];
    out[j]=res/(k-1);
  
    for(int i=0;i<n-k+2;i++){
      cout<<out[i]<<" ";
    }
  }else{
    for(int i=0;i<n-k+1;i++){
      cout<<out[i]<<" ";
    }
  }
  }
  else{
    int res=0;
    for(int i=0;i<n;i++){
      res=res+arr[i];
    }
    cout<<res/n;
  }
  return 0;
}