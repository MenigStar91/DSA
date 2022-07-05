# include <bits/stdc++.h>
using namespace std;

// import singlylinkedlist.cpp

int main(){
    int n;
    cin>>n;

    link_list list;
    for(int i=0;i<n;i++){
        cin>>temp;
        list.insert(temp);
    }

    int temp, pos;
    cin>>temp>>pos;

    int k=list.show((n+1)/2-pos);
    if(k==-1){
        cout<<"Not Possible";
    }else{
        cout<<k;
    }
}