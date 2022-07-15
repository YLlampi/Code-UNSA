#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n,t,max,i;

    while(cin>>m>>n>>t){
        if(m>n){
            int temp = m; m = n; n = temp;
        }

        max = t/m;
        
        int beer_time = t-max*m;
        if(beer_time == 0){
            cout << max << '\n';
            continue;
        }
        
        for(i = 1; i <= t/n; i++){
            int tMax = (t-n*i)/m+i;
            int temp_beer_time = t-((tMax-i)*m+i*n);
            if(temp_beer_time >= 0 and temp_beer_time < beer_time){
                max=tMax;
                beer_time=temp_beer_time;
            }
            if(temp_beer_time==0)
                break;
        }
        cout << max << '\n';
    }
    return 0;
}