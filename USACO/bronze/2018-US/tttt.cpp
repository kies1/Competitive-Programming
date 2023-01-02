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

char grid[4][4];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    setIO("tttt");
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> grid[i][j];
        }
    }    

    std::set<char> singleWin;
    std::set<std::pair<char, char> > doubleWin;
    for(int i = 0; i < 3; i++){
        std::set<char> s;
        for(int j = 0; j < 3; j++){
            s.insert(grid[i][j]);
        }
        auto it = s.begin();
        if(s.size() == 1){
            singleWin.insert(*it);
        }
        if(s.size() == 2){
            doubleWin.insert({*it, *++it});
        }
    }

    for(int i = 0; i < 3; i++){
        std::set<char> s;
        for(int j = 0; j < 3; j++){
            s.insert(grid[j][i]);
        }
        auto it = s.begin();
        if(s.size() == 1){
            singleWin.insert(*it);
        }
        if(s.size() == 2){
            doubleWin.insert({*it, *++it});
        }
    }

    std::set<char> st;
    for(int i = 0, j = 0; i < 3; i++){
        st.insert(grid[i][j]);
        j++;
    }
    auto it = st.begin();
    if(st.size() == 1){
        singleWin.insert(*it);
    }
    if(st.size() == 2){
        doubleWin.insert({*it, *++it});
    }
    st.clear();

    for(int i = 0, j = 2; i < 3; i++){
        st.insert(grid[i][j]);
        j--;
    }
    it = st.begin();
    if(st.size() == 1){
        singleWin.insert(*it);
    }
    if(st.size() == 2){
        doubleWin.insert({*it, *++it});
    }
    st.clear();

    std::cout << singleWin.size() << nl;
    std::cout << doubleWin.size() << nl;
    
}



