/*
Input:

First Line contains r1, c1 [Rows and Columns] of first matrix

Second Line contains the inputted elements of first matrix

Third Line contains r2, c2 [Rows and Columns] of second matrix

Fourth Line contains the inputted elements of second matrix

Output:

Multiplication Result

or

Multiplication Not Possible
*/


#include <bits/stdc++.h>
using namespace std;

int main(){ 
  int n,m, r,s;
  cin>>n>>m;
  int arr1[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr1[i][j];
    }
  }
  cin>>r>>s;
  int arr2[r][s];
  for(int i=0;i<r;i++){
    for(int j=0;j<s;j++){
      cin>>arr2[i][j];
    }
  }
  
  if (m==r){
    int output[n][s];
    for(int i=0; i < n; i++) {
      for (int j = 0; j < s; j++) {
        output[i][j] = 0;
        for (int k = 0; k < m; k++)
          output[i][j] += arr1[i][k] * arr2[k][j];
      cout<<output[i][j]<<" ";
      }
    }
  }else {
    cout<<"Multiplication Not Possible";
  }
  return 0;
}

