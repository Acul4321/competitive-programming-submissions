#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int powN(int n){
    return pow(3,n);
}

int main() {
    //input code
    int M;
    cin >> M;

    auto solve = [&]()->void{
        //solve code
        vector<int> pow;
        int sum = 0;
        while(sum!= M){
            int i = 0;
            while(sum + powN(i)<=M){
                i++;
                //cout << sum << " + " << powN(i) << "|";
            }
            sum = sum + powN(i-1);
            pow.push_back(i-1);
        }
        cout << pow.size() << endl;
        for(auto &i:pow){
            cout << i << " ";
        }

        return;
    };
    solve();
}