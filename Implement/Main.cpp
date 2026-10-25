#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "../Headers/Queue.h"
#include "../Headers/List.h"
#include "../Headers/Node.h"
#include "../Headers/AVL.h"
#include "../Headers/Departamento.h"
#include "../Headers/ADD.h"
using namespace std;

bool verificarCin(int& valor){
    cin >> valor;   
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

void leerArchivo(Queue<Persona*>& cola){ //Lee el archivo de prueba de los pacientes y los envia a la queue
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
        
        cola.push(p);
    }
}

void crearArboles(List<Departamento*>* servicios){
    string serv[] = {"Urgencias", "Medicina General", "Cardiologia", "Neurologia", "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"};
    for(string s: serv){
        Departamento* d = new Departamento(s);
        servicios->insertLast(d);
    }
}

void mostrarPaciente(Persona* p){
    cout << "" << endl;
    cout << "ID: " << p->getId() << endl;
    cout << "Nombre: " << p->getNombre() << endl;
    cout << "Edad: " << p->getAge() << endl;
    cout << "Temperatura: " << p->getTemp() << endl;
    cout << "Dolor: " << p->getDolor() << endl;
    cout << "Tipo Dolor: " << p->getTipoDolor() << endl;
    cout << "Trauma: " << p->getTrauma() << endl;
    cout << "SintomasNeurologicos: " << p->getSintomasNeurologicos() << endl;
    cout << "RequiereCirugia: " << p->getRequiereCirugia() << endl;
    cout << "DiasHospitalizacion: " << p->getDiasHospitalizacion() << endl;
    cout << "" << endl;
}

void mostrarPorAVL(NodeAVL* node){
    if(!node){
        return;
    }
    mostrarPorAVL(node->getLeft());

    Persona* p = node->getPersona();

    if(p != nullptr){
        cout << "Pacientes: " << p->getNombre() << "(" << p->getId() << ")" << endl;
    }

    mostrarPorAVL(node->getRight());
}

void atenderPacientes(Queue<Persona*>& lista, List<Departamento*>* servicios){ 
    cout << "=== ATENDIENDO PACIENTES ===" << endl;
    if(!lista.empty()){
        Persona* p = lista.front();
        lista.pop();
        mostrarPaciente(p);

        ADD* arbolDecision = new ADD();
        arbolDecision->construir();

        int idServicio = arbolDecision->evaluar(p, true);

        string nombreServicio = Servicio::nombre(idServicio);

        cout << "\nServicio asignado: " << nombreServicio << endl;

        for(int i = 0; i < servicios->getSize(); i++){
            Departamento* dep = servicios->get(i);
            if(dep->getNombre() == nombreServicio){
                dep->getArbol()->insert(p);
            }
        }
        cout << "Paciente ingresado al AVL de " << nombreServicio << endl;
        cout << "" << endl;
    } else{
        cout << "\nNo quedan pacientes\n" << endl;
    }
}

void verDepartamentos(List<Departamento*>* servicios){
    cout << "=== ESTADO DE LOS DEPARTAMENTOS ===\n" << endl;

    for(int i = 0; i < servicios->getSize(); i++){
        Departamento* dep = servicios->get(i);
        cout << dep->getNombre() << endl;

        if(dep->getArbol()->getRoot() == nullptr){
            cout << "Sin Pacientes" << endl;
        } else{
            mostrarPorAVL(dep->getArbol()->getRoot());
        }

        cout << "" << endl;
    }
}

void buscarPaciente(List<Departamento*>* servicios){
    cout << "=== BUSCAR PACIENTE ===\n" << endl;
    cout << "Indique el ID o el Nombre del paciente: ";
    string buscar;
    getline(cin,buscar);

    cout << "\nBuscando en AVL...\n" << endl;

    Persona* paciente = nullptr;
    string dep = "";

    for(int i = 0; i < servicios->getSize(); i++){
        Departamento* depa = servicios->get(i);

        paciente = depa->getArbol()->encontrarPorID(buscar);

        if(paciente == nullptr){
            paciente = depa->getArbol()->encontrarPorNombre(buscar);
        }

        if(paciente != nullptr){
            dep = depa->getNombre();
            break;
        }
    }

    if(paciente != nullptr){
        cout << "Paciente encontrado:" << endl;
        cout << "-------" << endl;
        cout << "ID: " << paciente->getId() << endl;
        cout << "Nombre: " << paciente->getNombre() << endl;
        cout << "Edad: " << paciente->getAge() << endl;
        cout << "Departamento: " << dep << endl;

        cout << "T: " << paciente->getTemp() << " | "
             << "D: " << paciente->getDolor() << " | "
             << "TD: " << paciente->getTipoDolor() << " | "
             << "T: " << (paciente->getTrauma() == 1 ? "Si" : "No") << " | "
             << "SN: " << (paciente->getSintomasNeurologicos() == 1 ? "Si" : "No") << " | "
             << "RC: " << (paciente->getRequiereCirugia() == 1 ? "Si" : "No") << " | "
             << "DH: " << (paciente->getDiasHospitalizacion() > 0 ? to_string(paciente->getDiasHospitalizacion()) : "Ninguno") 
             << endl;
        cout << "-------" << endl;
    } else {
        cout << "No se encontro ningun paciente con ese id o nombre" << endl;
    }
}

void mostrarPreOrder(List<Departamento*>* servicios){
    cout << "=== RECORRIDO PREORDEN DE LOS DEPARTAMENTOS ===\n" << endl;
    int c = servicios->getSize();
    for(int i = 0; i < c; i++){
        Departamento* dep = servicios->get(i);
        cout << "Departamento: " << dep->getNombre() << endl;
        
        NodeAVL* n = dep->getArbol()->getRoot();
        if(n == nullptr) {
            cout << "Sin Pacientes" << endl;
        } else {
            dep->getArbol()->preOrder(n);
            cout << endl;
        }
        cout << "-----------------------------------" << endl;
    }
    cout << endl;
}

void mostrarInOrder(List<Departamento*>* servicios){
    cout << "=== RECORRIDO INORDER DE LOS DEPARTAMENTOS ===\n" << endl;
    int c = servicios->getSize();
    for(int i = 0; i < c; i++){
        Departamento* dep = servicios->get(i);
        cout << "Departamento: " << dep->getNombre() << endl;
        
        NodeAVL* n = dep->getArbol()->getRoot();
        if(n == nullptr) {
            cout << "Sin Pacientes" << endl;
        } else {
            dep->getArbol()->inOrder(n);
            cout << endl;
        }
        cout << "-----------------------------------" << endl;
    }
    cout << endl;
}

void mostrarPostOrder(List<Departamento*>* servicios){
    cout << "=== RECORRIDO POSTORDER DE LOS DEPARTAMENTOS ===\n" << endl;
    int c = servicios->getSize();
    for(int i = 0; i < c; i++){
        Departamento* dep = servicios->get(i);
        cout << "Departamento: " << dep->getNombre() << endl;
        
        NodeAVL* n = dep->getArbol()->getRoot();
        if(n == nullptr) {
            cout << "Sin Pacientes" << endl;
        } else {
            dep->getArbol()->postOrder(n);
            cout << endl;
        }
        cout << "-----------------------------------" << endl;
    }
    cout << endl;
}

int main(){
    Queue<Persona*> listaEspera;
    List<Departamento*>* servicios = new List<Departamento*>();
    crearArboles(servicios);
    leerArchivo(listaEspera);
    int opcion = 0;
    do{
        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver Departamentos" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Mostrar preOrder" << endl;
        cout << "5. Mostrar inOrder" << endl;
        cout << "6. Mostrar postOrder" << endl;
        cout << "7. Salir" << endl;
        cout << "" << endl;
        cout << "Seleccione opcion: ";

        if(!verificarCin(opcion)){
            cout << "Error. Use solo numeros\n" << endl;
            continue;
        }
        if(opcion < 1 || opcion > 7){
            cout << "Error ingrese entre las opciones mostradas" << endl;
            cout << "" << endl;
        } else{
            switch (opcion){
                case 1:
                    atenderPacientes(listaEspera,servicios);
                    break;
                case 2:
                    verDepartamentos(servicios);
                    break;
                case 3:
                    cin.ignore();
                    buscarPaciente(servicios);
                    break;
                case 4:
                    mostrarPreOrder(servicios);
                    break;
                case 5:
                    mostrarInOrder(servicios);
                    break;
                case 6:
                    mostrarPostOrder(servicios);
                    break;
            }
        }
    } while (opcion != 7);

    delete servicios;
    return 0;
}