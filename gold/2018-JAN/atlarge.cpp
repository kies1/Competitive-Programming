//There's an exit at the nodes with one connection
//Place a farmer at each of those nodes
//If the farmer's distance to a point is less than or equal to Bessie, then you've caught her
//Add one to your answer everytime you catch her

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

int main(){
    fastRead();
    setIO("atlarge");

    int n,k;
    cin>>n>>k;

    vector<vector<int> > adj(n+2);

    for(int i = 1; i<n; i++){
        int a,b; cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<ll> distBessie(n+2, INT_MAX);
    vector<ll> distFarmer(n+2, INT_MAX);

    //Distance Bessie takes to every point from K

    queue<int> q;
    q.push(k);
    distBessie[k]=0;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto child: adj[x]){
            if(distBessie[x]+1<distBessie[child]){
                distBessie[child]=distBessie[x]+1;
                q.push(child);
            }
        }
    }

    
    for(int i = 1; i<=n; i++){
        if(adj[i].size()==1){ //if it's an "exit" or connected to only one other node
            q.push(i);
            distFarmer[i]=0;
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto child: adj[x]){
            if(distFarmer[x]+1 < distFarmer[child]){
                distFarmer[child]=distFarmer[x]+1;
                q.push(child);
            }
        }
    }

    int ans = 0;
    q.push(k);
    vector<bool> visited(n+1, false);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(distFarmer[x] <= distBessie[x]){
            ans++;
            continue;
        }

        if(visited[x]){
            continue;
        }

        visited[x]=true;

        for(auto child: adj[x]){
            q.push(child);
        }
    }

    cout<<ans<<endl;
}
