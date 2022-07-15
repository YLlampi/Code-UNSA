#include "BufferManager.h"

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