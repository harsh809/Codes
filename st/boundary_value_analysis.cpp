//write a program to find the maximum in three numbers input by the user and generate test cases for the program using boundary value analysis
#include <iostream>
using namespace std;

int Greater(int x,int y,int z){
    if(x >= y && x >= z){
        return x;
    }
    else if(y >= x && y >= z){
        return y;
    }
    else{
        return z;
    }
}
int main(){
    //let three be x,y,z
    //Range x=[0,100] , y=[0,50] , z=[100,200]
    cout<<"x"<<"\t\t"<<"y"<<"\t\t"<<"z"<<"\t\t"<<"Output"<<endl;
    int arr1[4] = {0,1,99,100};
    int arr2[4] = {0,1,49,50};
    int arr3[4] = {100,101,199,200};
    for(int i=0;i<4;i++){
        cout<<arr1[i]<<"\t\t"<<25<<"\t\t"<<150<<"\t\t"<<Greater(arr1[i],25,150)<<endl;
    }
    for(int i=0;i<4;i++){
        cout<<50<<"\t\t"<<arr2[i]<<"\t\t"<<150<<"\t\t"<<Greater(50,arr2[i],150)<<endl;
    }
    for(int i=0;i<4;i++){
        cout<<50<<"\t\t"<<25<<"\t\t"<<arr3[i]<<"\t\t"<<Greater(50,25,arr3[i])<<endl;
    }
    cout<<50<<"\t\t"<<25<<"\t\t"<<150<<"\t\t"<<Greater(50,25,150)<<endl;
}