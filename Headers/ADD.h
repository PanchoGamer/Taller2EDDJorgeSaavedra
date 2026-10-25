#pragma once
#include "DecisionNode.h"

class ADD{
    private:
        DecisionNode* raiz;

        bool responder(int pregunta, Persona* p);
        
        void destruir(DecisionNode* nodo);

    public:
        ADD();
        ~ADD();

        void construir();

        bool validarDatos(Persona* p);

        int evaluar(Persona* p, bool camino);
};