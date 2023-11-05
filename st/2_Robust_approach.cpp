#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << "Enter Number of variables: ";
  int n;
  cin >> n;
  vector<pair<int, int>> limit;
  for (int i = 0; i < n; i++) {
    cout << "Enter valid Range for variable " << i + 1 << " : ";
    int l, r;
    cin >> l >> r;
    limit.push_back({l, r});
  }
  vector<vector<int>> output;
  for (int i = 0; i < n; i++) {
    vector<int> temp(n);
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < n; k++) {
        if (i != k) {
          temp[k] = (limit[k].first + limit[k].second) / 2;
        } else {
          if (j == 0)
            temp[k] = limit[i].first - 1;
          else if (j == 1)
            temp[k] = limit[i].first;
          else if (j == 2)
            temp[k] = limit[i].first + 1;
          else if (j == 3)
            temp[k] = limit[i].second - 1;
          else if (j == 4)
            temp[k] = limit[i].second;
          else
            temp[k] = limit[i].second + 1;
        }
      }
      output.push_back(temp);
    }
  }
  vector<int> temp(n);
  for (int i = 0; i < n; i++) {
    temp[i] = (limit[i].first + limit[i].second) / 2;
  }
  output.push_back(temp);

  cout << "<------------------------Robust Testing--------------------------->"
       << endl;
  cout << "Sr.No. ";
  for (int i = 0; i < n; i++) {
    cout << "Variable " << i + 1 << " ";
  }
  cout << " Output";
  cout << endl;
  int testCase = 1;
  for (int i = 0; i < output.size(); i++) {
    cout << setw(5) << testCase;
    testCase++;
    int maxi = INT_MIN;
    for (auto j : output[i]) {
      maxi = max(maxi, j);
      cout << setw(11) << j;
    }
    if (i == 6 * n)
      cout << setw(10) << maxi;
    else if (i % (2 * n) == 0 || i % (2 * n) == ((2 * n) - 1))
      cout << " \t InValid";
    else
      cout << setw(10) << maxi;
    cout << endl;
  }
}
