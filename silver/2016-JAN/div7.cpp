#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int n; cin>>n;
	vector<long long> v(n);
	int first; cin>>first;
	v[0]=first%7;
	for(int i = 1; i < n; i++){
		int x; cin>>x;
		v[i]=(v[i-1]+x)%7;
	}
	vector<int> s(7,-1);
	int ans = 0;
	for(int i = 0; i <n; i++){
		if(s[v[i]]==-1){
			s[v[i]]=i;
		}else{
			ans=max(ans,i-s[v[i]]);
		}
	}
	cout<<ans;
}

//prefix sum modulo 7 bcuz lets say u have 1,3,4 so the ps array is 1,4,8 and the modulo 7 ps array is 1,4,1 so everything between the same modulo # is divisible by 7

/*
SLOWER SOLUTION ONLY GETS 8/10

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int n; cin>>n;
	vector<long long> v(n);
	int first; cin>>first;
	v[0]=first;
	for(int i = 1; i < n; i++){
		int x; cin>>x;
		v[i]=v[i-1]+x;
	}
	int M = 0;
	for(int i = n-1; i >=0;  i--){
		for(int j = 0; j<i; j++){
			long long curr = v[i]-v[j];
			if(curr%7==0&&i-j>M){
				M=i-j;
			}
		}
	}
	cout<<M;
}
*/
