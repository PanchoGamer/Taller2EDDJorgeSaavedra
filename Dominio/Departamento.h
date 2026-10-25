#pragma once
#include <iostream>
#include "AVL.h"

class Departamento{
    private:
        string nombre;
        AVL* arbol;
    public:
        Departamento(string nombre){
            this->nombre = nombre;
            this->arbol = new AVL();
        }

        string getNombre(){
            return this->nombre;
        }

        AVL* getArbol(){
            return this->arbol;
        }
        
        ~Departamento(){
            delete arbol;
        }
};