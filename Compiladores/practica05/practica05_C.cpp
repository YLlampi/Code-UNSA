#include <bits/stdc++.h>
using namespace std;

map<string,int> mp = {{"+",1},{"-",2},{"*",3},{"/",4}};

int main(){
    freopen("input.txt", "r", stdin);
    
    string as;
    stack<int> pila;
    int operacion;
    while(cin>>as){
        if (mp.find(as) != mp.end()) {
            operacion = mp[as];
        } else {
            int num = stoi(as);
            pila.push(num);
            continue;
        }
        int number1 = pila.top();
        pila.pop();
        int number2 = pila.top();
        pila.pop();
        int res = 0;
        if(operacion == 1){
            pila.push(number1 + number2);
        } else if(operacion == 2){
            pila.push(number1 - number2);
        } else if(operacion == 3){
            pila.push(number1 * number2);
        } else if(operacion == 4){
            pila.push(number1 / number2);
        }

    }
    cout << pila.top() << '\n';

    return 0;
}