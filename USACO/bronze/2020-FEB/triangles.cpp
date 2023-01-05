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
    setIO("triangles");
    
    int n; std::cin >> n;
    std::vector<std::pair<int, int> > coords(n);

    for(int i = 0; i < n; i++){
        std::cin >> coords[i].x >> coords[i].y;
    }

    std::sort(coords.begin(), coords.end());

    std::vector<std::array<std::pair<int, int> , 3> > points;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(coords[i].x != coords[j].x) continue;

            for(int k = 0; k < n; k++){
                if(j == k) continue;
                if(coords[k].y != coords[j].y) continue;

                points.push_back({coords[i], coords[j], coords[k]});
                
            }

            for(int k = 0; k < n; k++){
                if(j == k) continue;
                if(coords[k].y != coords[i].y) continue;

                points.push_back({coords[i], coords[j], coords[k]});
            }
        }
    }

    std::vector<int> area;

    for(int i = 0; i < points.size(); i++){
        int dy = abs(points[i][0].y - points[i][1].y);
        int dx = (points[i][2].y == points[i][1].y) ? abs(points[i][2].x - points[i][1].x) : abs(points[i][2].x - points[i][0].x);

        area.push_back(dy * dx);
    }

    std::sort(area.begin(), area.end());

    std::cout << area[area.size() - 1] << nl;
}   



