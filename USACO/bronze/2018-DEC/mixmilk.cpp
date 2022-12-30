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
  setIO("mixmilk");

  std::array<ll, 3> capacity;
  std::array<ll, 3> amount;

  for(int i = 0; i < 3; i++){
    std::cin >> capacity[i] >> amount[i];
  }

  for(int i = 0; i < 100; i++){
    if(i % 3 == 0){
      ll give = amount[0];
      ll original = amount[1];
      amount[1] = std::min(capacity[1], give + amount[1]);
      amount[0] -= (amount[1] - original);
    }else if(i % 3 == 1){
      ll give = amount[1];
      ll original = amount[2];
      amount[2] = std::min(capacity[2], give + amount[2]);
      amount[1] -= (amount[2] - original);
    }else{
      ll give = amount[2];
      ll original = amount[0];
      amount[0] = std::min(capacity[0], give + amount[0]);
      amount[2] -= (amount[0] - original);
    }
  }

  std::cout << amount[0] << nl;
  std::cout << amount[1] << nl;
  std::cout << amount[2] << nl;
}