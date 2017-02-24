#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
  int Q; cin >> Q;
  while(Q-->0) {
    int L, n;
    cin >> L >> n;
    int min_t = 0, max_t = 0;
    for(int i=0;i<n;++i) {
      int p_i; cin >> p_i;
      min_t = max(min_t, min(p_i, L-p_i));
      max_t = max(max_t, max(p_i, L-p_i));
    }
    cout << min_t << ' ' << max_t << endl;
  }
  return 0;
}
