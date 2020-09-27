template <typename T>
struct RSQ {

    //初期化
    const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RSQ(int n_) : n(), dat(n_ * 4, 0) { // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    //値の更新
    void update(int i, T x) {
        i += n-1;
        T before = dat[i];
        dat[i] = x;
        while(i > 0) {
            i = (i-1)/2;
            dat[i] += x - before;
        }
    }

    //任意区間の最小値
    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return 0;
        else if(a <= l && r <= b) return dat[k];
        else {
            T v1 = query_sub(a,b,2*k+1,l,(l+r)/2);
            T v2 = query_sub(a,b,2*k+2,(l+r)/2,r);
            return v1+v2;
        }
    }
};
