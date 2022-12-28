//Works for all cases except for #4, it's a decimal number and not an integer (weird case huh)

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

int n;
int cows;
vector<ll> haybales;

bool good(ll x){
    vector<bool> hit (n + 1, false);
    int cowsLeft = cows;
    int upperBound = haybales[0] + 2*x;
    cowsLeft--;

    for(int i = 0; i < n; i++){
        if(cowsLeft < 0) break;

        if(hit[i]==false && upperBound >= haybales[i]){
            hit[i]=true;
        }else if (upperBound < haybales[i]){
            upperBound = haybales[i] + 2*x;
            hit[i]=true;
            cowsLeft--;
        }
    }

    bool ok = true;
    for(int i = 0; i < n; i++){
        if(hit[i]==false){
            ok = false;
        }
    }

    return ok;
}

int main(){
    fastRead();
    setIO("angry");

    cin >> n >> cows;

    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        haybales.pb(x);
    }

    sort(haybales.begin(), haybales.end());

    ll lo = 0;
    ll hi = haybales[n-1] + 1;

    
    while(hi > lo + 1){
        int mid = (hi + lo) / 2;

        if(good(mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }

    cout << hi << endl;
}
