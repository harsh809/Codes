#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[11] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    int maxi = 0;
    int  cnt = 0;
    for(int i=0;i<11;i++){
        if(arr[i]==0){
            maxi = max(cnt,maxi); 
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    cout<<cnt<<endl;
}