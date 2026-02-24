#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stdio.h>
#include <cassert>
#include <numeric>
#include <utility>
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
    ios::sync_with_stdio(false); //disables the synchronization between the C and C++ standard streams
    cin.tie(nullptr); //This unties cin from cout not ensures that one stream is flushed automatically before each I/O operation on the other stream.
    //input code
    ll N, M;
    cin >> N >> M;
    //functions

    auto solve = [&]()->void{
        //solve code
        map<ll,ll> m;
        for(ll i=0; i<N; i++){
            ll l;
            cin >> l;
            vector<ll> juice(l);
            for(ll j=0; j<l; j++){
                ll a;
                cin >> a;
                juice[j] = a;
            }

            ll pick = juice[0];
            ll ind = 0;
            while(m.count(pick)){
                ind++;
                if(ind == juice.size()){
                    break;
                }
                pick = juice[ind];
            }
            if(ind == juice.size()) cout << 0 << endl;
            else cout << pick << endl;
            m[pick] = 1;

            
        }

        return;
    };
    solve();
}