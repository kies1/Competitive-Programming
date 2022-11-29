#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define nl '\n';

const int MOD = 1e9+7;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fastIO();
    
    int n; cin >> n;
    vector<int> petal(n);

    for(int i = 0; i < n; i++) cin >> petal[i];

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sumPetals = 0;
            for(int k = i; k <= j; k++){
                sumPetals += petal[k];
            }

            for(int k = i; k <= j; k++){
                if(petal[k] * (j - i + 1) == sumPetals){
                    ans++; 
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}
