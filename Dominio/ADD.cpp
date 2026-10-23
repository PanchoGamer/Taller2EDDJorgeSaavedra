#include <iostream>
#include "ADD.h"
#include "Persona.h"
#include <string>
using namespace std;

bool esDolorPecho(Persona* p){
    string t = p->getTipoDolor();
    return t == "pecho" || t == "Pecho" || t == "PECHO";
}

ADD::ADD(){
    this->raiz = nullptr;
}

ADD::~ADD(){
    destruir(raiz);
}

bool ADD::responder(int pregunta, Persona* p){
    switch(pregunta){
        case pUrgente:
            return p->getDolor() >= 8 || p->getTemp() <= 35.0 || p->getTemp() >= 40.0;
        case pTrauma:
            return p->getTrauma() == 1;
        case pCirugia:
            return p->getRequiereCirugia() == 1;
        case pPecho:
            return esDolorPecho(p);
        case pNeuro:
            return p->getSintomasNeurologicos() == 1;
        case pNiño:
            return p->getAge() <= 14;
        case pHospital:
            return p->getDiasHospitalizacion() > 0;
    }
    return false;
}

void ADD::construir(){
    if (this->raiz != nullptr) return;

    DecisionNode* urgente = new DecisionNode("Dolor >= 8 o Temperatura <= 35.0 o Temperatura >= 40.0", "Dolor < 8 y Temperatura entre 35.0 y 40.0", pUrgente);
    DecisionNode* trauma = new DecisionNode("Trauma = 1", "Trauma = 0", pTrauma);
    DecisionNode* cirugiaTrauma = new DecisionNode("Requiere Cirugia = 1", "Requiere Cirugia = 0", pCirugia);
    DecisionNode* cirugiaUnico = new DecisionNode("Requiere Cirugia = 1", "Requiere Cirugia = 0", pCirugia);
    DecisionNode* pecho = new DecisionNode("Tipo Dolor = Pecho", "Tipo Dolor != Pecho", pPecho);
    DecisionNode* neuro = new DecisionNode("Sintomas Neurologicos = 1", "Sintomas Neurologicos = 0", pNeuro);
    DecisionNode* pediatria = new DecisionNode("Edad <= 14", "Edad > 14", pNiño);
    DecisionNode* hospitalizacion = new DecisionNode("DiasHospitalizacion > 0", "DiasHospitalizacion = 0", pHospital);

    urgente->setSi(new DecisionNode(Servicio::urgencias));
    urgente->setNo(trauma);

    trauma->setSi(cirugiaTrauma);
    trauma->setNo(cirugiaUnico);

    cirugiaTrauma->setSi(new DecisionNode(Servicio::cirugia));
    cirugiaTrauma->setNo(new DecisionNode(Servicio::traumatologia));

    cirugiaUnico->setSi(new DecisionNode(Servicio::cirugia));
    cirugiaUnico->setNo(pecho);

    pecho->setSi(new DecisionNode(Servicio::cardiologia));
    pecho->setNo(neuro);

    neuro->setSi(new DecisionNode(Servicio::neurologia));
    neuro->setNo(pediatria);

    pediatria->setSi(new DecisionNode(Servicio::pediatria));
    pediatria->setNo(hospitalizacion);

    hospitalizacion->setSi(new DecisionNode(Servicio::hospitalizacion));
    hospitalizacion->setNo(new DecisionNode(Servicio::medicinaGeneral));

    this->raiz = urgente;
}

bool ADD::validarDatos(Persona* p){
    if(!p) return false;
    if(p->getAge() < 0) return false;
    if(p->getDolor() < 0 || p->getDolor() > 10) return false;
    if(p->getTrauma() < 0 || p->getTrauma() > 1) return false;
    if(p->getSintomasNeurologicos() < 0 || p->getSintomasNeurologicos() > 1) return false;
    if(p->getRequiereCirugia() < 0 || p->getRequiereCirugia() > 1) return false;
    if(p->getDiasHospitalizacion() < 0) return false;

    return true;
}

int ADD::evaluar(Persona* p, bool camino){
    if(this->raiz == nullptr || !validarDatos(p)){
        if(camino){
            cout << "Ruta: datos invalidos -> " << Servicio::medicinaGeneral << endl;
        }
        return Servicio::medicinaGeneral;
    }

    DecisionNode* actual = this->raiz;
    string nCamino = "";
    while(!actual->esHoja()){
        bool respuesta = responder(actual->getPregunta(),p);
        nCamino += respuesta ? actual->getTextoSi() : actual->getTextoNo();
        nCamino += " -> ";
        actual = respuesta ? actual->getSi() : actual->getNo();
    } 

    if(camino){
        cout << "Ruta: " << nCamino << actual->getDescripcion() << endl;
    }
    return actual->getServicio();
}

void ADD::destruir(DecisionNode* nodo){
    if(!nodo) return;
    destruir(nodo->getSi());
    destruir(nodo->getNo());
    delete nodo;
}