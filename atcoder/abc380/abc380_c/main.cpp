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
    ll N,K;
    cin >> N >> K;
    K--;
    string S;
    cin >> S;

    //functions

    auto solve = [&]()->void{
        //solve code
        ll blockTo = K;
        ll onK = 0;
        bool startingF = false;
        ll startingP = K;
        for(ll i=0;i<N;i++){
            if(S[i] == '1' and !startingF){
                startingF = true;
            }else if(S[i] == '0' and startingF){
                startingF = false;
                startingP = i;
                onK++;
            }else if(i == S.length()){
                startingP = i;
            }
            if(onK == blockTo){
                break;
            }
        }
        // cout << "Starting at:" << startingP << endl;
        
        bool found = false;
        ll start,end;
        for(ll i=startingP;i<N;i++){
            if(S[i] == '1' and !found){
                start = i;
                S[i] = '0';
                found = true;
            }else if(S[i] == '1' and found){
                S[i] = '0';
            }
            else if(S[i] == '0' and found){
                end = i;
                break;
            }else{
                end = N;
            }
            //cout << i <<'|' << S.length()-1 << endl;
        }
        // cout << "start block at:" << start << endl;
        // cout << "end block at:" << end << endl;
        // cout << "block length:" << end-start << endl;

        for(ll i=0;i<end-start;i++){
            S[startingP] = '1';
            startingP++;
        }
        
        for(auto l:S){
            cout << l;
        }



        return;
    };
    solve();
}