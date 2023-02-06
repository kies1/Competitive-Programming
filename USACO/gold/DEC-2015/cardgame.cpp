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


    void solve(){
        int n; std::cin >> n;
        std::vector<bool> cards(2 * n + 1);
        std::vector<int> elsieFirstHalf;
        std::vector<int> elsieSecondHalf;

        for(int i = 0; i < n / 2; i++){
            int x; std::cin >> x;
            elsieFirstHalf.push_back(x);
            cards[x] = true;
        }

        for(int i = 0; i < n / 2; i++){
            int x; std::cin >> x;
            elsieSecondHalf.push_back(x);
            cards[x] = true;
        }

        std::vector<int> bessie;

        for(int i = 1; i <= 2 * n; i++){
            if(!cards[i]) bessie.push_back(i);
        }

        std::sort(bessie.begin(), bessie.end());
        std::vector<int> bessieFirstHalf;
        std::vector<int> bessieSecondHalf;

        for(int i = n / 2; i < n; i++) bessieFirstHalf.push_back(bessie[i]);
        for(int i = 0; i < n / 2; i++) bessieSecondHalf.push_back(bessie[i]);
        
        std::sort(elsieFirstHalf.begin(), elsieFirstHalf.end());
        std::sort(bessieFirstHalf.begin(), bessieFirstHalf.end());

        int wins = 0;
        int b = 0, e = 0;
        while(b < n / 2 && e < n / 2){
            if(bessieFirstHalf[b] > elsieFirstHalf[e]){
                wins++;
                b++, e++;
            }else{
                b++;
            }
        }

        std::sort(elsieSecondHalf.rbegin(), elsieSecondHalf.rend());
        std::sort(bessieSecondHalf.rbegin(), bessieSecondHalf.rend());

        b = 0, e = 0;
        
        while(b < n / 2 && e < n / 2){
            if(bessieSecondHalf[b] < elsieSecondHalf[e]){
                wins++;
                b++, e++;
            }else{
                b++;
            }
        }

        std::cout << wins << nl;
    }

    int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        setIO("cardgame");
        solve();
        
    }   





