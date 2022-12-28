#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
    int N,Q;
    cin>>N>>Q;
    vector<long> v;
    for(int i = 0; i < N; i++){
        int ipt; cin>>ipt;
        v.push_back(ipt);
    }
    vector<int> arr1(N,0);
    vector<int> arr2(N,0);
    vector<int> arr3(N,0);
    if(v[0]==1){
        arr1[0]=1;
    }else if(v[0]==2){
        arr2[0]=1;
    }else{
        arr3[0]=1;
    }
    
    for(int i = 1; i < N; i++){
        if(v[i]==1){
            arr1[i]=arr1[i-1]+1;
        }else{
            arr1[i]=arr1[i-1];
        }
    }
    for(int i = 1; i < N; i++){
        if(v[i]==2){
            arr2[i]=arr2[i-1]+1;
        }else{
            arr2[i]=arr2[i-1];
        }
    }
    for(int i = 1; i < N; i++){
        if(v[i]==3){
            arr3[i]=arr3[i-1]+1;
        }else{
            arr3[i]=arr3[i-1];
        }
    }
    for(int i = 0;i<Q;i++){
        int a,b;
        cin>>a>>b;
        cout<<arr1[b-1]-arr1[a-2]<<' '<<arr2[b-1]-arr2[a-2]<<' '<<arr3[b-1]-arr3[a-2]<<endl;
    }
}
