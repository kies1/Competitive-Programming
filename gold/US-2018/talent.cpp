#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first 
#define s second 

const int MOD = (int) 1e9+7;
const int INF = 2000000000;



void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

ll solve(){

    ll T; //number of cows
    ll W; //weight required
    vector<pair<int, int> > cow (1e7); //first is Weight, second is Talent

    cin>>T>>W;

    int sumT = 0;

    for(int i = 1; i<=T; i++){
        cin>>cow[i].f>>cow[i].s;
        sumT+=cow[i].s;
    }

    vector<vector<int> > dp(T+1, vector<int> (sumT+1, INF));

    dp[0][0]=0;

    for(int i=1; i<=T; i++){
        for(int j = 0; j<=sumT; j++){
            if(j-cow[i].s>=0){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-cow[i].s]+cow[i].f);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    int ans = 0;

    for(int i = 1; i<=sumT; i++){
        if(dp[T][i]>=W){
            ans=max(ans, (i*1000)/dp[T][i] );
        }
    }

    return ans;
}

int main() {
    setIO("talent");
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cout<<solve()<<endl;
}

//make a standard knapsack
//after weight W, finding the max ratio ones
