#include <bits/stdc++.h>
using namespace std;

void ejercicio1(){
    int estado;
    char simbolo;
    string cadena; cin>>cadena;
    estado = 1;
    simbolo = cadena[0];
    int i = 0;
    while(simbolo){
        switch(estado){
            case 1:
                if(simbolo >= 48 and simbolo <= 57) estado = 2;
                else if((simbolo >= 65 and simbolo <= 90) or (simbolo >=97 and simbolo <= 122)){
                    estado = 3;
                }
                else{
                    //cout << "Salir a rutina de error 1" << '\n';
                    estado = 2;
                }
                break;
            case 2:
                //cout << "Salir a rutina de error 2" << '\n';
                break;
            case 3:
                if((simbolo >= 65 and simbolo <= 90) or (simbolo >=97 and simbolo <= 122)){
                    estado = 3;
                }
                else if(simbolo >= 48 and simbolo <= 57) estado = 3;
                else{
                    //cout << "Salir a rutina de error 3" << '\n';
                    estado = 2;
                }
                break;
        }
        if(estado == 2) break;
        i++;
        simbolo = cadena[i];
    }
    if(estado != 3) cout << "Incorrecto" << '\n';
    else cout << "Correcto" << '\n';
}

void ejercicio2(){
    string cadena; cin>>cadena;

    enum tabla_entrada{
        error = -1,
        aceptar,
        digito = 0,
        letra,
        fdc
    };

    int tabla[3][3] = {
        {2, 3, error},
        {error, error, error},
        {3, 3, aceptar}
    };

    int estado = 1;
    int entrada;

    int i = 0;
    char simbolo;

    do{
        simbolo = cadena[i++];
        if(simbolo >= 48 and simbolo <= 57) {
            entrada = digito;
            estado = 2;
            cout << "Error1" << '\n';
            break;
        }
        else if((simbolo >= 65 and simbolo <= 90) or (simbolo >=97 and simbolo <= 122)){
            entrada = letra;
            estado = 3;
        }
        else if(!simbolo) {
            entrada = fdc;
        }
        else{
            cout << "Error2" << '\n';
            break;
        }

        estado = tabla[estado-1][entrada];

        if(estado == error){
            cout << "Error3" << '\n';
            break;
        }
        else if(estado == aceptar){
            cout << "Correcto" << '\n';
        }
    }while(estado != aceptar);

}


int main(){
    //ejercicio1();
    //ejercicio2();

    return 0;
}