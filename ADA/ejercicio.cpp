#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long solve1 = 0;
    long long solve2 = 0;
    for(int n = 0; n <= 1000; n++){
        solve1 = n * n;
        solve2 = solve1 - 3*n + 2;
        cout << n << " - " << solve1 << ' ' << solve2 << '\n';
    }

    return 0;
}