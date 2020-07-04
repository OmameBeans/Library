#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const int INF = 1e9;
veci dp(100010,INF), a(100010);

int LIS(veci &dp, veci &a, int N) {
    REP(i,N) {
        int l = -1;
        int r = N;
        while(r-l > 1) {
            int mid = (r+l)/2;
            if(dp[mid] >= a[i]) r = mid;
            else l = mid;
        }
        if(r != N) dp[r] = a[i];
    }
    int l = -1;
    int r = N;
    while(r-l > 1) {
        int mid = (r+l)/2;
        if(dp[mid] < INF) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
    int N; cin >> N;
    REP(i,N) cin >> a[i];
    cout << LIS(dp,a,N) << endl;
}