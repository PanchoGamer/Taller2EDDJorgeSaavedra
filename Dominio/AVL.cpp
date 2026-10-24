#include "AVL.h"
#include <iostream>
using namespace std;

AVL::AVL(){
    this->root = nullptr;
}

AVL::~AVL(){}

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

Persona* AVL::encontrarMedianteID(NodeAVL* node, string id){
    if(!node) return nullptr;
    string nodeId = node->getPersona()->getId();
    if(id == nodeId){
        return node->getPersona();
    }
    if(id < nodeId){
        return encontrarMedianteID(node->getLeft(), id);
    }
    return encontrarMedianteID(node->getRight(), id);
}

Persona* AVL::encontrarPorID(string id){
    return encontrarMedianteID(this->root, id);
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

AVL::~AVL(){
    borrarTodo(this->root);
}
