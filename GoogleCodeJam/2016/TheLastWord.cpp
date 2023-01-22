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

void solve(int test_case){
    std::string original; std::cin >> original;

    std::string ans;
    ans += original[0];
    for(int i = 1; i < original.length(); i++){
        if(original[i] >= ans[0]){
            std::string temp;
            temp += original[i];
            temp += ans;
            ans = temp;
        }else{
            ans += original[i];
        }
    }

    std::cout << "Case #" << test_case << ": " << ans << nl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    for(int i = 1; i <= tt; i++){
        solve(i);
    }
    
}