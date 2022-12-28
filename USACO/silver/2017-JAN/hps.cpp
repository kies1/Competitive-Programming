#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
	int n; cin>>n;
	int arr[4][n+1];
	char first; cin>>first;
	if(first=='H'){
		arr[0][0]=1;
		arr[1][0]=0;
		arr[2][0]=0;
	}
	else if(first=='P'){
		arr[1][0]=1;
		arr[0][0]=0;
		arr[2][0]=0;
	}
	else if(first=='S'){
		arr[0][0]=0;
		arr[1][0]=0;
		arr[2][0]=1;
	}
	for(int i = 1; i <n ;i++){
		char c; cin>>c;
		arr[0][i]=arr[0][i-1];
		arr[1][i]=arr[1][i-1];
		arr[2][i]=arr[2][i-1];
		if(c=='H')arr[0][i]++;
		else if(c=='P')arr[1][i]++;
		else if(c=='S')arr[2][i]++;
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		int h_cur = arr[0][i];
		int p_cur = arr[1][i];
		int s_cur = arr[2][i];
		int max_cur = max({h_cur,p_cur,s_cur});
		int ind;
		for(int j = 0 ; j < 3;j++){
			if(max_cur==arr[j][i])ind=j;
		}
		//check the other two
		if(ind==0){
		int curr1 = arr[0][i] + (arr[1][n-1]-arr[1][i]);
		int curr2 = arr[0][i] + (arr[2][n-1]-arr[2][i]);
		ans = max({ans,curr1,curr2});
		}else if (ind==1){
		int curr1 = arr[1][i] + (arr[0][n-1]-arr[0][i]);
		int curr2 = arr[1][i] + (arr[2][n-1]-arr[2][i]);
		ans = max({ans,curr1,curr2});
		}else{
		int curr1 = arr[2][i] + (arr[1][n-1]-arr[1][i]);
		int curr2 = arr[2][i] + (arr[0][n-1]-arr[0][i]);
		ans = max({ans,curr1,curr2});
		}
	}
	cout<<ans;
}
