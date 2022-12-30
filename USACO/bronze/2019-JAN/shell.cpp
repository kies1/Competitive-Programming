#include <bits/stdc++.h>
typedef long long ll;
const int MOD  = 1e9 + 7;
#define nl '\n';
#define dbg(v)                                                                 \
    std::cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';

void setIO(std::string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  setIO("shell");

  int n; std::cin >> n;
  std::array<int, 3> points = {0, 0, 0};
  std::array<int, 3> shells = {0, 1, 2};

  while(n--){
    int a, b, g; std::cin >> a >> b >> g;
    a--, b--, g--;
    std::swap(shells[a], shells[b]);
    points[shells[g]]++;
  }
  
  std::cout << std::max(points[0], std::max(points[1], points[2])) << nl;   
}