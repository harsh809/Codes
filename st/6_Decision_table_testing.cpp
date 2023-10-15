#include <iostream>
using namespace std;

void check(int a,int b,int c){
    // Check the type of triangle
    if (a <= 0 || b <= 0 || c <= 0 || a>10 || b>10 || c>10) {
        cout <<a<<" "<<b<<" " << c<<"   "<<"Invalid Input" << endl;
    } else if (a + b <= c || a + c <= b || b + c <= a) {
        cout <<a<<" "<<b<<" " << c<<"   "<< "Not a triangle" << endl;
    } else if (a == b && b == c) {
        cout <<a<<" "<<b<<" " << c<<"    "<< "Equilateral triangle" << endl;
    } else if (a == b || b == c || a == c) {
        cout <<a<<" "<<b<<" " << c<<"    "<< "Isosceles triangle" << endl;
    } else {
        cout <<a<<" "<<b<<" " << c<<"   "<< "Scalene triangle" << endl;
    }
}
int main() {
    //Range of a,b,and c 1-10
    check(5,10,5);
    check(10,5,5);
    check(5,5,10);
    check(10,9,5);
    check(5,1,5);
    check(1,5,5);
    check(5,5,1);
    check(5,5,5);
    check(-1,5,5);
    check(5,-1,5);
    check(5,5,-1);
    return 0;
}
