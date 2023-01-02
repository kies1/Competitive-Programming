#include <bits/stdc++.h>
typedef long long ll;
const int MOD  = 1e9 + 7;
#define nl '\n';
#define dbg(v)                                                                 \
    std::cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';

void setIO(std::string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("censor");
    
    std::string s; std::cin >> s;
    std::string word; std::cin >> word;
    std::string censored;

    for(int i = 0; i < s.length(); i++){
        censored += s[i];

        if(censored.size() >= word.size() && censored.substr(censored.size() - word.size()) == word){
            censored.resize(censored.size() - word.size());
        }
    }

    std::cout << censored << nl;
}   



