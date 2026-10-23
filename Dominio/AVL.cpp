#include "AVL.h"
#include <iostream>
using namespace std;

AVL::AVL(){
    this->root = nullptr;
    this->next = nullptr;
}

AVL::~AVL(){
    clear();
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
    y->setLeft(x->getRight());
    x->setRight(y);
    cambiarAltura(y);
    cambiarAltura(x);
    return x;
}

NodeAVL* AVL::rotarIzquierda(NodeAVL* x){
    NodeAVL* y = x->getRight();
    x->setRight(y->getLeft());
    y->setLeft(x);
    cambiarAltura(x);
    cambiarAltura(y);
    return y;
}

NodeAVL* AVL::insertar(NodeAVL* node, Persona* p){


}