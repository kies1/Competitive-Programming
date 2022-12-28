#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<long long>v;
    for(int i = 0; i <3;i++){
        long long input; cin>>input;
        v.push_back(input);
    }
    sort(v.begin(),v.end());
    if(v[2]-v[1]==2||v[1]-v[0]==2){
        cout<<1<<endl;
    }else if(v[2]==v[1]+1&&v[1]==v[0]+1){
        cout<<0<<endl;
    }
    else{
        cout<<2<<endl;
    }
    cout<<max(v[1]-v[0]-1,v[2]-v[1]-1);
}   
