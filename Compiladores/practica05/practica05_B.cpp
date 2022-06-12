#include <bits/stdc++.h>
using namespace std;

map<string,int> mp = {{"+",1},{"-",2},{"*",3},{"/",4}};

int main(){
    vector<string> arr = {"10", "1", "2", "+", "2", "*", "+"};
    stack<int> pila;
    int operacion;

    for(int i = 0; i < arr.size(); i++){
        if (mp.find(arr[i]) != mp.end()) {
            operacion = mp[arr[i]];
        } else {
            int num = stoi(arr[i]);
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