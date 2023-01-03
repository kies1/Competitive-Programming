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

int timeVis [2000][2000];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("mowing");
    
    int n; std::cin >> n;
    std::vector<char> dir(n);
    std::vector<int> len(n);

    for(int i = 0; i < n; i++){
        std::cin >> dir[i] >> len[i];
    }

    memset(timeVis, -1, sizeof(timeVis));


    timeVis[1000][1000] = 0;
    
    int centerX = 1000;
    int centerY = 1000;
    int time = 0;
    int ans = 1001;
    for(int i = 0; i < n; i++){
        if(dir[i] == 'N'){
            for(int j = 0; j < len[i]; j++){
                centerX--;
                time++;
                
                if(timeVis[centerX][centerY] > 0){
                    ans = std::min(time - timeVis[centerX][centerY], ans);
                }
                timeVis[centerX][centerY] = time;
            }
        }else if(dir[i] == 'W'){
            for(int j = 0; j < len[i]; j++){
                centerY--;
                time++;
                
                if(timeVis[centerX][centerY] > 0){
                    ans = std::min(time - timeVis[centerX][centerY], ans);
                }
                timeVis[centerX][centerY] = time;
            }
        }else if(dir[i] == 'E'){
            for(int j = 0; j < len[i]; j++){
                centerY++;
                time++;
                
                if(timeVis[centerX][centerY] > 0){
                    ans = std::min(time - timeVis[centerX][centerY], ans);
                }

                timeVis[centerX][centerY] = time;

            }
        }else{
            for(int j = 0; j < len[i]; j++){
                centerX++;
                time++;
                
                if(timeVis[centerX][centerY] > 0){
                    ans = std::min(time - timeVis[centerX][centerY], ans);
                }
                timeVis[centerX][centerY] = time;
            }
        }
    }

    if(ans == 1001) ans = -1;
    std::cout << ans << nl;
    
}   



