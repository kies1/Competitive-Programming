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
    setIO("traffic");
    int n; std::cin >> n;
    std::vector<std::array<int, 3> > traffic(n);
    int firstNormalRamp = -1;
    int lastNormalRamp = -1;
    for(int i = 0; i < n; i++){
        std::string s; std::cin >> s;
        if(s == "on"){
            traffic[i][0] = 1;
        }else if(s == "off"){
            traffic[i][0] = 0;
        }else{
            traffic[i][0] = 2;
            if(firstNormalRamp == -1){
                firstNormalRamp = i;
            }

            lastNormalRamp = i;
        }

        std::cin >> traffic[i][1] >> traffic[i][2];
    }

    std::pair<int, int> firstRate = {-999999, 999999};

    //after the road
    for(int i = 0; i < n; i++){
        if(traffic[i][0] == 2){
            firstRate.first = std::max(traffic[i][1], firstRate.first);
            firstRate.second = std::min(traffic[i][2], firstRate.second);
        }else if(traffic[i][0] == 1){
            firstRate.first += traffic[i][1];
            firstRate.second += traffic[i][2];
        }else{
            firstRate.first -= traffic[i][2];
            firstRate.second -= traffic[i][1];
            firstRate.first = std::max(firstRate.first, 0);
        }
    }

    std::pair<int, int> lastRate = {-999999, 999999};

    //prior to mile 1
    
    for(int i = n - 1; i >= 0; i--){
        if(traffic[i][0] == 2){
            lastRate.first = std::max(traffic[i][1], lastRate.first);
            lastRate.second = std::min(traffic[i][2], lastRate.second);
        }else if(traffic[i][0] == 1){
            lastRate.first -= traffic[i][2];
            lastRate.second -= traffic[i][1];
            lastRate.first = std::max(lastRate.first, 0);
        }else{
            lastRate.first += traffic[i][1];
            lastRate.second += traffic[i][2];
        }
    }

    std::cout << lastRate.first << ' ' << lastRate.second << nl;
    std::cout << firstRate.first << ' ' << firstRate.second << nl;
}

