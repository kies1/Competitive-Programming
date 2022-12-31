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
    setIO("lostcow");

    int moves = 0;
    int x, y; std::cin >> x >> y;  

    int deviation = 1;
    bool sign = true; //true is positive, false if negative
    int cloci = x; //current location
    
    while(true){
        moves += abs(cloci - x);
        cloci = x;
        for(int i = 1; i <= deviation; i++){
            
            if(sign == true){
                cloci++;
            }else{
                cloci--;
            }
            moves++;
            if(cloci == y){
                std::cout << moves << nl;
                return 0;
            }
        }
        sign = !sign;
        deviation *= 2;
    }    
}