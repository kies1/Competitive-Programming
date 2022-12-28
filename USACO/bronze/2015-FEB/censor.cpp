
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

const int MOD = (int) 1e9+7;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void fastRead(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastRead();
    setIO("censor");
    string s;
    cin >> s;
    string censor;
    cin >> censor;
    string ans;
    int n = s.length();
    int nc = censor.length();

    for(int i = 0; i < n; i++){
        if(ans.size() >= nc){
            if(ans.substr(ans.size()-nc) == censor){
                ans.resize(ans.size()-nc);
            }
        }

        ans += s[i];
    }

    cout << ans <<endl;
}

