#include <bits/stdc++.h>
typedef long long ll;
const int MOD  = 1e9 + 7;
#define nl '\n';
 
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
 
  std::vector<ll> v(7);

  for(int i = 0; i < 7; i++) std::cin >> v[i];
  std::sort(v.begin(), v.end());

  ll a = v[0];
  ll b = v[1];
  ll c = v[6] - a - b;

  std::cout << a << ' ' << b << ' ' << c << nl;
}