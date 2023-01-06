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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("balancing");
    
    int n; std::cin >> n;
    int b; std::cin >> b;

    std::vector<std::pair<int, int> > coords(n);

    for(int i = 0; i < n; i++){
        std::cin >> coords[i].x >> coords[i].y;
    }

    std::sort(coords.begin(), coords.end());

    int ans = n;

    for(int k = 0; k < n; k++){
        for(int j = 0; j < n; j++){
            int ySplit = coords[k].x + 1;
            int xSplit = coords[j].y + 1;

            int q1 = 0;
            int q2 = 0;
            int q3 = 0;
            int q4 = 0;

            for(int i = 0; i < n; i++){
                if(coords[i].x > ySplit && coords[i].y > xSplit){
                    q1++;
                }else if(coords[i].x > ySplit && coords[i].y < xSplit){
                    q2++;
                }else if(coords[i].x < ySplit && coords[i].y < xSplit){
                    q3++;
                }else{
                    q4++;
                }
            }

            int curr = std::max(q1, std::max(q2, std::max(q3, q4)));
            ans = std::min(ans, curr);
        }
    }

    std::cout << ans << nl;
}   



