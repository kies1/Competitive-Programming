#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x,y,m;
    cin>>x>>y>>m;
    int M = 0;
    int curr = 0;
    while(curr<=m){
        curr+=y;
    }
    if(curr>m)curr-=y;
    M = max(curr,M);
    int turns = curr/y;
    while(turns--){
        curr-=y;
        while(curr<=m){
            curr+=x;
        }
        if(curr>m)curr-=x;
        M=max(curr,M);
    }
    int curr2=0;
    while(curr2<=m){
        curr2+=x;
    }
    if(curr2>m)curr2-=x;
    M = max(curr2,M);
    int turns2 = curr2/x;
    while(turns2--){
        curr2-=x;
        while(curr2<=m){
            curr2+=y;
        }
        if(curr2>m)curr2-=y;
        M=max(curr2,M);
    }
    cout<<M;
}   
