
#include <bits/stdc++.h>
#include <tuple>
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
int total = 0;
vector<double> a;



bool good(double guess){
    vector<double> temp = a;

    for(int i = 0; i < n; i++){
        temp[i] -= guess;
    }

    pair<double, int> best = {-6969, 0};
    pair<double, int> curr = {-6969, 0};
    for(int i = 1; i < n - 1; i++){
        if(curr.first < 0){
            curr.first = 0;
            curr.second = 0;
        }
        curr.first += temp[i];
        if(curr.first > best.first){
            best.first = curr.first;
            best.second = curr.second;
        }
    }

    return (total - (best.first + best.second * guess)) / (n - best.second) <= guess; 
}


int main() {
    fastRead();
    setIO("sabotage");
    cin >> n;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
        total += x;
    }

    double lo = 0;
    double hi = 1e5;

    
    for(int i = 0; i < 50; i++){
        double mid = (lo + hi) / 2;

        if(good(mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    

    cout << fixed << setprecision(3) << hi << endl;
}
