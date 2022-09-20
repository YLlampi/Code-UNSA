#include <iostream>
#include <math.h>
#include <list>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
//#include "adaptarSistemasOp.h"

#ifndef __adaptarSistemasOp_H__
#define __adaptarSistemasOp_H__

#ifdef __linux__
#define LIMPIAR "clear"
#define MOVER "mv"
#endif // __linux__
 
#ifdef __MINGW32__
#define LIMPIAR "cls"
#define MOVER "move"
#endif // __MINGW32__
 
#ifdef __APPLE__
#define LIMPIAR "clear"
#define MOVER "mv"
#endif // __APPLE__

#endif // __adaptarSistemasOp_H__

using namespace std;

void menu();
bool ConsultaPrimo(int num);
int sigPrimo(int val);
int fd(string key, int n);

template<class T>
class Hash;

template <class T>
class Table;

template <class T>
class Database;

template <class T>
class Transaction{
public:
    Transaction() {}
    ~Transaction() {}
    void startTransaction(Hash<T>&);
};

template <class T>
void Transaction<T>::startTransaction(Hash<T> &h){
    cout << "Iniciando transaccion" << endl;
    int option;
    vector<string> transactionOperations;
    string dbCopy = "databaseCopy";
    string dbName = "";
    bool backupCreado = false;
    do {
        system(LIMPIAR);
        cout << "LISTA DE OPERACIONES" << endl;
        for (int i = 0; i < transactionOperations.size(); i++) {
            cout << i+1 << ". " << transactionOperations[i] << endl;
        }
        cout << "\n1. Agregar operacion a la transaccion" << endl;
        cout << "2. Hacer commit" << endl;
        cout << "3. Hacer rollback" << endl;
        cout << "Ingrese una opcion o deje en blanco para salir: ";
        cin.ignore();
        getline(cin, option);
        switch (option) {
            case 1: {
                system(LIMPIAR);
                cout << "Ingrese que operacion desea poner en la transaccion" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Actualizar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Consultar" << endl;

                cout << "Ingrese una opcion o deje en blanco para salir: ";
                cin.ignore();
                getline(cin, option);
                switch (option) {
                    case 1: {
                        transactionOperations.push_back("Insert");
                        h.insertData(dbName, dbCopy, backupCreado);
                        break;
                    }
                    case 2: {
                        transactionOperations.push_back("Update");
                        h.updateData(dbbName, dbCopy, backupCreado);
                        break;
                    }
                    case 3: {
                        transactionOperations.push_back("Delete");
                        h.deleteData(dbName, dbCopy, backupCreado);
                        break;
                    }
                    case 4: {
                        cout<<"Elija que tablas de la base de datos desee mostrar"<<endl;
                        cout<<"Base de Datos"<<endl;
                        cin>>bd;
                        cout<<"Tabla"<<endl;
                        cin>>tb;
                        h.selectfrom("*",bd,tb);
                        h.printData();
                        cout<<"Pulse una tecla para continuar"<<endl;
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 2: {
                cout << "Haciendo commit" << endl;
                system("rmdir TemporaryFiles\\" + dbCopy + " /s /q");
                transactionOperations.clear();
                break;
            }
            case 3: {
                cout << "Haciendo rollback" << endl;
                system("rmdir BasesDeDatos\\" + dbName + " /s /q");
                system("xcopy TemporaryFiles\\" + dbCopy + " " + "BasesDeDatos\\" + dbName + " /E /I /Y");
                system("ren BasesDeDatos\\" + dbCopy + " " + dbName);
                system("rmdir TemporaryFiles\\" + dbCopy + " /s /q");
                transactionOperations.clear();
                break;
            }
            default:
                break;
        }
    } while (option != '\0');
}

template<typename T>
class Table{
private:
    string name;
    list<string> *colums;
    template <typename U>
    friend class Database;
public:
    Table(){
        name="";
        colums=new list<string>[1];
    }
    Table(string t){
        name=t;
        colums=new list<string>[1];
    }
    void insert(string columna){
        colums->push_back(columna);
    }

    void selectfrom(string rows, string bd, string tb)
    {
        ifstream archivo("BasesDeDatos/"+bd+"/"+tb+".txt");
        ifstream aux;
        string _lectura((std::istreambuf_iterator<char>(archivo)),
                 std::istreambuf_iterator<char>());
        if (rows=="*")
        {
            cout<<_lectura;
        }
    }

    void insertData(string bd,string tabla){
        fstream archivo;
        archivo.open("BasesDeDatos/"+bd+"/"+tabla+".txt",ios::app);
        archivo<<endl;
        for (list<string>::iterator it = colums->begin(); it != colums->end(); ++it)
        {
            string data;
            cout<<(*it)<<": ";
            getline(cin,data);
            archivo<<data<<"\t\t";
        }
        archivo.close();
    }

    void deleteData(string bd,string tabla){
        fstream archivo,aux;
        archivo.open("BasesDeDatos/"+bd+"/"+tabla+".txt",ios::in);
        aux.open("BasesDeDatos/"+bd+"/aux"+".txt",ios::out);

        string _column,_condition,_lectura;
        cout<<"Columna ";
        getline(cin,_column);
        cout<<"Dato ";
        getline(cin,_condition);

        int eliminar,cont=1;
        for (list<string>::iterator it = colums->begin(); it != colums->end(); ++it)
        {
            archivo>>_lectura;
            aux<<_lectura<<"\t\t";
            if(_lectura==_column)
                eliminar=cont;
            cont++;
        }
        while(!archivo.eof()){
            string _ingreso="";
            bool _find=false;
            for(int i=0;i<eliminar;i++){
                archivo>>_lectura;
                if(i==eliminar-1 && _lectura==_condition){
                    _find=true;
                    _ingreso+=_lectura;
                }
                else if(i==eliminar-1){
                    _ingreso+=_lectura;
                }
                else{
                    _ingreso+=_lectura+"\t\t";
                }
            }

            getline(archivo,_lectura);
            if(_find!=true){
                aux<<endl<<_ingreso;
                aux<<_lectura;
            }       
        }

        archivo.close();
        aux.close();

        string _remove="BasesDeDatos/"+bd+"/"+tabla+".txt";
        string _rename="BasesDeDatos/"+bd+"/aux"+".txt";
        remove(_remove.c_str());                    
        rename(_rename.c_str(), _remove.c_str());
    }

    void updateData(string bd,string tabla){
        fstream archivo,aux;
        archivo.open("BasesDeDatos/"+bd+"/"+tabla+".txt",ios::in);
        aux.open("BasesDeDatos/"+bd+"/aux"+".txt",ios::out);

        string _column,_condition,_nuevo,_lectura;
        cout<<"Columna ";
        getline(cin,_column);
        cout<<"Dato a reemplazar ";
        getline(cin,_condition);
        cout<<"Dato nuevo ";
        getline(cin,_nuevo);

        int eliminar,cont=1;
        for (list<string>::iterator it = colums->begin(); it != colums->end(); ++it)
        {
            archivo>>_lectura;
            aux<<_lectura<<"\t\t";
            if(_lectura==_column)
                eliminar=cont;
            cont++;
        }
        while(!archivo.eof()){
            string _ingreso="";
            bool _find=false;
            for(int i=0;i<eliminar;i++){
                archivo>>_lectura;
                if(i==eliminar-1 && _lectura==_condition){
                    _find=true;
                    _ingreso+=_nuevo;
                }
                else if(i==eliminar-1){
                    _ingreso+=_lectura;
                }
                else{
                    _ingreso+=_lectura+"\t\t";
                }
            }
            getline(archivo,_lectura);
            aux<<endl<<_ingreso;
            aux<<_lectura;   
        }
        archivo.close();
        aux.close();

        string _remove="BasesDeDatos/"+bd+"/"+tabla+".txt";
        string _rename="BasesDeDatos/"+bd+"/aux"+".txt";
        remove(_remove.c_str());                    
        rename(_rename.c_str(), _remove.c_str());
    }

    void printData(string bd,string tabla){
        fstream archivo,aux;
        archivo.open("BasesDeDatos/"+bd+"/"+tabla+".txt",ios::in);

        string _lectura;
        while(!archivo.eof()){
            getline(archivo,_lectura);
            cout<<_lectura<<endl;
        }
    }
};

template <typename T>
class Database
{
private:
    string key;
    list< Table<T> > *tables;
    
    template <typename U>
    friend class Hash;
    template <typename T>
    friend class LRUcache;

public:
    Database()
    {
        key = "";
        tables= new list< Table<T> > [1];
    }
    Database(string k)
    {
        key = k;
        tables= new list< Table<T> > [1];
    }
    void insertTable(string name,string database)
    {
        Table<T>* nueva_tabla= new Table<T>(name);
        tables->push_back(*nueva_tabla);
       
        fstream tabla_txt;
        tabla_txt.open("BasesDeDatos/"+database+"/"+name+".txt",ios::out);

        string nueva_columna;
        cout<<"\tNo ingrese nada para dejar de insertar columnas"<<endl;
        do
        {
            cout<<"\tColumna: ";
            getline(cin,nueva_columna);
            if(nueva_columna != "\0"){
                (*nueva_tabla).insert(nueva_columna);
                tabla_txt<<nueva_columna<<"\t\t";
            }
            else
                break;
        } while (true);
        tabla_txt.close();
    }

    void deleteTable(string _table){
        string borrar="BasesDeDatos/"+key+"/"+_table+".txt";
        remove(borrar.c_str());
    }

    void deleteData(string _bd){
        string _table;
        cout<<"Ingrese la tabla: "<<endl;
        getline(cin,_table);

        typename list<Table <T> >:: iterator it=search(_table);
        if(it!=tables->end() && (*it).name==_table){
            (*it).deleteData(_bd,_table);
        }

    }

    void selectfrom(string rows, string bd, string tb)
    {
        typename list<Table <T> >:: iterator it=search(tb);
        if(it!=tables->end() && (*it).name==tb){
            (*it).selectfrom(rows,bd,tb);
        }
    }

    void insertData(string _bd){
        cout<<endl<<"Ingrese la tabla: "<<endl;
        string _table;
        getline(cin,_table);
        typename list<Table <T> >:: iterator it=search(_table);
        if(it!=tables->end() && (*it).name==_table){
            (*it).insertData(_bd,_table);
        }
    }

    void updateData(string _bd){
        cout<<endl<<"Ingrese la tabla: "<<endl;
        string _table;
        getline(cin,_table);
        typename list<Table <T> >:: iterator it=search(_table);
        if(it!=tables->end() && (*it).name==_table){
            (*it).updateData(_bd,_table);
        }
    }

    void printData(string _bd){
        cout<<endl<<"Ingrese la tabla: "<<endl;
        string _table;
        getline(cin,_table);
        typename list<Table <T> >:: iterator it=search(_table);
        if(it!=tables->end() && (*it).name==_table){
            (*it).printData(_bd,_table);
        }
    }

    typename list<Table <T> >:: iterator search(string _table){
        for (typename list<Table <T> >:: iterator it = tables->begin(); it != tables->end(); ++it){
            if((*it).name==_table){
                return it;
            }
        }
        cout<<"No encontrado"<<endl;
        return tables->end();
    }

    void printTables(){
        cout<<endl;
        for (typename list<Table <T> >:: iterator it = tables->begin(); it != tables->end(); ++it){
            cout<<"\t\t"<<(*it).name;
        }
        cout<<endl;
    }
};

template <typename T>
class Hash
{
private:
    int tam;
    list< Database<T> > *tabla;
    int fd(string key, int n)
    {
        const char *k = key.c_str();
        int s = 0;
        while (*k)
        {
            s = s + int(*k);
            k++;
        }
        return s % n;
    }

public:
    Hash()
    {
        tam = 0;
        tabla = NULL;
    }
    Hash(int t)
    {
        //el tamaño sera el siguiente primo de esta manera hay menos coliciones :D
        tam = sigPrimo(t);
        tabla = new list< Database<T> >[tam];
    }

    int hash(string k)
    {
        return fd(k, tam);
    }

    typename list<Database <T> >:: iterator search(string _bd){
        int indice = fd(_bd, tam);
        for (typename list<Database <T> >:: iterator it = tabla[indice].begin(); it != tabla[indice].end(); ++it){
            if((*it).key==_bd){
                return it;
            }
        }
        cout<<"No encontrado"<<endl;
        return tabla[indice].end();
    }

    void insert(string k)
    {
        int indice = fd(k, tam);
        Database<T> * nueva= new Database<T>(k);
        tabla[indice].push_back(*nueva);

        string carpeta="mkdir "+k;
        system(carpeta.c_str());
        string mover = "";
        mover += "move ";
        mover += k+" BasesDeDatos/";
        system(mover.c_str());
        fstream nueva_bd;
        nueva_bd.open("BasesDeDatos/"+k+"/"+k+".txt",ios::out);

        string nueva_tabla;
        cout<<"No ingrese nada para dejar de insertar tablas"<<endl;
        do
        {
            cout<<"Tabla: ";
            getline(cin,nueva_tabla);
            if(nueva_tabla != "\0"){
                (*nueva).insertTable(nueva_tabla,k);
                nueva_bd<<nueva_tabla<<"\t\t";
            }
            else
                break;
        } while (true);
        nueva_bd.close();
    }
    void remove(string bd)
    {
        string borrar="rm -r BasesDeDatos/"+bd;
        system(borrar.c_str());
    }

    void print()
    {
        for (int i = 0; i < tam; i++)
        {
            for (typename list<Database <T> >:: iterator it = tabla[i].begin(); it != tabla[i].end(); ++it)
            {
                if((*it).key!=""){
                    cout << (*it).key << "    ";
                    (*it).printTables();
                }
            }
        }
    }

    void printData(){
        cout<<endl<<"Ingrese la base de datos: "<<endl;
        string bd;
        cin>> bd;
        cout<<bd;
        typename list<Database <T> >:: iterator it=search(bd);
        if((*it).key==bd){
            (*it).printData(bd);
        }
    }

    void selectfrom(string rows, string bd, string tb)
    {
        typename list<Database <T> >:: iterator it=search(bd);
        if ((*it).key==bd)
        {
            (*it).selectfrom(rows, bd, tb);
        }
        
    }

    void insertData(string &dbName = "", string &dbCopy = "", bool &backupCreado = false){
        cout<<endl<<"Ingrese la base de datos: "<<endl;
        string bd;
        getline(cin,bd);
        typename list<Database <T> >:: iterator it=search(bd);
        if((*it).key==bd){
            if (dbCopy != "" && dbCopy != bd) {
                cout<<"Solo se puede modificar una Base de datos a la vez en una transaccion"<<endl;
                return;
            }
            if (dbCopy != "" && !backupCreado) {
                dbName = bd;
                system("mkdir TemporaryFiles\\"+dbCopy);
                system("xcopy BasesDeDatos\\"+bd+" TemporaryFiles\\"+dbCopy+" /E /I /Y");
                backupCreado = true;
            }
            bd_name = bd;
            (*it).insertData(bd);
        }
    }

    void deleteData(string &dbName = "", string &dbCopy = "", bool &backupCreado = false){
        cout<<endl<<"Ingrese la base de datos: "<<endl;
        string bd;
        getline(cin,bd);
        typename list<Database <T> >:: iterator it=search(bd);
        if((*it).key==bd){
            if (dbCopy != "" && dbCopy != bd) {
                cout<<"Solo se puede modificar una Base de datos a la vez en una transaccion"<<endl;
                return;
            }
            if (dbCopy != "" && !backupCreado) {
                dbName = bd;
                system("mkdir TemporaryFiles\\"+dbCopy);
                system("xcopy BasesDeDatos\\"+bd+" TemporaryFiles\\"+dbCopy+" /E /I /Y");
                backupCreado = true;
            }
            (*it).deleteData(bd);
        }
    }

    void updateData(string &dbName = "", string &dbCopy = "", bool &backupCreado = false){
        cout<<endl<<"Ingrese la base de datos: "<<endl;
        string bd;
        getline(cin,bd);
        typename list<Database <T> >:: iterator it=search(bd);
        if((*it).key==bd){
            if (dbCopy != "" && dbCopy != bd) {
                cout<<"Solo se puede modificar una Base de datos a la vez en una transaccion"<<endl;
                return;
            }
            if (dbCopy != "" && !backupCreado) {
                dbName = bd;
                system("mkdir TemporaryFiles\\"+dbCopy);
                system("xcopy BasesDeDatos\\"+bd+" TemporaryFiles\\"+dbCopy+" /E /I /Y");
                backupCreado = true;
            }
            (*it).updateData(bd);
        }
    }
};

template <typename T>
class LRUcache
{
private:
    list< Table<T> > *dq;
    unordered_map<int, list<int>::iterator> ma;

    int csize;

public:
    LRUcache(int t, Database<T> database)
    {
        dq=&database->tables;
        csize = t;
    }

    void refer(int x)
    {
        if (ma.find(x)==ma.end())
        {
            if (dq->size()==csize)
            {
                int last = dq.back();

                dq.pop_back();
                ma.erase(last);
            }
        }
        else
        {
            dq.erase(ma[x]);
        }
        dq.push_front(x);
        ma[x] = dq.begin();
    }
};

int main()
{
    menu();
    return 0;
}

int sigPrimo(int val)

{
    for (int i = val;; i++, val++)
    {
        if (ConsultaPrimo(val))
            return val;
    }
}
bool ConsultaPrimo(int num)
{
    if (num % 2 == 0)
        return false;
    else
    {
        for (int y = 3; y <= sqrt(num); y += 2)
            if (num % y == 0)
                return false;
        return true;
    }
}

void menu(){
    Transaction<string> transacciones;
    Hash<string> h(17);
    int opcion;
    string bd, tb;
    do
    {
        cout<<"¿Que accion desea realizar?"<<endl;
        cout<<"1 Crear"<<endl;
        cout<<"2 Insertar"<<endl;
        cout<<"3 Mostrar"<<endl;
        cout<<"4 Eliminar"<<endl;
        cout<<"5 Actualizar"<<endl;
        cout<<"6 Ninguna"<<endl;
        cin>>opcion;
        system("cls");
        fflush(stdin);
        bool backupCreado = false;
        string dbName = "", dbCopy = "";
        switch (opcion)
        {
        case 1:
            char c;
            cout<<"Desea crear una transaccion? (s/n)"<<endl; cin>>c;
            if(c=='s' || c=='S'){
                cout << "Se esta creando una transaccion" << endl;
                transacciones.startTransaction(h);
            }
            else{
                cout << "Se esta creando una base de datos" << endl;
                cout << "Ingrese el nombre de la base de datos" << endl;
                cin.ignore();
                getline(cin,bd);
                h.insert(bd);
            }
            break;
        case 2:
            h.insertData(bd, dbCopy, backupCreado);
            break;
        case 3:
            cout<<"Elija que tablas de la base de datos desee mostrar"<<endl;
            cout<<"Base de Datos"<<endl;
            cin>>bd;
            cout<<"Tabla"<<endl;
            cin>>tb;
            h.selectfrom("*",bd,tb);
            h.printData();
            cout<<"Pulse una tecla para continuar"<<endl;
            break;
        case 4:
            // cout<<"Nombre de la BD: ";
            // getline(cin,bd);
            // h.remove(bd);
            h.deleteData(dbName, dbCopy, backupCreado);
            break;
        case 5:
            h.updateData(dbName, dbCopy, backupCreado);
            break;
        default:
            break;
        }
    } while (opcion!=6);
}
//ordenar, modificar, consultas a una tabla