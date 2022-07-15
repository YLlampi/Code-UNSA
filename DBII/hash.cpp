#include <bits/stdc++.h>
using namespace std;

template <class T>
class Lista;

template <class T>
class HashTable;


// Nodo para la lista doblemente enlazada
template <class T>
class Nodo{
    private:
        T info;
        string info2;
        //string apellido;
        vector<T> colum;
        Nodo<T>* nextIzq;
        Nodo<T>* nextDer;
        /*
        * Cantidad inicial de datos de cada nodo
        *
        */
    public:
        Nodo(int sizeNodo){
            this->nextDer = nullptr;
            this->nextIzq = nullptr;
        }
        friend class Lista<T>;
        friend class HashTable<T>;
};

// Lista Doblemente Enlazada
// Utilizada para la tabla Hash
template <class T>
class Lista{
    private:
        Nodo<T>* primero;
        Nodo<T>* ultimo;
        /*
        * 
        */

    public:
        Lista(){
            this->primero = nullptr;
            this->ultimo = nullptr;
        }

        void insertarInicio(T dato, string dato2){
            Nodo<T>* apunt = new Nodo<T>();
            apunt->info = dato;
            apunt->info2 = dato2;
            apunt->nextDer = this->primero;
            if(this->primero)
                this->primero->nextIzq = apunt;
            else
            this->ultimo = apunt;
            this->primero = apunt;
        }

        void insertarFinal(T dato, string dato2){
            Nodo<T>* apunt = new Nodo<T>();
            apunt->info = dato;
            apunt->info2 = dato2;
            apunt->nextIzq = this->ultimo;
            if(this->ultimo)
                this->ultimo->nextDer = apunt;
            else
                this->primero = apunt;
            this->ultimo = apunt;
        }

        int eliminarPrimero(){
            Nodo<T>* apunt;
            int resp = 1;
            if(this->primero){
                apunt = this->primero;
                if(apunt->nextDer){
                    this->primero = apunt->nextDer;
                    this->primero->nextIzq = nullptr;
                }
                else{
                    this->primero = nullptr;
                    this->ultimo = nullptr;
                }
                delete (apunt);
            }
            else resp = 0;
            return resp;
        }

        int eliminarUltimo(){
            Nodo<T>* apunt;
            int resp = 1;
            if(this->ultimo){
                apunt = this->ultimo;
                if(apunt->nextIzq){
                    this->ultimo = apunt->nextIzq;
                    this->ultimo->nextDer = nullptr;
                }
                else{
                    this->primero = nullptr;
                    this->ultimo = nullptr;
                }
                delete (apunt);
            }
            else resp = 0;
            return resp;
        }

        int eliminarNodo(T dato){
            Nodo<T>* apunt1, *apunt2, *apunt3;
            int resp = 1;
            if(this->primero){
                apunt1 = this->primero;
                while((apunt1 != nullptr) and (apunt1->info != dato)){
                    apunt1 = apunt1->nextDer;
                }
                if(apunt1 == nullptr){
                    resp = 0;
                }
                else{
                    if(this->primero == this->ultimo){
                        this->primero = nullptr;
                        this->ultimo = nullptr;
                    }
                    else
                        if(apunt1 == this->primero){
                            this->primero = apunt1->nextDer;
                            this->primero->nextIzq = nullptr;
                        }
                        else
                            if(apunt1 == this->ultimo){
                                this->ultimo = apunt1->nextIzq;
                                this->ultimo->nextDer = nullptr;
                            }
                            else{
                                apunt2 = apunt1->nextIzq;
                                apunt3 = apunt1->nextDer;
                                apunt2->nextDer = apunt3;
                                apunt3->nextIzq = apunt2;
                            }
                    delete (apunt1);
                }
            }
            else resp = -1;
            return resp;
        }

        Nodo<T>* busca(T dato, Nodo<T>* apunt){
            if(apunt)
                if(apunt->info == dato)
                    return apunt;
                else
                    return busca(dato, apunt->nextDer);
            else
                return nullptr;
        }

        void imprimir() const {
            Nodo<T>* apunt = this->primero;
            while(apunt){
                cout << apunt->info << " |-| " << apunt->info2 << '\n';;
                apunt = apunt->nextDer;
            }
        }

        // Retorna el tamaño de la lista
        int size() const{
            int cont{};
            Nodo<T>* apunt = this->primero;
            while(apunt){
                cont++;
                apunt = apunt->nextDer;
            }
            return cont;
        }


        // Opcional - Iterador para el recorrido y algunas operaciones en la lista
        class Iterator{
        private:
            const Nodo<T> *actual;
        public:
            Iterator() : actual{nullptr} {}

            Iterator(const Nodo<T> *other){
                this->actual = other;
            }

            Iterator &operator++(){
                if(this->actual)
                    this->actual = this->actual->nextDer;
                return *this;
            }
            Iterator operator++(int){
                Iterator iterator = *this;
                ++*this;
                return iterator;
            }
            bool operator!=(const Iterator &other){
                return this->actual != other.actual;
            }
            int operator*(){
                return this->actual->info;
            }
        };

        Iterator begin(){
            return Iterator(this->primero);
        }

        Iterator end(){
            return Iterator();
        }
        friend class HashTable<T>;
};

template <class T>
class HashTable{
    private:
        const static int hashGroups = 20;
        // Lista doblemente enlazada - Implementada al principio del codigo
        Lista<int> table[hashGroups]; // Creación de la tabla (tabla de listas)
    public:
        // Verificamos se esta vacia la tabla Hash
        bool isEmpty(){
            int sum{};
            for(int i{}; i < hashGroups; i++){
                sum += table[i].size();
            }
            if(!sum) return true;
            return false;
        }

        // Devuelve la funcion Hash - (Asignación)
        // Hacemos uso del Hash de Divicion - (Resto de la Division)
        /*
            Dado un diccionario D, se fija un número m >= |D| (m mayor o igual al tamaño
            del diccionario) y que sea primo no cercano a potencia de 2 o de 10. Siendo k la clave a buscar
            y h(k) la función hash, se tiene h(k)=k%m (Resto de la división k/m).
        */
        int hashFunction(int key){
            return key % hashGroups;
        }

        // Inserta elementos 
        void insertItem(int key, string value){
            int hashValue = hashFunction(key); // Llama a la funcion hash para la asignacion
            Nodo<T>* inicio = table[hashValue].primero; // Determina la lista en la que pertenece
            bool keyExists = false;
            
            if(inicio){ // Si existe algun elemento lo agrega al final
                keyExists = true;
                table[hashValue].insertarFinal(key,value);
                //cout << "[INFO] Insertado correctamente." << '\n';
            }

            if(!keyExists){ // Si no existe algun elemento lo agrega al inicio
                //cout << "[INFO] No existe datos en esta clave." << '\n';
                table[hashValue].insertarInicio(key,value);
            }
        }

        // Eliminar datos de una determinada clave
        void removeItem(int key){
            int hashValue = hashFunction(key);
            Nodo<T>* inicio = table[hashValue].primero;
            bool keyExists = false;
            
            while(inicio){ // Si existe elementos en dicha clave, los elimina
                keyExists = true;
                table[hashValue].eliminarNodo(inicio->info);
                inicio = inicio->nextDer;
            }


            if(!keyExists){ // Si no existe, no hay nadad que eliminar
                cout << "[ERROR] Clave no encontrada, no eliminado." << '\n';
            }else{
                cout << "[INFO] Clave Eliminada." << '\n'; // Mensaje
            }
        }

        // Impresion de la tabla hash
        void printTable(){
            for(int i = 0; i < hashGroups; i++){
                if(table[i].size() == 0) continue;
                Nodo<T>* apunt = table[i].primero;
                cout << "------------------------- [INFO] Slot: " << i + 1 << " -------------------------\n";
                
                while(apunt){
                    cout << apunt->info2 << ' ';
                    apunt = apunt->nextDer;
                }
                
                cout << '\n';
                cout << '\n';
            }
        }

        // Buscamos determinado elemento por la clave
        // Imprime la lista(si hay colisiones)
        void search(int key, string cadena = "") {
            int hashValue = hashFunction(key);
            Nodo<T>* inicio = table[hashValue].primero;

            if(cadena == ""){
                while(inicio){
                    cout << inicio->info2 << ' ';
                    inicio = inicio->nextDer;
                }
            }
            else{
                bool band = false;
                while(inicio){
                    if(cadena == inicio->info2){
                        band = true;
                    }
                }
                band = false;
                if(band) cout << "Elemento encontrado" << '\n';
                else cout << "Elemento no encontrado" << '\n';
            }
        }
};

void menu(HashTable<int>& myTabla) {
    int opcion;
    do{
        cout << "Menu" << '\n';
        cout << "1. Insertar" << '\n';
        cout << "2. Mostrar Tabla(bloque)" << '\n';
        cout << "3. Mostrar Tabla(Completo)" << '\n';
        cout << "4. Modificar" << '\n';
        //cout << "5. Eliminar" << '\n';
        cout << "6. Salir" << '\n';
        cout << "Seleccione una opcion: "; cin>>opcion;

        int id;
        string cadena;

        switch(opcion){
            case 1:
                cout << "Id del Usuario: "; cin>>id;
                cout << "Nombre del Usuario: "; cin>>cadena;
                myTabla.insertItem(id, cadena);
                break;
            case 2:
                cout << "Bloque que desea imprimir: "; cin>>id;
                myTabla.search(id);
                break;
            case 3:
                cout << "Tabla Completa" << '\n';
                myTabla.printTable();
                break;
            case 4:
                cout << "Id a modificar"; cin>>id;
                cout << "Nombre del Usuario: "; cin>>cadena;
                myTabla.search(id, cadena);
                break;
            case 6:
                break;
        }
    }while(opcion != 6);
}

int main(){

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    HashTable<int> myTabla;

    menu(myTabla);

    /*
    string cadena = "";
    int id;

    while(cin>>id>>cadena){
        myTabla.insertItem(id, cadena);
    }
    cout << '\n';

    // Imprimimos la tabla original
    myTabla.printTable();
    */

    return 0;
}