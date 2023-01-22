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
    int n; std::cin >> n;
    std::vector<std::pair<int, char> > ppl(n);
    int currSum = 0;

    for(int i = 0; i < n; i++){
        std::cin >> ppl[i].first;
        ppl[i].second = ((char)'A' + i);
        currSum += ppl[i].first;
    }

    std::vector<char> ans;
    while(currSum > 0){
        std::sort(ppl.begin(), ppl.end());

        ans.push_back(ppl[n - 1].second);
        currSum--, ppl[n - 1].first--;

        if(currSum % 2 == 1 && currSum > 0){
            std::sort(ppl.begin(), ppl.end());
            ans.push_back(ppl[n - 1].second);
            currSum--, ppl[n - 1].first--;
        }

        ans.push_back(' ');
    }
    

    std::cout << "Case #" << test_case << ": ";
    for(auto x: ans) std::cout << x;
    std::cout << nl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    for(int i = 1; i <= tt; i++){
        solve(i);
    }
    
}   