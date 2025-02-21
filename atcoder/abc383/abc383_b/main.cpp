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
    int H,W,D;
    cin >> H >> W >> D;
    vector<vector<int>> grid(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            char cell;
            cin >> cell; 
            if(cell =='#'){
                grid[i][j] = 1;
            }
        }
    }
    //functions

    auto solve = [&]()->void{
        //solve code
        auto getFloorsInReach = [&](int i, int j)->int{
            int floorCount = 0;
            if(grid[i][j] == 1) return -1;//cannot evaluate a desk;
            for (int dx = -D; dx <= D; dx++){
                for (int dy = -D; dy <= D; dy++){
                    if (abs(dx) + abs(dy) <= D){
                        int newI = i + dx;
                        int newJ = j + dy;
                        if (newI >= 0 && newI < H && newJ >= 0 && newJ < W) {
                            if(grid[newI][newJ] == 0) floorCount++;
                        }
                    }
                }
            }
            return floorCount;
        };

        auto calcManhattanDistance = [&](int i1, int j1,int i2, int j2) -> int{
            return abs(i1-i2) + abs(j1-j2);
        };
        
        vector<int> max;
        for(int x=0; x<H;x++){
            for(int y=0;y<W;y++){
            vector<int> humidReach; 
            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){ 
                    int ReachableFloor = getFloorsInReach(i,j);
                    if(ReachableFloor == -1){//desk
                        cout <<'.' << ' ';
                    }else{
                        cout << ReachableFloor << ' ';
                        humidReach.push_back(ReachableFloor);
                    }
                }
                cout << endl;
            }   
            int max1 = -1;
            int max2 = -1;
            for(int n:humidReach){
                if (n > max1) {
                    max2 = max1;
                    max1 = n;
                } else if (n > max2) {
                    max2 = n;
                }
            }
            max.push_back(max1+max2);
            }
        }
        int m =-1;
        for(auto mi:max){
            if (m > mi){
                m = mi;
            }
        }
        cout << m;

        return;
    };
    solve();
}