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
const int MOD = 1000000007;
const double pi = acos(-1);

template <typename T>
struct RMQ {

    //初期化
    const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RMQ(int n_) : n(), dat(n_ * 4, INF) { // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    //値の更新
    void update(int i, T x) {
        i += n-1;
        dat[i] = x;
        while(i > 0) {
            i = (i-1)/2;
            dat[i] = min(dat[i*2+1],dat[i*2+2]);
        }
    }

    //任意区間の最小値
    // the minimum element of [a,b)
    T query_min(int a, int b) { return query_min_sub(a, b, 0, 0, n); }
    T query_min_sub(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return INF;
        else if(a <= l && r <= b) return dat[k];
        else {
            T v1 = query_min_sub(a,b,2*k+1,l,(l+r)/2);
            T v2 = query_min_sub(a,b,2*k+2,(l+r)/2,r);
            return min(v1,v2);
        }
    }
};

int main() {
    int N,Q; cin >> N >> Q;
    RMQ<int> ST(N);
    REP(i,Q) {
        int c; cin >> c;
        if(c == 0) {
            int x,y; cin >> x >> y;
            ST.update(x,y);
        } else {
            int x,y; cin >> x >> y;
            cout << ST.query_min(x,y+1) << endl;;
        }
    }
}
