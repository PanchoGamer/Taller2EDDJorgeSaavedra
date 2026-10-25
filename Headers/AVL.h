#pragma once
#include "NodeAVL.h"
#include <string>
using namespace std;

class AVL{
    private:
        NodeAVL* root;
        
        int height(NodeAVL* nodo);
        void cambiarAltura(NodeAVL* nodo);
        int factorDeBalance(NodeAVL* nodo);
        NodeAVL* rotarDerecha(NodeAVL* y);
        NodeAVL* rotarIzquierda(NodeAVL* x);

        NodeAVL* insertar(NodeAVL* node, Persona* p);
        Persona* encontrarMedianteID(NodeAVL* node, string id);
        void mostrarBalance(NodeAVL* node);
        void borrarTodo(NodeAVL* node);

    public:
        AVL();

        bool insert(Persona* p);

        bool exists(string id);

        bool remove(NodeAVL* nodo);

        NodeAVL* getRoot();

        Persona* encontrarPorID(string id);

        Persona* encontrarPorNombre(string nombre, NodeAVL* node = nullptr, bool inicial = true);

        void inOrder(NodeAVL* node);

        void preOrder(NodeAVL* node);
        
        void postOrder(NodeAVL* node);

        int getHeight();

        void getFactorDeBalance();

        bool isEmpty();
        
        ~AVL();
};