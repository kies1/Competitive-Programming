
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
vector<int> cnt (26, 0);

int main() {
    fastRead();
    setIO("blocks");
    cin >> n;

    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;

        vector<int> countA (26, 0);
        vector<int> countB (26, 0);
        for(int j = 0; j < a.length(); j++){
            countA[a[j]-'a']++;
        }

        for(int j = 0; j < b.length(); j++){
            countB[b[j]-'a']++;
        }



        for(int j = 0; j < 26; j++){
            cnt[j] += max(countA[j], countB[j]);
        }
    }

    
    for(int j = 0; j < 26; j++){
        cout << cnt[j] << endl;
    }
    
}

