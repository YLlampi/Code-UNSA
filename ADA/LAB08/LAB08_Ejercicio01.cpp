#include <bits/stdc++.h>
using namespace std;

void solve(int m, int n, int t){
    int i, first, second;
    int time[1000];
    int burgers[1000];

    time[0] = 0;
    burgers[0] = 0;

    for (i = 1; i <= t; i++){
        time[i] = 0;
        burgers[i] = 0;

        if (i >= m)
            first = time[i - m] + m;
        else
            first = -1;
        if (i >= n)
            second = time[i - n] + n;
        else
            second = -1;

        if (first > time[i] && first > second){
            time[i] = first;
            burgers[i] = burgers[i - m] + 1;
        }
        else if (second > time[i] && second > first){
            time[i] = second;
            burgers[i] = burgers[i - n] + 1;
        }
        else if (first > time[i] && first == second){
            time[i] = first;
            burgers[i] = max(burgers[i - m], burgers[i - n]) + 1;
        }
    }

    if (time[t] == t) cout << burgers[t] << '\n';
    else cout << burgers[t] << t - time[t] << '\n';
}

int main(){
    int m, n, t;
    
    while (cin>>n>>n>>t){
        solve(m, n, t);
    }
        
    
    
    return 0;
}