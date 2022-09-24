//Make a vector with pair and enter in all the coords
//Loop thru all of the other coords, if they are within range P, connect a uni-directional edge
//Use DFS to check the longest connected range for every single cow, remember to set visited to false after each DFS

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

const int MN = 200;

int ans = 1;
int curr = 0;

vector<vector<int> > adj (MN+1);
vector<bool> visited (MN+1,false);

void dfs(int node){
    visited[node]=true;
    curr++;
    for(auto child: adj[node]){
        if(visited[child]==false){
            dfs(child);
        }
    }
}

int main() {
    fastRead();
    setIO("moocast");
    int n; cin>>n;

    vector<int> P;
    vector<pair<int, int> > coords;

    for(int i = 0; i<n; i++){
        int a,b;
        cin>>a>>b;
        int p; cin>>p;

        coords.push_back(make_pair(a,b));
        P.push_back(p);
    }

    for(int i = 0; i<n; i++){
        int x1 = coords[i].first;
        int y1 = coords[i].second;

        for(int j = 0; j<n; j++){
            if(j==i)continue;

            int x2 = coords[j].first;
            int y2 = coords[j].second;

            int dx = abs(x2-x1);
            int dy = abs(y2-y1);

            if(sqrt(dx*dx + dy*dy)<=P[i]){
                adj[i].push_back(j);
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(visited[i]==false){
            curr=0;
            dfs(i);
            ans=max(ans,curr);
        }

        fill(visited.begin(),visited.end(),false);
    }

    cout<<ans<<endl;
}
