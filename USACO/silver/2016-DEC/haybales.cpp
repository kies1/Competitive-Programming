//For all queries, find the lowerbound and upperbound index
//The answer is index(upper) - index(lower) + 1 

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

int n, q;
vector<int> a;

int main(){
    fastRead();
    setIO("haybales");

    cin >> n >> q;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.pb(x);
    }

    sort(a.begin(), a.end());
    for(int i = 0; i < q; i++){
        int lowerbound, upperbound;
        cin >> lowerbound >> upperbound;
        int indexLower, indexUpper;

        int l = -1, r = n;

        while(r > l + 1){
            int mid = (r + l) / 2;

            if(a[mid] >= lowerbound){
                r = mid;
            }else{
                l = mid;
            }
        }

        indexLower = r;
        l = -1;
        r = n;

        while(r > l + 1){
            int mid = (r + l) / 2;

            if(a[mid] <= upperbound){
                l = mid;
            }else{
                r = mid;
            }
        }

        indexUpper = l;

        cout << indexUpper << indexLower;
        cout << indexUpper - indexLower + 1 << endl;
    }

}
