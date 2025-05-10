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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    vector<int> degree(N, 0);
    for(int i=0;i<M;i++){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        degree[A[i]]++;
        degree[B[i]]++;
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        if (M != N) {
            cout << "No";
            return;
        }

        bool found = false;
        dsu G(N);
        for(int i=0;i<M;i++){
            if(G.same(A[i],B[i]) && found == false){
                found = true;
            } else if(G.same(A[i],B[i]) && found == true){
                cout << "No";
                return;
            }
            G.merge(A[i],B[i]);
        }

        bool connected = G.size(0) == N;

        for(int i = 0; i < N; ++i) {
            if(degree[i] != 2){
                cout << "No";
                return;
            }
        }

        if(found && connected){
            cout << "Yes";
        } else{
            cout << "No";
        }

        return;
    };
    solve();
}