#include <bits/stdc++.h>
using namespace std;

void solve(int idx, vector<int>& temp, vector<vector<int>>& testCase,
           vector<vector<int>>& result) {
  if (idx == testCase.size()) {
    result.push_back(temp);
    return;
  }
  for (int j = 0; j < 7; j++) {
    if (j == 0) {
      temp.push_back(testCase[idx][0] - 1);
    } else if (j == 1) {
      temp.push_back(testCase[idx][0]);
    } else if (j == 2) {
      temp.push_back(testCase[idx][0] + 1);
    } else if (j == 3) {
      temp.push_back((testCase[idx][0] + testCase[idx][1]) / 2);
    } else if (j == 4) {
      temp.push_back(testCase[idx][1] - 1);
    } else if (j == 5) {
      temp.push_back(testCase[idx][1]);
    } else {
      temp.push_back(testCase[idx][1] + 1);
    }
    solve(idx + 1, temp, testCase, result);
    temp.pop_back();
  }
}

int main() {
  cout << "Enter Number of variables: ";
  int n;
  cin >> n;
  vector<pair<int, int>> limits;
  for (int i = 0; i < n; i++) {
    cout << "Enter valid Range for variable " << i + 1 << " : ";
    int l, r;
    cin >> l >> r;
    limits.push_back({l, r});
  }
  vector<vector<int>> Case(n);
  for (int i = 0; i < n; i++) {
    Case[i].push_back(limits[i].first);
    Case[i].push_back(limits[i].second);
  }

  vector<vector<int>> result;
  vector<int> temp;
  solve(0, temp, Case, result);
  cout << "<---------------------- ROBUST WORST CASE TESTING "
          "---------------------->"
       << endl;
  cout << "Sr.No."
       << " ";
  for (int i = 0; i < n; i++) {
    cout << "  Variable" << i + 1 << " ";
  }
  cout << "  Output";
  cout << endl;
  int testCase = 1;
  bool valid = true;
  for (auto i : result) {
    cout << setw(4) << testCase;
    testCase++;
    int maxi = INT_MIN;
    int k = 0;
    for (auto j : i) {
      maxi = max(maxi, j);
      cout << setw(10) << j;

      if (j > limits[k].second || j < limits[k].first) {
        valid = false;
      }
      k++;
    }
    if (valid)
      cout << setw(9) << "    " << maxi;
    else
      cout << setw(9) << "    "
           << " INVALID INPUT";
    valid = true;
    cout << endl;
  }
}
