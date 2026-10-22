#pragma once
#include "DecisionNode.h"

class ADD{
    private:
        DecisionNode* raiz;

        bool responder(int pregunta, Persona* p);

        void inOrden(DecisionNode* nodo, int nivel);
        void preOrden(DecisionNode* nodo, int nivel);
        void postOrden(DecisionNode* nodo, int nivel);
        void destruir(DecisionNode* nodo);

    public:
        ADD();
        ADD(ADD*) = delete;
};