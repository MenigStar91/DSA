# include <bits/stdc++.h>
using namespace std;

// import stack array .cpp

int main(){
    int N;
    cin>>N;

    int min, temp;
    stack S;
    for (int i=0;i<N;i++){
        cin>>temp;
        if(i==0){
            min = i;
        }
        else{
            if(temp<min){
                S.push_min(temp);
            }else{
                S.push_min(min);
                min = temp;
            }
        }
    }
    return 0;
}