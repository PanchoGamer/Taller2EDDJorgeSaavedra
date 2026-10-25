    #include "../Headers/AVL.h"
    #include <iostream>
    using namespace std;

    AVL::AVL(){
        this->root = nullptr;
    }

    int AVL::height(NodeAVL* node){
        return node ? node->getAltura() : 0;
    }

    void AVL::cambiarAltura(NodeAVL* node){
        int hLeft = height(node->getLeft());
        int hRight = height(node->getRight());
        node->setAltura(1 + (hLeft > hRight ? hLeft : hRight));
    }

    int AVL::factorDeBalance(NodeAVL* node){
        return node ? height(node->getLeft()) - height(node->getRight()) : 0;
    }

    NodeAVL* AVL::rotarDerecha(NodeAVL* y){
        NodeAVL* x = y->getLeft();
        NodeAVL* z = x->getRight();
        x->setRight(y);
        y->setLeft(z);
        cambiarAltura(y);
        cambiarAltura(x);
        return x;
    }

    NodeAVL* AVL::rotarIzquierda(NodeAVL* x){ 
        NodeAVL* y = x->getRight();
        NodeAVL* z = y->getLeft();
        y->setLeft(x);
        x->setRight(z);
        cambiarAltura(x);
        cambiarAltura(y);
        return y;
    }

    NodeAVL* AVL::insertar(NodeAVL* node, Persona* p){
        if(!node){
            return new NodeAVL(p);
        }

        if(p->getId() < node->getPersona()->getId()){
            node->setLeft(insertar(node->getLeft(), p));
        } else if(p->getId() > node->getPersona()->getId()){
            node->setRight(insertar(node->getRight(), p));
        } else{
            return node;
        }

        cambiarAltura(node);
        int factorBalance = factorDeBalance(node);

        if(factorBalance > 1 && factorDeBalance(node->getLeft()) >= 0){ //LL
            return rotarDerecha(node);  
        }

        if(factorBalance < -1 && factorDeBalance(node->getRight()) <= 0){ //RR
            return rotarIzquierda(node);
        }

        if(factorBalance > 1 && factorDeBalance(node->getLeft()) < 0){ //LR
            node->setLeft(rotarIzquierda(node->getLeft()));
            return rotarDerecha(node);
        }

        if(factorBalance < -1 && factorDeBalance(node->getRight()) > 0){ //RL
            node->setRight(rotarDerecha(node->getRight()));
            return rotarIzquierda(node);
        }

        return node;
    }

    bool AVL::insert(Persona* p){
        if(!p || exists(p->getId())) return false;
        this->root = insertar(this->root, p);
        return true;
    }

    Persona* AVL::encontrarMedianteID(NodeAVL* node, string id){
        if(!node) return nullptr;
        string nodeId = node->getPersona()->getId();

        int idNumero = stoi(id);
        int nodeIdNumero = stoi(nodeId);

        if(idNumero == nodeIdNumero){
            return node->getPersona();
        }
        if(idNumero < nodeIdNumero){
            return encontrarMedianteID(node->getLeft(), id);
        }
        return encontrarMedianteID(node->getRight(), id);
    }

    Persona* AVL::encontrarPorID(string id){
        return encontrarMedianteID(this->root, id);
    }

    Persona* AVL::encontrarPorNombre(string nombre, NodeAVL* node, bool inicial){
        if(inicial){
            node = this->root;
            inicial = false;
        }
        if (!node){
            return nullptr;
        }
        if(node->getPersona()->getNombre() == nombre){
            return node->getPersona();
        }

        Persona* p = encontrarPorNombre(nombre, node->getLeft(), false);
        
        if(p) return p;

        return encontrarPorNombre(nombre, node->getRight(), false);
    }

    bool AVL::exists(string id){
        return encontrarMedianteID(this->root, id) != nullptr;
    }

    void AVL::inOrder(NodeAVL* node){
        if(!node) return;
        inOrder(node->getLeft());
        cout<< node->getPersona()->getId() << " | ";
        inOrder(node->getRight());
    }

    void AVL::preOrder(NodeAVL* node){
        if(!node) return;
        cout << node->getPersona()->getId() << " | ";
        preOrder(node->getLeft());
        preOrder(node->getRight());
    }

    void AVL::postOrder(NodeAVL* node){
        if(!node) return;
        postOrder(node->getLeft());
        postOrder(node->getRight());
        cout << node->getPersona()->getId() << " | ";
    }

    void AVL::borrarTodo(NodeAVL* node){
        if(!node) return;
        borrarTodo(node->getLeft());
        borrarTodo(node->getRight());
        delete node->getPersona();
        delete node;
    }

    int AVL::getHeight(){
        return height(this->root);  
    }

    void AVL::mostrarBalance(NodeAVL* node){
        if(!node) return;
        mostrarBalance(node->getLeft());
        cout << "ID: " << node->getPersona()->getId()
            << " | factor de balance: " << factorDeBalance(node) << endl;
        mostrarBalance(node->getRight());
    }

    void AVL::getFactorDeBalance(){
        mostrarBalance(this->root);
    }

    NodeAVL* AVL::getRoot(){
        return this->root;
    }

    AVL::~AVL(){
        borrarTodo(this->root);
    }