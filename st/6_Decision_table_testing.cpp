#include <bits/stdc++.h>
using namespace std;
void check(int side1 , int side2 , int side3 , int left , int right)
{
    if(side1<left || side1>right || side2 < left || side2 > right || side3 < left || side3 > right){
        cout<<"Invalid Input"<<endl;
    }
    else if(side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1){
        cout<<"Not a traingle"<<endl;
    }
    else{
        if(side1 == side2 && side1 == side3){
            cout<<"Equilateral Triangle"<<endl;
        }
        else if(side1 == side2 || side2 == side3 || side1 == side3){
            cout<<"Isosceles Triangle"<<endl;
        }
        else{
            cout<<"Scalene"<<endl;
        }
    }
}
int main(){
    int left , right;
    cout<<"Enter value range for sides : "<<endl;
    cin>>left>>right;
     string str = "\nDECISION TABLE FOR TRIANGLE CLASSIFICATION PROBLEM\n";
    str = str + "----------------------------------------------------------------\n";
    str = str + "Decisions          | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11|\n";
    str = str + "----------------------------------------------------------------\n";
    str = str + "C1: a < b + c?     | F | T | T | T | T | T | T | T | T | T | T |\n";
    str = str + "C2: b < a + c?     | - | F | T | T | T | T | T | T | T | T | T |\n";
    str = str + "C3: c < a + b?     | - | - | F | T | T | T | T | T | T | T | T |\n";
    str = str + "C4: a = b ?        | - | - | - | T | T | T | T | F | F | F | F |\n";
    str = str + "C5: a = c ?        | - | - | - | T | T | F | F | T | F | F | F |\n";
    str = str + "C6: b = c ?        | - | - | - | T | F | T | F | F | F | T | F |\n";
    str = str + "----------------------------------------------------------------\n";
    str = str + "Rule count         |32 |16 | 8 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |\n";
    str = str + "----------------------------------------------------------------\n";
    str = str + "A1: Not a triangle | X | X | X |   |   |   |   |   |   |   |   |\n";
    str = str + "A2: Scalene        |   |   |   |   |   |   |   |   |   |   | X |\n";
    str = str + "A3: Isosceles      |   |   |   |   |   |   | X |   | X | X |   |\n";
    str = str + "A4: Equilateral    |   |   |   | X |   |   |   |   |   |   |   |\n";
    str = str + "A5: Impossible     |   |   |   |   | X | X |   | X |   |   |   |\n";
    cout<<str<<endl;
    cout<<"<-------------------------Decision Table Testing---------------------->"<<endl;
    cout << "Cases" << " ";
    for (int i = 0; i < 3; i++) {
        cout << "  side" << i + 1 << " ";
    }
    int nominal = (right + left)/2;
    cout << "  Output";
    cout << endl;
    cout<<"1 "<<"\t  "<<nominal<<" \t  "<< right <<" \t  "<< nominal <<" \t ";
    check(nominal , right , nominal , left , right);

    cout<<"2 "<<"\t  "<<right<<" \t  "<< nominal <<" \t  "<< nominal <<" \t ";
    check(right , nominal , nominal , left , right);

    cout<<"3 "<<"\t  "<<nominal<<" \t  "<< nominal <<" \t  "<< right <<" \t ";
    check(nominal , nominal , right , left , right);

    cout<<"4 "<<"\t  "<<nominal<<" \t  "<< right <<" \t  "<< nominal <<" \t ";
    check(right , right - 1 , nominal , left , right);

    cout<<"5 "<<"\t  "<<nominal<<" \t  "<< left <<" \t  "<< nominal <<" \t ";
    check(nominal , left , nominal , left , right);

    cout<<"6 "<<"\t  "<<left<<" \t  "<< nominal <<" \t  "<< nominal <<" \t ";
    check(left , nominal , nominal , left , right);

    cout<<"7 "<<"\t  "<<left - 1<<" \t  "<< left - 1 <<" \t  "<< left - 1 <<" \t ";
    check(left - 1, left - 1 , left - 1 , left , right);

    cout<<"8 "<<"\t  "<<nominal<<" \t  "<< nominal <<" \t  "<< left <<" \t ";
    check(nominal , nominal , left , left , right);

    cout<<"9 "<<"\t  "<<right  + 1<<" \t  "<< right + 1<<" \t  "<< right + 1 <<" \t ";
    check(right + 1, right + 1 , right  + 1 , left , right);

    cout<<"10 "<<"\t  "<<nominal<<" \t  "<< right <<" \t  "<< nominal <<" \t ";
    check(nominal , nominal , nominal , left , right);

    cout<<"11 "<<"\t  "<<nominal<<" \t  "<< nominal <<" \t  "<< nominal <<" \t ";
    check(nominal , nominal , nominal , left , right);
}
