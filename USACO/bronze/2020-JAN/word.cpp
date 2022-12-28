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
    
int bronzeInitial, bronzeFinal;
std::cin >> bronzeInitial >> bronzeFinal;

int silverInitial, silverFinal;
std::cin >> silverInitial >> silverFinal;

int goldInitial, goldFinal;
std::cin >> goldInitial >> goldFinal;

  int platInitial, platFinal;
  std::cin >> platInitial >> platFinal;

  int s = 0, g = 0, p = 0;

  if(platFinal > platInitial){
    p+= platFinal - platInitial;
    goldInitial -= (platFinal - platInitial);
  }

  if(goldFinal > goldInitial){
    g += goldFinal > goldInitial;
    silverInitial -= (goldFinal - goldInitial);
  }

  if(silverFinal > silverInitial){
    s += (silverFinal > silverInitial);
  }

  std::cout << s << nl;
  std::cout << g << nl;
  std::cout << p << nl;
}