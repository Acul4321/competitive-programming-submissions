#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    //input code
    char AB;
    char AC;
    char BC;
    cin >> AB >> AC >> BC;

    auto solve = [&]()->void{
        //solve code
        if((AB == '<' and AC == '>') or (AB == '>' and AC == '<')){
            cout << 'A';
        }else if ((AB == '<' and AC == '<' and BC == '<') or (AB == '>' and AC == '>' and BC == '>')){
            cout << 'B';
        }else {
            cout << 'C';
        }

        return;
    };
    solve();
}