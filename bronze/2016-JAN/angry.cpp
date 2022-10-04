
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
vector<int> haybales;


int main(){
    fastRead();
    setIO("angry");

    cin >> n;

    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        haybales.pb(x);
    }

    sort(haybales.begin(), haybales.end());
    int ans = 1;

    for(int i = 0; i < n; i++){
        int start = haybales[i];
        int radius = 1;
        int currIndex = i;
        int exploded = 1;
        while(currIndex >= 0 && currIndex < n){
            
            while(currIndex - 1 >=0 && currIndex - 1 < n && abs(start - haybales[currIndex-1]) <= radius){
                exploded++;
                currIndex--;
            }

            if(start == haybales[currIndex]){
                break;
            }else{
                start = haybales[currIndex];
                radius++;
            }
        }

        start = haybales[i];
        radius = 1;
        currIndex = i;

        while(currIndex >= 0 && currIndex < n){
            
            while(currIndex + 1>=0 && currIndex + 1 < n && abs(start - haybales[currIndex+1]) <= radius){
                exploded++;
                currIndex++;
                
            }

            if(start == haybales[currIndex]){
                break;
            }else{
                start = haybales[currIndex];
                radius++;
            }
        }

        

        ans = max(ans, exploded);
        
    }

    cout << ans << endl;
}

