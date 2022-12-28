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
    setIO("word");
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> v(n);

    for(int i = 0; i < n; i++) std::cin >> v[i];
  
    std::string curr = "";
    int clength = 0;

  for(int i = 0; i < n; i++){
    if(clength + v[i].length() > k){
      std::cout << curr << nl;
      curr = "";
      clength = 0;
      if(clength == 0){
        curr += v[i];
      }else{
        curr += ' ';
        curr += v[i];
      }
      clength += v[i].length();
    }else{
      if(clength == 0){
        curr += v[i];
      }else{
        curr += ' ';
        curr += v[i];
      }
      clength += v[i].length();
    }
  }
  std::cout << curr << nl;
}