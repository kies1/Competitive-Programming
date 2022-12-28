#include <bits/stdc++.h>
typedef long long ll;
const int MOD  = 1e9 + 7;
#define nl '\n';

void setIO(std::string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

char grid[11][11];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    setIO("buckets");
int b_x, b_y;
  int r_x, r_y;
  int l_x, l_y;

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      std::cin >> grid[i][j];

      if(grid[i][j] == 'B'){
        b_x = i;
        b_y = j;
      }else if(grid[i][j] == 'R'){
        r_x = i;
        r_y = j;
      }else if(grid[i][j] == 'L'){
        l_x = i;
        l_y = j;
      }
    }
  }

  int ans = abs(l_x - b_x) + abs(l_y - b_y) - 1;

if(b_x == l_x && r_x == l_x && ((r_y > b_y && r_y < l_y) || (r_y < b_y && r_y > l_y))){
    ans += 2;
  }else if(b_y == r_y && r_y == l_y && ((r_x > b_x && r_x < l_x) || (r_x < b_x && r_x > l_x))){
    ans += 2;
  }

  std::cout << ans << nl;
}