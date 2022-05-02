#include <bits/stdc++.h>
using namespace std;

typedef map<string, int>::iterator it_map;

void ejercicio1(){
    string instruccion;
    getline(cin, instruccion);

    for(int i = 0; i < instruccion.size(); i++){
        cout << instruccion[i] << ' ';
    }
}

void ejercicio2(){
    string cadena = "";
    string entrada;
    while(cin>>entrada){
        cadena += entrada;
    }
    for(int i = 0; i < cadena.size(); i++){
        cout << cadena[i] << ' ';
    }
}


string codificador(string texto, int desp){
    for(int i = 0; i < texto.size(); i++){
        int aux = texto[i];
        if(aux + desp > 122){
            aux = ((aux  + desp) - 122) + 96;
        }
        else{
            aux = aux + desp;
        }
        if(texto[i] != ' '){
            texto[i] = aux;
        }
    }
    return texto;
}

string decodificador(string texto, int desp){
    for(int i = 0; i < texto.size(); i++){
        int aux = texto[i];
        if(aux - desp < 97){
            aux = 122 - (96 - (aux - desp));
        }
        else{
            aux = aux - desp;
        }
        if(texto[i] != ' '){
            texto[i] = aux;
        }
    }
    return texto;
}

void ejercicio3(){
    // codificador
    string texto = "hola como estas";
    int desp = 1;
    string text_codificado = codificador(texto, desp);
    cout << "Texto Codificado: " << text_codificado << '\n';
    
    // decodificador
    string text_decodificado = decodificador(text_codificado, desp);
    cout << "Texto Decodificado: " << text_decodificado << '\n';
}

void ejercicio4(){
    map<string,int> mp = {
        {"+",1},
        {"-",1},
        {"*",1},
        {"/",1}, 
    };

    string texto; cin>>texto;
    it_map i = mp.find(texto);
    if(i != mp.end()){
        cout << "Es un caracter especial [ " << texto << " ]" <<'\n';
    }
    else if(texto[0] >= 48 and texto[0] <= 57)
        cout << "Es un numero [ " << texto << " ]" <<'\n';

    else cout << "Es una palabra [ " << texto << " ]" <<'\n';
    
}


int main(){
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    //ejercicio4();

    return 0;
}