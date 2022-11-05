/*
Find the # of operations where the tweaked array will be the same as the original array
Perform the two operations k%(# of operations) times
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = (int) 1e9+7;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void fastRead(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


int main() {
    fastRead();

    setIO("swap");
    int n; cin >> n;
    int k; cin >> k;
    int a1, b1, a2, b2; 
    cin >> a1 >> b1 >> a2 >> b2;
    a1--, b1--, a2--, b2--;
    vector<int> a;
    vector<int> b;

    for(int i = 0; i < n; i++){
        a.push_back(i + 1);
        b.push_back(i + 1);
    }

    int pivot = -1;
    for(int i = 0; i < k; i++){
        reverse(a.begin() + a1, a.begin() + b1 + 1);
        reverse(a.begin() + a2, a.begin() + b2 + 1);
        bool ok = true;
        for(int j = 0; j < n; j++){
            if(a[j] != b[j]) ok = false;
        }

        if(ok){
            pivot = i + 1;
            break;
        }

    }

    if(pivot == -1){
        for(int i = 0; i < n; i++){
            cout << a[i] << endl;
        }
    }else{
        k = k%pivot;
        while(k--){
            reverse(b.begin() + a1, b.begin() + b1 + 1);
            reverse(b.begin() + a2, b.begin() + b2 + 1);
        }

        for(int i = 0; i < n; i++){
            cout << b[i] << endl;
        }
    }
}
