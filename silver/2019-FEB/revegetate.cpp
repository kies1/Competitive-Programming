//Have two separate adjecency lists for S and D
//Perform Bipartite DFS
//For S, the neighbors must be same
//For D, the neighors must be different

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

const int MN = 1e5+1;
bool impossible = false;
vector<vector<int> > adjS (MN);
vector<vector<int> > adjD (MN);

vector<bool> visited (MN, false);
vector<bool> grass (MN);
void dfs(int node, bool color=false){
    visited[node]=true;
    grass[node]=color;
    
    for(auto child: adjS[node]){
        if(visited[child]){
            if(grass[child]!=color){
                impossible=true;
            }
        }else{
            dfs(child, color);
        }
    }

    for(auto child: adjD[node]){
        if(visited[child]){
            if(grass[child]==color){
                impossible=true;
            }
        }else{
            dfs(child, !color);
        }
    }
}

int main(){
    fastRead();
    setIO("revegetate");

    int n; cin>>n; //pastures
    int cows; cin>>cows;

    while(cows--){
        char c; cin>>c;
        int a,b;
        cin>>a>>b;

        if(c=='S'){
            adjS[a].pb(b);
            adjS[b].pb(a);
        }else{
            adjD[a].pb(b);
            adjD[b].pb(a);
        }
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }

    if(impossible){
        cout<<0<<endl;
        return 0;
    }else{
        cout<<1;
        while(ans--){
            cout<<0;
        }
    }
}
