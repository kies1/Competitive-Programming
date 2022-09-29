//When intializing the grid, put 1 for all the # and 0 for all the .
//Do floodfill
//For each # encounter, add one to the area 
//For each # encounter, if to either 4 sides, there's a . or it's out of bounds, add one to the perimeter

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

int maxArea = 0;
int minP = 0;

int currArea = 0;
int currP = 0;

int grid[1001][1001];
bool visited[1001][1001];
int n;

void floodfill(int r, int c, int color){
    if(r<0 || r>=n || c<0 || c>=n || grid[r][c]!=color){
        currP++;
        return;
    }

    if(visited[r][c]){
        return;
    }

    visited[r][c]=true;
    currArea++;

    floodfill(r+1, c, color);
    floodfill(r-1, c, color);
    floodfill(r, c+1, color);
    floodfill(r, c-1, color);
}

int main(){
    fastRead();
    setIO("perimeter");

    cin>>n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char c; cin>>c;

            if(c=='#'){
                grid[i][j]=1; //ice cream
            }else{
                grid[i][j]=0; //empty space
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            
            if(visited[i][j]==false && grid[i][j]==1){
                currArea=0;
                currP=0;

                floodfill(i, j, 1);

                if(currArea==maxArea){
                    minP = min(minP, currP);
                }else if(currArea>maxArea){
                    maxArea=currArea;
                    minP = currP;
                }
            }
        }
    }

    cout<<maxArea<<" "<<minP<<endl;
}
