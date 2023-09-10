//write a program to find the maximum in three numbers input by the user and generate test cases for the program using boundary value analysis
#include <iostream>
using namespace std;

void Greater(int x,int y,int z){
    if(x<0 || x>100 || y<0 || y>50 || z<100 || z>200){
        cout<<"Invalid";
    }
    else if(x >= y && x >= z){
        cout<<x;
    }
    else if(y >= x && y >= z){
        cout<<y;
    }
    else{
        cout<<z;
    }
}
int main(){
    //let three numbers be x,y,z
    //Range x=[0,100] , y=[0,50] , z=[100,200]
    cout<<"x"<<"\t\t"<<"y"<<"\t\t"<<"z"<<"\t\t"<<"Output"<<endl;
    int arr1[6] = {-1,0,1,99,100,101};
    int arr2[6] = {-1,0,1,49,50,51};
    int arr3[6] = {99,100,101,199,200,201};
    for(int i=0;i<6;i++){
        cout<<arr1[i]<<"\t\t"<<25<<"\t\t"<<150<<"\t\t";
        Greater(arr1[i],25,150);
        cout<<endl;
    }
    for(int i=0;i<6;i++){
        cout<<50<<"\t\t"<<arr2[i]<<"\t\t"<<150<<"\t\t";
        Greater(50,arr2[i],150);
        cout<<endl;
    }
    for(int i=0;i<6;i++){
        cout<<50<<"\t\t"<<25<<"\t\t"<<arr3[i]<<"\t\t";
        Greater(50,25,arr3[i]);
        cout<<endl;
    }
    cout<<50<<"\t\t"<<25<<"\t\t"<<150<<"\t\t";
    Greater(50,25,150);
    cout<<endl;
}