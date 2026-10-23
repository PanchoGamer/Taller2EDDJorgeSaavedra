#include "NodeAVL.h"

class AVL{
    private:
        NodeAVL* root;
        AVL* next;
        
        int height(NodeAVL* nodo);
        void cambiarAltura(NodeAVL* nodo);
        int factorDeBalance(NodeAVL* nodo);
        NodeAVL* rotarDerecha(NodeAVL* y);
        NodeAVL* rotarIzquierda(NodeAVL* x);

        NodeAVL* insertar(NodeAVL* node, Persona* p);
        Persona* encontrarMedianteID(NodeAVL* node, string id);
        void inOrderRecursivo(NodeAVL* node);
        void preOrderRecursivo(NodeAVL* node);
        void postOrderRecursivo(NodeAVL* node);
        void mostrarBalance(NodeAVL* node);
        void destruir(NodeAVL* node);

    public:
        AVL();

        bool insert(Persona* p);

        bool exists(NodeAVL* nodo);

        bool remove(NodeAVL* nodo);

        void clear();

        NodeAVL* getRoot();

        AVL* getNext();

        void setNext(AVL* next);

        Persona* encontrarPorID(string id);

        void inOrder();

        void preOrder();
        
        void postOrder();

        int getHeight();

        void getFactorDeBalance();

        bool isEmpty();
        
        ~AVL();
};