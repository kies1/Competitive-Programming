#include <bits/stdc++.h> 
using namespace std;


int arr[100002];
long long walked[100002];
bool visted[100002];
int parked[100002];

int find_parked(int a) {
    if (parked[a] == a) return a;
    return parked[a] = find_parked(parked[a]);
}

int main() {
    /*
    int n;
  cin >> n;
  int yesorno[n];
  //setting up visited/dsu array so parent become itself
  for (int i = 0; i < n; i++) {
    visited[i]=false;
    dsu[i]=i;
  }
  long long ans = 0;

  for (int i = 0; i < n; i++) {
    cin >> cowgoto[i] >> weight[i];
    cowgoto[i]--;
    combine(cowgoto[i],weight[i]);
    ans += weight[i];
    yesorno[i]=0;
  }




  for(int i = 0; i<n; i++){
    yesorno[find(i)]=1;
  }

  //solving using cycle detection
  for (int i = 0; i < n; i++) {
    if(yesorno[i]==1){
      int cur = yesorno[i];
      while(true){

        if(visited[cur]==true){
          break;
        }
        visited[cur]=true;
        cur=cowgoto[cur];
      }
      long long smallestCycle=INT_MAX;
      for(int j = 0; j<n+1;j++){
        if(smallestCycle>weight[cur]){
          smallestCycle=weight[cur];
        }
        cur=cowgoto[cur];
      }
      ans=ans-smallestCycle;
    }

    }
  cout<<ans;*/
    int n;
    cin >> n;
    for (int i = 0; i < 100002; i++) {
        parked[i] = i;
        visted[i] = false;
    }
    //visited array so parent become itself
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> walked[i];
        parked[i] = find_parked(arr[i]);
        ans += walked[i];
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (parked[i] == i) v.push_back(i);
    }
    //find cycle
    for (int i = 0; i < v.size(); i++) {
        int a = v[i];
        int t = a;
        while (true) {
            if (visted[t]) {
                a = t;
                break;
            }
            visted[t] = true;
            t = arr[t];
        }
        int purr = arr[a];
        long long min = 10000000000;
        while (true) {
            if (walked[purr] < min) min = walked[purr];
            if (purr == a) break;
            purr = arr[purr];
        }
        ans -= min;
    }

    cout << ans << endl;

    return 0;
}
