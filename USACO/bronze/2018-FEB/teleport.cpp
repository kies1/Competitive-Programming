#include <bits/stdc++.h>
typedef long long ll;
const int MOD  = 1e9 + 7;
#define nl '\n';

void setIO(std::string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    setIO("teleport");
    int a, b, x, y;
    std::cin >> a >> b >> x >> y;

    if(a > b) std::swap(a, b);
    if(x > y) std::swap(x, y);

    int useTeleport = abs(a - x) + abs(b - y);
    int noTeleport = b - a;

    std::cout << std::min(useTeleport, noTeleport) << nl;
}