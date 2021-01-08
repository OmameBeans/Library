#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
struct SqrtDecomposition {
    const int sqrtN = 512;
    //const T INF = numeric_limits<T>::max();
    const T INF = 0;
    int N, K;
    vector<T> data;
    vector<T> bucket;
    SqrtDecomposition(int n) : N(n) {
        K = (N + sqrtN - 1) / sqrtN;
        data.assign(K * sqrtN, INF);
        bucket.assign(K, INF);
    }

    void update(int x, T y) {
        int k = x / sqrtN;
        data[x] += y;
        T sum = 0;
        for (int i = k * sqrtN; i < (k + 1) * sqrtN; ++i) {
            sum += data[i];
        }
        bucket[k] = sum;
    }

    // [x, y)
    int find(int x, int y) {
        T sum = 0;
        for (int k = 0; k < K; ++k) {
        int l = k * sqrtN, r = (k + 1) * sqrtN;
        if (r <= x || y <= l)
            continue;
        if (x <= l && r <= y) {
            sum += bucket[k];
        } else {
            for (int i = max(x, l); i < min(y, r); ++i) {
                sum += data[i];
            }
        }
        }
        return sum;
    }
    
};

int main() {
    int N,Q; cin >> N >> Q;
    SqrtDecomposition<ll> SD(N);
    for(int i = 0; i < Q; i++) {
        int c; cin >> c;
        if(c == 0) {
            int x;
            ll y;
            cin >> x >> y;
            SD.update(x,y);
        } else {
            int l,r; cin >> l >> r;
            cout << SD.find(l,r+1) << endl;
        }
    }
}
