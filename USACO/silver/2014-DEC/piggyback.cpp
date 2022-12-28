//BFS finds the shorterst path from one point to another
//Use this logic to find the shortest point from a starting point (for Bessie it would be 1, for Elsie it would be 2)
//Then, find the shortest path from the barn (or the end, or N) to any point
//So if Bessie and Elsie meet up, they can take the shortest route to the barn
//You want to test for all possible points for where they meet up
//The answer will be the minimum of distBessie[meet]*B + distElsie[meet]*E + distEverywhere[meet]*P for all points where they meet

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
    cin.tie(nullptr);
}


int B,E,P,N,M;

const int MN = 1e5+1;
vector<vector<int> > fields(MN);

vector<long long> dist(int start, vector<vector<int> >& adj){
    queue<int> q;
    q.push(start);
    vector<long long> d(MN, INT_MAX);

    d[start]=0;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto child: adj[x]){
            if(d[child]==INT_MAX){
                d[child]=d[x]+1;
                q.push(child);
            }
        }
    }

    return d;
}

int main() {
    setIO("piggyback");
    cin>>B>>E>>P>>N>>M;

    while(M--){
        int a,b;
        cin>>a>>b;

        fields[a].push_back(b);
        fields[b].push_back(a);
    }

    vector<long long> distBessie = dist(1, fields);
    vector<long long> distElsie = dist(2, fields);
    vector<long long> distEverywhere = dist(N, fields);

    long long ans = INT_MAX;

    for(int i = 1; i<=N; i++){
        ans=min(ans,distBessie[i]*B + distElsie[i]*E + distEverywhere[i]*P);
    }

    cout<<ans<<endl;
}
