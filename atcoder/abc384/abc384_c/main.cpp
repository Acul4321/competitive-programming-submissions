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
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    //functions

    auto solve = [&]()->void{
        //solve code
        int qCount = 5;
        vector<pair<string,int>> p(32);
        for(int i=0;i<1<<qCount;i++){
            string q = "";
            int perf = 0;
            for(int j=0;j<qCount;j++){
                if(((i>>j)&1) == 1){
                    if(j == 0){ //A
                        q+= 'A';
                        perf += a;
                    }else if(j == 1){ //B
                        q+= 'B';
                        perf += b;
                    }else if(j == 2){//C
                        q+='C';
                        perf += c;
                    }else if(j == 3){//D
                        q+= 'D';
                        perf += d;
                    }else if(j == 4){//E
                        q+= 'E';
                        perf += e;
                    }
                }
            }
            p[i] = make_pair(q,perf);
        }
        sort(p.begin(), p.end(), [](const pair<string, int>& a, const pair<std::string, int>& b) {
            if(a.second != b.second){
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        for(auto [q,perf]:p){
            if(q == "") continue;
            cout << q << endl;
        }

        return;
    };
    solve();
}