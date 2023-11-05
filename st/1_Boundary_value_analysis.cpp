#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << "Enter Number of variables: ";
  int n;
  cin >> n;
  vector<pair<int, int>> ranges;
  for (int i = 0; i < n; i++) {
    cout << "Enter valid Range for variable " << i + 1 << " : ";
    int l, r;
    cin >> l >> r;
    ranges.push_back({l, r});
  }
  vector<vector<int>> output;
  for (int i = 0; i < n; i++) {
    vector<int> temp(n);
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < n; k++) {
        if (i != k) {
          temp[k] = (ranges[k].first + ranges[k].second) / 2;
        } else {
          if (j == 0)
            temp[k] = ranges[i].first;
          else if (j == 1)
            temp[k] = ranges[i].first + 1;
          else if (j == 2)
            temp[k] = ranges[i].second - 1;
          else
            temp[k] = ranges[i].second;
        }
      }
      output.push_back(temp);
    }
  }
  cout << "<---------------BOUNDARY VALUE ANALYSIS------------------->" << endl;
  cout << "Sr.No."
       << " ";
  for (int i = 0; i < n; i++) {
    cout << "Variable" << i + 1 << " ";
  }
  cout << "Output";
  cout << endl;
  int testCase = 1;
  for (auto i : output) {
    cout << testCase << "       ";
    testCase++;
    int maxi = INT_MIN;
    for (auto j : i) {
      maxi = max(maxi, j);
      cout << j << "        ";
    }
    cout << maxi;
    cout << endl;
  }
  return 0;
}
