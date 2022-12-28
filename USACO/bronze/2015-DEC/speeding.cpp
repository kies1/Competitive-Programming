#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int M = 0;
    vector< pair<int,int> > road;
    vector< pair<int,int> > cow;
    int n1,n2;
    cin>>n1>>n2;
    while(n1--){
        int a,b;
        cin>>a>>b;
        road.push_back(make_pair(a,b));
    }
    while(n2--){
        int a,b;
        cin>>a>>b;
        cow.push_back(make_pair(a,b));
    }
    int ind_road = 0;
    int ind_cow = 0;
    while(true){
        int speed_over = cow[ind_cow].second- road[ind_road].second;
        if(speed_over>M)M=speed_over;
        int diff = min(cow[ind_cow].first,road[ind_road].first);
        cow[ind_cow].first -= diff;
        
        road[ind_road].first -= diff;
        if(cow[ind_cow].first==0)ind_cow++;
        if(road[ind_road].first==0)ind_road++;
        if(cow[cow.size()-1].first==0)break;
    }
    cout<<M;
}
