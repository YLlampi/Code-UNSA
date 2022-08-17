/*

Almacenar todos los datos en un mapa
como en el mapa no se aceptan valores repetidos
ya tenemos solo valores unicos.
luego pasamos a otro vector.
y tenemos una nueva coleccion sin valores repetidos

tiempo de complejidad: O(nlogn)

*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> coleccion{1,1,6,6,8,4,2,5,7,8,8,4};

    map<int,int> mp;

    for(int i = 0; i < coleccion.size(); i++){
        mp[coleccion[i]]++;
    }

    vector<int> newColeccion;

    for(auto& i : mp){
        newColeccion.push_back(i.first);
    }

    for(auto& i : newColeccion){
        cout << i << ' ';
    }
    
    return 0;
}