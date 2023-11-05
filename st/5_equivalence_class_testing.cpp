#include <iomanip>
#include <iostream>
using namespace std;
int count = 1;
void check(int side1, int side2, int side3, int l, int r) {
  cout << setw(5) << count++ << setw(10) << side1 << setw(10) << side2
       << setw(10) << side3 << "     ";
  if (side1 < l || side1 > r || side2 < l || side2 > r || side3 < l ||
      side3 > r) {
    cout << " Invalid Input" << endl;
  } else if (side1 + side2 <= side3 || side1 + side3 <= side2 ||
             side2 + side3 <= side1) {
    cout << " Not a triangle" << endl;
  } else {
    if (side1 == side2 && side1 == side3) {
      cout << " Equilateral Triangle" << endl;
    } else if (side1 == side2 || side2 == side3 || side1 == side3) {
      cout << " Isosceles Triangle" << endl;
    } else {
      cout << " Scalene Triangle" << endl;
    }
  }
}

int main() {
  int left, right;
  cout << "Enter value range for sides: ";
  cin >> left >> right;

  int I1 = (left + right) / 2;
  int I2 = left - 1;
  int I3 = right + 1;
  cout << "I1  = { 1 <= a <= 100, 1 <= b <= 100, 1 <= c <= 100 } (All inputs "
          "are valid)\n";
  cout << "I2  = { a < 1, 1 <= b <= 100, 1 <= c <= 100 } (a is invalid, b is "
          "valid, c is valid)\n";
  cout << "I3  = { 1 <= a <= 100, b < 1, 1 <= c <= 100 } (a is valid, b is "
          "invalid, c is valid)\n";
  cout << "I4  = { 1 <= a <= 100, 1 <= b <= 100, c < 1 } (a is valid, b is "
          "valid, c is invalid)\n";
  cout << "I5  = { a > 100, 1 <= b <= 100, 1 <= c <= 100 } (a is invalid, b is "
          "valid, c is valid)\n";
  cout << "I6  = { 1 <= a <= 100, b > 100, 1 <= c <= 100 } (a is valid, b is "
          "invalid, c is valid)\n";
  cout << "I7  = { 1 <= a <= 100, 1 <= b <= 100, c > 100 } (a is valid, b is "
          "valid, c is invalid)\n";
  cout << "I8  = { a < 1, b < 1, 1 <= c <= 100 } (a is invalid, b is invalid, "
          "c is valid)\n";
  cout << "I9  = { 1 <= a <= 100, b < 1, c < 1 } (a is valid, b is invalid, c "
          "is invalid)\n";
  cout << "I10 = { a < 1, 1 <= b <= 100, c < 1 } (a is invalid, b is valid, c "
          "is invalid)\n";
  cout << "I11 = { a > 100, b > 100, 1 <= c <= 100 } (a is invalid, b is "
          "invalid, c is valid)\n";
  cout << "I12 = { 1 <= a <= 100, b > 100, c > 100 } (a is valid, b is "
          "invalid, c is invalid)\n";
  cout << "I13 = { a > 100, 1 <= b <= 100, c > 100 } (a is invalid, b is "
          "valid, c is invalid)\n";
  cout << "I14 = { a < 1, b > 100, 1 <= c <= 100 } (a is invalid, b is "
          "invalid, c is valid)\n";
  cout << "I15 = { a > 100, b < 1, 1 <= c <= 100 } (a is invalid, b is "
          "invalid, c is valid)\n";
  cout << "I16 = { 1 <= a <= 100, b < 1, c > 100 } (a is valid, b is invalid, "
          "c is invalid)\n";
  cout << "I17 = { 1 <= a <= 100, b > 100, c < 1 } (a is valid, b is invalid, "
          "c is invalid)\n";
  cout << "I18 = { a < 1, 1 <= b <= 100, c > 100 } (a is invalid, b is valid, "
          "c is invalid)\n";
  cout << "I19 = { a > 100, 1 <= b <= 100, c < 1 } (a is invalid, b is valid, "
          "c is invalid)\n";
  cout << "I20 = { a < 1, b < 1, c < 1 } (All inputs are invalid)\n";
  cout << "I21 = { a > 100, b > 100, c > 100 } (All inputs are invalid)\n";
  cout << "I22 = { a < 1, b < 1, c > 100 } (All inputs are invalid)\n";
  cout << "I23 = { a < 1, b > 100, c < 1 } (All inputs are invalid)\n";
  cout << "I24 = { a > 100, b < 1, c < 1 } (All inputs are invalid)\n";
  cout << "I25 = { a > 100, b > 100, c < 1 } (All inputs are invalid)\n";
  cout << "I26 = { a > 100, b < 1, c > 100 } (All inputs are invalid)\n";
  cout << "I27 = { a < 1, b > 100, c > 100 } (All inputs are invalid)\n";
  cout << "<---------Equivalence Input Class----------------->" << endl;
  cout << "CaseID    Side1      Side2      Side3      Output" << endl;
  check(I1, I1, I1, left, right);
  check(I2, I1, I1, left, right);
  check(I3, I1, I1, left, right);

  check(I1, I2, I1, left, right);
  check(I2, I2, I1, left, right);
  check(I3, I2, I1, left, right);

  check(I1, I3, I1, left, right);
  check(I2, I3, I1, left, right);
  check(I3, I3, I1, left, right);

  check(I1, I1, I2, left, right);
  check(I2, I1, I2, left, right);
  check(I3, I1, I2, left, right);

  check(I1, I2, I2, left, right);
  check(I2, I2, I2, left, right);
  check(I3, I2, I2, left, right);

  check(I1, I3, I2, left, right);
  check(I2, I3, I2, left, right);
  check(I3, I3, I2, left, right);

  check(I1, I1, I3, left, right);
  check(I2, I1, I3, left, right);
  check(I3, I1, I3, left, right);

  check(I1, I2, I3, left, right);
  check(I2, I2, I3, left, right);
  check(I3, I2, I3, left, right);

  check(I1, I3, I3, left, right);
  check(I2, I3, I3, left, right);
  check(I3, I3, I3, left, right);
  cout << endl;
  cout << endl;
  cout << "<---------Equivalence Output Class----------------->" << endl;
  cout << "CaseID    Side1      Side2      Side3      Output" << endl;
  cout << setw(5) << 1 << setw(10) << 5 << setw(10) << 5 << setw(10) << 5
       << "        "
       << "Equilateral Trianlge" << endl;
  cout << setw(5) << 2 << setw(10) << 3 << setw(10) << 4 << setw(10) << 4
       << "        "
       << "Scalene Triangle" << endl;
  cout << setw(5) << 3 << setw(10) << 5 << setw(10) << 5 << setw(10) << 3
       << "        "
       << "Isosceles Triangle" << endl;
  cout << setw(5) << 4 << setw(10) << 3 << setw(10) << 5 << setw(10) << 8
       << "        "
       << "Not a Triangle" << endl;
  return 0;
}
