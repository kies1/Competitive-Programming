#include <bits/stdc++.h>
#include <complex>
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


void solve(){
    int n; std::cin >> n;
    std::vector<bool> cards(2 * n + 1);
    std::vector<int> elsie;
    std::vector<int> bessie;

    for(int i = 0; i < n; i++){
        int x; std::cin >> x;
        elsie.push_back(x);
        cards[x] = true;
    }

    for(int i = 1; i <= 2 * n; i++){
        if(!cards[i]) bessie.push_back(i);
    }

    std::sort(elsie.begin(), elsie.end());
    std::sort(bessie.begin(), bessie.end());

    int wins = 0;
    int b = 0, e = 0;

    while(b < n && e < n){
        if(bessie[b] > elsie[e]){
            wins++;
            b++;
            e++;
        }else{
            b++;
        }
    }

    std::cout << wins << nl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    setIO("highcard");
    solve();
    
}   





