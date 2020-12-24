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
const int MOD = 998244353;
const double pi = acos(-1);

template <typename T>
struct BIT {
    int n;          // 配列の要素数(数列の要素数+1)
    vector<T> bit;  // データの格納先
    BIT(int n_) : n(n_ + 1), bit(n, 0) {}
    
    //一点加算
    void add(int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }

    //区間和(1,...,i)
    T sum(int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[idx];
        }
        return s;
    }
    
    //区間和(l,...,r)
    T sum(int l, int r) {
        return sum(r)-sum(l);
    }

    //w番目に小さい値を取得
    int lower_bound(T w) {
        if(w <= 0) return 0;
        else {
            int x = 0, r = 1;
            while(r < n) r = r << 1;
            for(int len = r; len > 0; len /= 2) {
                if(x+len < n && bit[x+len] < w) {
                    w -= bit[x+len];
                    x += len;
                }
            }
            return x+1;
        }
    }
};
