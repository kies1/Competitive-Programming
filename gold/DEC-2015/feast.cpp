#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int) 1e9+7;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

ll solve(){
    int T; cin>>T;
    int a,b;
    cin>>a>>b;

    vector<ll> dp(T+1);
    dp[0]=0;

    for(int i = 1; i<=T; i++){
        dp[i]=dp[i-1];

        if(i-a>=0){
            dp[i]=max(dp[i],dp[i-a]+a);
        }

        if(i-b>=0){
            dp[i]=max(dp[i],dp[i-b]+b);
        }

    }

    ll ans = dp[T];

    for(int i = 1; i<=T; i++){
        ll x = dp[i]/2 + dp[T-dp[i]/2];
        ans = max(ans,x);
    }

    return ans;
}

int main() {
    setIO("feast");
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout<<solve()<<endl;
}
