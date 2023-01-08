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

int n;
std::vector<int> a;

bool good(int x){
    ll currSum = 0;

    for(int i = 0; i < n; i++){
        currSum += a[i];
        if(currSum > x){
            return false;
        }

        if(currSum == x){
            currSum = 0;
        }
    }

    return true;
}

void solve(){
    std::cin >> n;
    a.resize(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        sum += a[i];
    }
    
    for(int i = 0; i <= sum; i++){
        if(i > 0 && sum % i != 0) continue;

        if(good(i)){
            if(i == 0){
                std::cout << 0 << nl;
                break;
            }else{
                std::cout << n - sum / i << nl;
                break;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while(tt--){
        solve();
    }
}   



