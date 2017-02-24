#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

// snippets
void dfs(vector<string>& M, int r, int c) {
  if(r < 0 || c < 0 || r >= M.size() || c >= M.front().size()) return;
  if(M[r][c] != 'W') return;
  M[r][c] = '.';
  dfs(M, r-1,c-1);
  dfs(M, r+1,c-1);
  dfs(M, r+1,c+1);
  dfs(M, r-1,c+1);
  dfs(M, r-1,c);
  dfs(M, r+1,c);
  dfs(M, r,c-1);
  dfs(M, r,c+1);
}

void print(const vector<string>& M) {
  for(auto s : M) cout << s << endl;
  cout << endl;
}

int solve(const vector<string>& Min) {
  vector<string> M = Min;

  int cnt = 0;
  for(int i=0;i<M.size();++i) {
    for(int j=0;j<M[i].size();++j) {
      if(M[i][j] == 'W') {
        //print(M);
        dfs(M, i, j);
        ++cnt;
      }
    }
  }
  return cnt;
}

int main(int argc, char** argv) {
  int n, m; cin >> n >> m;
  vector<string> M(n);
  for(int i=0;i<n;++i) {
      cin >> M[i];
  }

  cout << solve(M) << endl;
  return 0;
}
