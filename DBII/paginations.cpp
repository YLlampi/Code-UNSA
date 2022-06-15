#include <bits/stdc++.h>
using namespace std;

int cantPaginas;

void imprimir(vector<string> vect){
    for (int i = 0; i < vect.size(); i++){
        if (i != vect.size() - 1)
            cout << vect[i] << ' ';
        else
            cout << vect[i];
    }
    cout << '\n';
}

void metodo_lru(){
    int contFallos = 0;
    vector<string> pagAlojadas;
    vector<string> paginas;
    
    string input2;
    
    while(cin>>input2){
        paginas.push_back(input2);
    }
    
    //paginas.resize(paginas.size());

    cout << "-----------------LRU-----------------" << '\n';
    cout << "-------------------------------------" << '\n';
    cout << "Pag.   Cont. de Frames" << '\n';
    cout << "----   ---------------" << '\n';
    for (int i = 0; i < paginas.size(); i++){
        if (pagAlojadas.size() < cantPaginas and
            find(pagAlojadas.begin(), pagAlojadas.end(), paginas[i]) == pagAlojadas.end()){
            pagAlojadas.push_back(paginas[i]); // añadir pagina
            contFallos++;
            cout << paginas[i] << " M    ";
            imprimir(pagAlojadas);
        }
        // si la pagina ya existe
        else if (find(pagAlojadas.begin(), pagAlojadas.end(), paginas[i]) != pagAlojadas.end()){
            cout << paginas[i] << "      ";
            imprimir(pagAlojadas);
        }

        // pagina a reemplazar(nuevo)
        else{
            int k;
            int maxIndex = INT_MAX;
            int remplazarPag = 0;
            int flag = 0;
            for (int j = 0; j < pagAlojadas.size(); j++){
                flag = 0;
                for (k = i - 1; k >= 0; k--){
                    if (paginas[k] != pagAlojadas[j])
                        continue;
                    else{
                        flag = 1;
                        if (k < maxIndex){
                            maxIndex = k;
                            remplazarPag = j;
                        }
                        break;
                    }
                }

                if (flag == 0){
                    pagAlojadas[j] = paginas[i];
                    contFallos++;
                    cout << paginas[i] << " M    ";
                    imprimir(pagAlojadas);
                    break;
                }
            }
            if (flag == 1){
                pagAlojadas[remplazarPag] = paginas[i];
                contFallos++;
                cout << paginas[i] << " M    ";
                imprimir(pagAlojadas);
            }
        }
    }

    cout << "-------------------------------------" << '\n';
    cout << "Numero de fallos de pagina = " << contFallos << '\n';
}

void metodo_clock(){
    int contFallos = 0;
    int arm = 0;
    vector<string> pagAlojadas;
    vector<string> paginas;
    bool useBit[cantPaginas];

    string input2;
    
    while(cin>>input2){
        paginas.push_back(input2);
    }

    cout << "----------------CLOCK----------------" << '\n';
    cout << "-------------------------------------" << '\n';
    cout << "Pag.   Cont. de Frames" << '\n';
    cout << "----   ---------------" << '\n';
    for (int i = 0; i < paginas.size(); i++){
        auto it = find(pagAlojadas.begin(), pagAlojadas.end(), paginas[i]);
        // si no esta completo los frames y se tiene una nueva pagina
        if (pagAlojadas.size() < cantPaginas &&
            find(pagAlojadas.begin(), pagAlojadas.end(), paginas[i]) == pagAlojadas.end()){
            pagAlojadas.push_back(paginas[i]); // agregados pagina
            useBit[i] = true;
            contFallos++;
            cout << paginas[i] << " M    ";
            imprimir(pagAlojadas);
        }
        // La pagina existe en el vector

        else if (it != pagAlojadas.end()){
            useBit[it - pagAlojadas.begin()] = true;
            cout << paginas[i] << "      ";
            imprimir(pagAlojadas);
        }

        // nueva pagina - vector lleno (caso de fallo)
        else{
            int allPassed = 0; // Bandera para el caso de que todas las páginas sean verdaderas
            while (allPassed == 0){
                for (int j = 0; j < pagAlojadas.size(); j++){
                    if (useBit[arm] == true){
                        useBit[arm] = false;
                        arm++;
                        if (arm == pagAlojadas.size()) // Reiniciar reloj
                            arm = 0;
                    }
                    else{
                        pagAlojadas[arm] = paginas[i];
                        useBit[arm] = true;
                        arm++;
                        if (arm == pagAlojadas.size()) // Reiniciar reloj
                            arm = 0;
                        allPassed = 1;
                        break;
                    }
                }
            }

            contFallos++;
            cout << paginas[i] << " M    ";
            imprimir(pagAlojadas);
        }
    }

    cout << "-------------------------------------" << '\n';
    cout << "Numero de fallos de pagina = " << contFallos << '\n';
}

int find_vector(vector<string> vec, string val){
    int cont = 0;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == val)
            return cont;
        cont++;
    }
    return -1;
}

void metodo_mru(){
    string input;
    vector<string> paginas;
    vector<string> proceso;
    int contFallos = 0;

    for(int i = 0; i < cantPaginas; i++) proceso.push_back(" "); // inicializa el proceso vacio

    while(cin>>input){
        paginas.push_back(input);
    }

    cout << "-----------------MRU-----------------" << '\n';
    cout << "-------------------------------------" << '\n';
    cout << "Pag.   Cont. de Frames" << '\n';
    cout << "----   ---------------" << '\n';

    int posPagina, posVacio, posInsercion;

    for(int i = 0; i < paginas.size(); i++){
        posPagina = find_vector(proceso, paginas[i]); // busca la posicion de la entrada actual en el proceso

        // IMPRESION PAG. ------------------
        cout << paginas[i] << " ";

        if ( posPagina >= 0) // si la encuentra
            cout << "    " << "\t";
        else{ // si no la encuentra, es Missed
            cout << "M " << "\t";
            contFallos++;
        }

        // IMPRESION CONT. DE FRAMES --------
        if ( posPagina < 0){ // si no la encuentra en el proceso
            posVacio = find_vector(proceso, " "); // busca si hay un espacio vacio en el proceso para insertar una pagina

            if(posVacio >= 0){ // si se ha encontrado una posicion vacia
            
                proceso[posVacio] = paginas[i];
            }
            else{ // si no hay espacios vacios
            
                // MRU !
                posInsercion = find_vector(proceso, paginas[i-1]); // busca posicion donde insertar en el proceso
                proceso[posInsercion] = paginas[i];
            }
        }
        for(int i = 0; i < proceso.size(); i++)
            cout << proceso[i] << " ";
        cout << endl;
    }

    cout << "-------------------------------------" << '\n';
    cout << "Numero de fallos de pagina = " << contFallos << '\n';
}

int main(){    
    cin >> cantPaginas;
    string method;
    cin >> method;

    
    if (method == "LRU")
        metodo_lru();
    else if (method == "MRU")
        metodo_mru();
    else if (method == "CLOCK")
        metodo_clock();
    
    return 0;
}

