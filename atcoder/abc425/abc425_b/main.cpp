#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <stdio.h>
#include <cassert>
#define ll long long
#define ld long double
#define MOD(x,y) (x%y+y)%y
using namespace std;

//modular exponentiation: calculates a^b mod c where a^b is a crazy big number and would usually overflow. Change mod above as needed
ll mpow(ll base, ll exp)
{
    ll mod=1e9+7;
    //ll mod=1000;
    base %= mod;
    ll result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

int main() {
    cout << fixed << setprecision(11);//allows large decimal numbers
    //input code
    ll N;
    cin >> N;

    vector<ll> A(N);

    for(ll i=0;i<N;i++){
        ll temp;
        cin >> temp;
        A[i] = temp;
    }

    //functions

    auto solve = [&]()->void{
        //solve code
        map<ll,ll> freq;

        for(auto i:A){
            freq[i] += 1;

            if(freq[i] >= 2 && i != -1){
                cout << "No";
                return;
            }
        }

        cout << "Yes" << endl;


        vector<ll> numsLeft;

        for(ll i=1;i<=N;i++){
            if(freq.find(i) == freq.end()){
                numsLeft.push_back(i);
            }
        }

        ll curInd = 0;
        for(ll i=0;i<N;i++){
            if(A[i] == -1){
                cout << numsLeft[curInd] << ' ';
                curInd++;
            }else {
                cout << A[i] << ' ';
            }
        }
        // map<ll,ll> pos;
        // for(ll i=0;i<N;i++){
        //     if(A[i] == -1) continue;

        //     pos[A[i]] = i;
        // }

        // ll runningTotal = 1;
        // for(ll i=0;i<N;i++){
        //     if(pos.find(A[i]) == pos.end()) {
        //         cout << runningTotal << ' ';
        //     } else {
        //         cout << A[i] << ' ';
        //     }

        //     runningTotal +=1;
        //     if(pos.find(runningTotal) != pos.end()){
        //         runningTotal += 1;
        //     }

        // }


        return;
    };
    solve();
}