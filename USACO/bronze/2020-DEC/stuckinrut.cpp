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
std::vector<std::array<ll, 3> > north;
std::vector<std::array<ll, 3> > east;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    for(int i = 0; i < n; i++){
        char dir; 
        int x, y;
        std::cin >> dir >> x >> y;
        if(dir == 'N'){
            north.push_back({x, y, i});
        }else{
            east.push_back({x, y, i});
        }
    }

    std::sort(north.begin(), north.end());
    std::sort(east.begin(), east.end(), [](auto &left, auto &right) {
		return left[1] < right[1];
	});

    std::vector<ll> grass(n, -1);

    for(auto n_cow: north){
        for(auto e_cow: east){
            if(n_cow[0] > e_cow[0] && e_cow[1] > n_cow[1]){
                ll nTime = e_cow[1] - n_cow[1];
                ll eTime = n_cow[0] - e_cow[0];

                if(nTime < eTime && grass[e_cow[2]] == -1){
                    grass[e_cow[2]] = eTime;
                }else if(nTime > eTime && grass[e_cow[2]] == -1){
                    grass[n_cow[2]] = nTime;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(grass[i] == -1){
            std::cout << "Infinity" << nl;
        }else{
            std::cout << grass[i] << nl;
        }
    }
}   



