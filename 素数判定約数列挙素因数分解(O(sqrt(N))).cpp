#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool is_prime(long long n) {
    for(long long i = 2; i * i <= n; i++) {
        if(n%i == 0) return false;
    }
    return n != 1;
}

vector<long long> divisor(long long n) {
    vector<long long> res;
    for(long long i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    return res;
}

map<long long, long long> prime_factor(long long n) {
    map<long long, long long> m;
    for(long long i = 2; i * i <= n; i++) {
        if(n%i == 0) {
            while(n%i == 0) {
                m[i]++;
                n /= i;
            }
        }
    }
    if(n != 1) m[n]++;
    return m;
}

int main() {
    long long n; cin >> n;
    cout << is_prime(n) << endl;
    for(auto x : divisor(n)) cout << x <<" ";
    cout << endl;
    for(auto x : prime_factor(n)) cout << x.first << " " << x.second << endl;
}
