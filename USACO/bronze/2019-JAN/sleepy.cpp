#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sleepy.in", "r", stdin);
	  freopen("sleepy.out", "w", stdout);
    vector<int>v;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int input; cin >>input;
        v.push_back(input);
    }
    int in_order = 1;
    for(int i = n-1;i>=1;i--){
        if(v[i]>v[i-1]){
            in_order++;
        }else{
            break;
        }
    }
    cout<<n-in_order;
} 
