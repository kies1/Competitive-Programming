#include <bits/stdc++.h>
typedef long long ll;
const int MOD  = 1e9 + 7;
#define x first
#define y second
#define nl '\n';
#define dbg(v)                                                                 \
    std::cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';

void setIO(std::string s) { 
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n, m, d, s;
int pDrink[1001], mDrink[1001], tDrink[1001];
int pSick[51], tSick[51];

bool drank(int person, int milk, int time){
    for(int i = 1; i <= d; i++){
        if(pDrink[i] == person && milk == mDrink[i] && time > tDrink[i]) return true;
    }

    return false;
}

bool bad(int milk){
    for(int i = 1; i <= s; i++){
        if(!drank(pSick[i], milk, tSick[i])) return false;
    }

    return true;
}

int count(int milk){
    std::set<int> cow;
    for(int i = 1; i <= d; i++){
        if(mDrink[i] == milk){
            cow.insert(pDrink[i]);
        }
    }

    return cow.size();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("badmilk");
    
    std::cin >> n >> m >> d >> s;
    
    for(int i = 1; i <= d; i++){
        std::cin >> pDrink[i] >> mDrink[i] >> tDrink[i];
    }

    for(int i = 1; i <= s; i++){
        std::cin >> pSick[i] >> tSick[i];
    }

    int ans = 0;
    for(int i = 1; i <= m; i++){
        if(bad(i)){
            ans = std::max(ans, count(i));
        }
    }

    std::cout << ans << nl;
}   





