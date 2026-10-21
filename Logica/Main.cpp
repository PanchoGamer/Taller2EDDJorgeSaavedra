#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Persona.h"
#include "Queue.h"
#include "List.h"
#include "Node.h"
using namespace std;

struct NodoAVL {
    Persona* paciente;
    int altura;
    NodoAVL* izq;  
    NodoAVL* der;
    NodoAVL(Persona* val) : paciente(val), altura(1), izq(nullptr), der(nullptr) {}
};

int altura(NodoAVL* n) {
    return n ? n->altura : 0;
}

int factorBalance(NodoAVL* n) {
    return n ? altura(n->izq) - altura(n->der) : 0;
}

bool verificarCin(int& valor){
    cin >> valor;   
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

void leerArchivo(){
    ifstream archivo("Pacientes.txt");

    if(!archivo.is_open()) {
        cout << "El archivo no existe" << endl;
        return;
    }

    string linea;
    while (getline(archivo,linea)){
        stringstream ss(linea);
        string id, nombre, ageTexto, tempTexto, pArterialTexto, dolorTexto, tipoDolor, traumaTexto, sintomaTexto, cirugiaTexto, diasTexto;
        
        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, ageTexto, ';');
        getline(ss, tempTexto, ';');
        getline(ss, pArterialTexto, ';');
        getline(ss, dolorTexto, ';');
        getline(ss, tipoDolor, ';');
        getline(ss, traumaTexto, ';');
        getline(ss, sintomaTexto, ';');
        getline(ss, cirugiaTexto, ';');
        getline(ss, diasTexto, ';');

        int age = stoi(ageTexto);
        double temperatura = stod(tempTexto);
        int presionArterial = stoi(pArterialTexto);
        int dolor = stoi(dolorTexto);
        int trauma = stoi(traumaTexto);
        int sintomasNeurologicos = stoi(sintomaTexto);
        int requiereCirugia = stoi(cirugiaTexto);
        int diasHospitalizacion = stoi(diasTexto);

        Persona* p = new Persona(id,nombre,age,temperatura,presionArterial,dolor,tipoDolor,trauma,sintomasNeurologicos,requiereCirugia,diasHospitalizacion);
        

    }
}

void atenderPacientes(){
    
}

void verDepartamentos(){

}

void buscarPaciente(){

}

int main(){
    Queue<Persona>* listaEspera = new Queue<Persona>();
    leerArchivo();
    int opcion = 0;
    do{
        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver Departamentos" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Salir" << endl;
        cout << "" << endl;
        cout << "\nSeleccione opcion: ";

        if(!verificarCin(opcion)){
            cout << "Error. Use solo numeros\n" << endl;
            continue;
        }
        if(opcion < 1 || opcion > 4){
            cout << "Error ingrese entre las opciones mostradas" << endl;
            cout << "" << endl;
        } else{
            switch (opcion){
                case 1:
                    atenderPacientes();
                    break;
                case 2:
                    verDepartamentos();
                    break;
                case 3:
                    buscarPaciente();
                    break;
            }
        }
    } while (opcion != 4);
    
}