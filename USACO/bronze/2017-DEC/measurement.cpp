
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

int n;
vector<tuple<int, string, int> > t;
map<string, int> scores;
// bessie, elsie, mildred -- in this order
int main() {
    fastRead();
    setIO("measurement");
	cin >> n;

	scores["Bessie"] = 7;
	scores["Elsie"] = 7;
	scores["Mildred"] = 7;

	for(int i = 0; i < n; i++){
		int day; cin >> day;
		string cow; cin >> cow;
		string change; cin >> change;

		if(change[0]=='+'){
			int num = change[1] - '0';
			t.push_back(make_tuple(day, cow, num));
		}else{
			int num = change[1] - '0';
			num = -num;
			t.push_back(make_tuple(day, cow, num));
		}
	}	

	sort(t.begin(), t.end());
	int ans = 0;

	vector<bool> lastLeaders (3, false);
	for(int i = 0; i < n; i++){

		if(get<1>(t[i]) == "Bessie"){
			scores["Bessie"] += get<2>(t[i]);
		}else if(get<1>(t[i]) == "Elsie"){
			scores["Elsie"] += get<2>(t[i]);
		}else if(get<1>(t[i]) == "Mildred"){
			scores["Mildred"] += get<2>(t[i]);
		}

		int currMax = max(scores["Bessie"], max(scores["Elsie"], scores["Mildred"]));

		bool ok = false;

		if(scores["Bessie"] == currMax){
			if(i >= 0){
				if(lastLeaders[0]!=true){
					if(!ok){
						ans++;
						ok = true;
					}
				}
			}
			lastLeaders[0]=true;
		}else{
			if(i >= 0){
				if(lastLeaders[0]==true){
					if(!ok){
						ans++;
						ok = true;
					}
				}
			}
			lastLeaders[0]=false;
		}
		if(scores["Elsie"] == currMax){
			if(i >= 0){
				if(lastLeaders[1]!=true){
					if(!ok){
						ans++;
						ok = true;
					}
				}
			}
			lastLeaders[1]=true;
		}else{
			if(i >= 0){
				if(lastLeaders[1]==true){
					if(!ok){
						ans++;
						ok = true;
					}
				}
			}
			lastLeaders[1]=false;
		}
		if(scores["Mildred"] == currMax){
			if(i >= 0){
				if(lastLeaders[2]!=true){
					if(!ok){
						ans++;
						ok = true;
					}
				}
			}
			lastLeaders[2]=true;
		}else{
			if(i >= 0){
				if(lastLeaders[2]==true){
					if(!ok){
						ans++;
						ok = true;
					}
				}
			}
			lastLeaders[2]=false;
		}
	}

	cout << ans << endl;
}
