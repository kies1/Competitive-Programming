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


void solve(){
    int c, m; std::cin >> c >> m;
    std::vector<ll> chickenTime(c);
    std::vector<std::pair<ll, ll> > cowTime(m);

    for(int i = 0; i < c; i++){
        std::cin >> chickenTime[i];
    }

    for(int i = 0; i < m; i++){
        std::cin >> cowTime[i].first >> cowTime[i].second;
    }

    std::sort(chickenTime.begin(), chickenTime.end());
    std::sort(cowTime.begin(), cowTime.end(), [](std::pair<ll, ll> cow1, std::pair<ll, ll> cow2) {
		return cow1.second < cow2.second;
	});

    std::vector<bool> visited(m);
    int ans = 0;
    for(ll chicken: chickenTime){
        for(int i = 0; i < m; i++){
            if(!visited[i] && cowTime[i].first <= chicken && chicken <= cowTime[i].second){
                ans++;
                visited[i] = true;
                break;
            }
        }
    }

    std::cout << ans << nl;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("helpcross");
    solve();  
}   





