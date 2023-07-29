#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int sum = 0;
    int count = 0;
    for(int i=n-1;i>=0;i--){
        sum += arr[i];
        if(sum<0){
            cout<<count<<endl;
        }
        count++;
    }
}