#include <bits/stdc++.h>
using namespace std;


class Nodo{
    private:
        int id;
        string nombre;
        vector<string> val;
    public:
        Nodo(int id, vector<string>& vals) : id(id){
            this->val = vals;
        }

        int getId() const {
            return this->id;
        }

        string getNombre() const {
            return this->nombre;
        }
        void setNombre(string nombre){
            this->nombre = nombre;
        }

        void toString() const {
            for(auto i : val){
                cout << i << "\t";
            }
        }

};

class Hash{
    int BUCKET;

    list<Nodo*> *table;
    vector<string> vals;

public:
    Hash(int V, vector<string>& colums);

    void insertItem(Nodo* x);

    void deleteItem(int key);

    int hashFunction(int x){
        return (x % BUCKET);
    }

    void displayHash();
};

Hash::Hash(int b, vector<string>& colums){
    this->BUCKET = b;
    table = new list<Nodo*>[BUCKET];
    this->vals = colums;
}

void Hash::insertItem(Nodo* key){
    int index = hashFunction(key->getId());
    table[index].push_back(key);
}

void Hash::deleteItem(int key){
    int index = hashFunction(key);


    list<Nodo*>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++){
        if ((*i)->getId() == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void Hash::displayHash(){
    for(auto i : vals){
        cout << i << "\t";
    }
    cout << '\n';
    for(int i = 0; i < BUCKET; i++){
        for(auto x : table[i]){
            x->toString();
        }
        cout << '\n';
    }
    /*for (int i = 0; i < BUCKET; i++){
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x->getId() << "| ";
        cout << endl;
    }
    */
}

void insertarDato(Hash& h, vector<string>& colums){
    vector<string> pas(colums.size());
    for(int i = 0; i < colums.size(); i++){
        cout << colums[i] << ": "; cin>>pas[i];
    }
    Nodo* p = new Nodo(stoi(pas[0]),pas);
    h.insertItem(p);
}

int main(){
    string opcion;
    int cont = 0;
    vector<string> colums;
    string valColumn;

    do{
        cout << "Desea agregar un campo columna? SI/NO: ";cin>>opcion;
        if(opcion == "SI" or opcion == "si"){
            cont++;
            cout << "Nombre de la Columna: "; cin>>valColumn;
            colums.push_back(valColumn); 

        }

    }while(opcion == "SI" or opcion == "si");

    const int numsBuck = 10;

    Hash h(numsBuck, colums);

    /* MENU */
    int opcion__menu;
    do{
        cout << "\tMENU" << '\n';
        cout << "1. Insertar Valor" << '\n';
        cout << "2. Eliminar Dato" << '\n';
        cout << "3. Mostrar Tabla" << '\n';
        cout << "4. Salir" << '\n';
        cout << "Seleccione una opcion: "; cin>>opcion__menu;

        if(opcion__menu == 1){
            insertarDato(h, colums);
        }
        else if(opcion__menu == 2){
            int id__eliminar;
            cout << "Id a Eliminar: "; cin>>id__eliminar;
            h.deleteItem(id__eliminar);
        }
        else if(opcion__menu == 3){
            h.displayHash();
        }

    }while(opcion__menu != 4);
    
    return 0;
}
