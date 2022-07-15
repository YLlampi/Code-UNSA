#include <bits/stdc++.h>
using namespace std;

class Nodo;
class Hash;

class BufferManager{
private:
    int cantPaginas;
    vector<int> data_files;
        
public:
    //BufferManager() {

    //}

    BufferManager(int cantPaginas, vector<int>& data_files) : cantPaginas{cantPaginas}{
        this->data_files = data_files;
        metodo_clock();
    }

    void imprimir(vector<string>& vect){
        for (int i = 0; i < vect.size(); i++){
            if (i != vect.size() - 1)
                cout << vect[i] << ' ';
            else
                cout << vect[i];
        }
        cout << '\n';
    }

    void metodo_clock(){
        int contFallos = 0;
        int arm = 0;
        vector<string> pagAlojadas;
        vector<string> paginas;
        bool useBit[cantPaginas];

        string input2;
        
        //while(cin>>input2){
            //paginas.push_back(input2);
        //}

        // valores aleatorios
        //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
        int index = 7 + rand() % 20; // Numeros de paginas a Consultar (pueden ser Repetidos)
        for(int i = 0; i < index; i++){
            int index_a = 0 + rand() % (this->data_files.size()-1 + 1 - 0);
            //paginas[i] = to_string(this->data_files[index]);
            paginas.push_back(to_string(this->data_files[index_a]));
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
};


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
            cout << this->id << "-";
            for(auto i : val){
                cout << i << "\t";
            }
        }

};

class Hash{
    int BUCKET;

    list<Nodo*> *table;
    vector<string> vals;

    vector<int> all_data;

public:
    Hash(int V, vector<string>& colums);

    void insertItem(Nodo* x);

    void deleteItem(int key);

    int hashFunction(int x){
        return (x % BUCKET);
    }

    vector<int>& getData() {
        return this->all_data;
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
    this->all_data.push_back(key->getId());
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
        cout << i << ": ";
        for(auto x : table[i]){
            x->toString();
            //this->all_data.push_back(x->getId());
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



class Controller{
private:
    string opcion;
    int cont = 0;
    vector<string> colums;
    string valColumn;

    const int cantPaginas = 3;

    BufferManager* bm;

    int contador_id;
public:
    Controller(){
        this->contador_id = 0;
    }

    void insertarDato(Hash& h, vector<string>& colums){
        vector<string> pas(colums.size());
        for(int i = 0; i < colums.size(); i++){
            cout << colums[i] << ": "; cin>>pas[i];
        }
        //Nodo* p = new Nodo(stoi(pas[0]),pas);
        Nodo* p = new Nodo(this->contador_id++, pas);
        h.insertItem(p);
    }

    void menu(){
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

        // MENU 
        int opcion__menu;
        do{
            cout << "\tMENU" << '\n';
            cout << "1. Insertar Valor" << '\n';
            cout << "2. Eliminar Dato" << '\n';
            cout << "3. Mostrar Tabla" << '\n';
            cout << "4. Buffer Manager(Consultas)" << '\n';
            cout << "5. Salir" << '\n';
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
            else if(opcion__menu == 4){
                bm = new BufferManager(this->cantPaginas, h.getData());
            }

        }while(opcion__menu != 5);
    }
};


int main(){
    srand(time(NULL));
    Controller c1;

    c1.menu();



    /*
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

    // MENU 
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
    */
    
    return 0;
}
