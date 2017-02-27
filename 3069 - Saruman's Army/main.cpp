#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

// snippets
int solve(const vector<int>& x, int R, int pos) {
  //cout << pos << endl;
  if(pos >= x.size()) return 0;
  else if(pos == x.size() - 1) return 1;
  else {
    int first = 0;
    for(int i=0;i<x.size();++i) {
      if(x[i] - x[pos] <= R) {
        first = i;
      } else break;
    }

    int i;
    for(i=first+1;i<x.size();++i) {
      if(x[i] - x[first] > R) {
        break;
      }
    }
    return 1 + solve(x, R, i);
  }
}

int main(int argc, char** argv) {
  int R, n;
  while(cin >> R >> n) {
    if(R == -1 && n == -1) break;
    vector<int> x(n);
    for(int i=0;i<n;++i) cin >> x[i];
    std::sort(x.begin(), x.end());
    cout << solve(x, R, 0) << endl;
  }
  return 0;
}
