#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "../Dominio/Persona.h"
#include "../Dominio/Queue.h"
#include "../Dominio/List.h"
#include "../Dominio/Node.h"
#include "../Dominio/AVL.h";
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

void leerArchivo(Queue<Persona*>& cola){
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

    cout << cola.size() << endl;
}

void atenderPacientes(Queue<Persona*>& lista, Queue<AVL*>& servicios){
    if(!lista.empty()){
        Persona* p = lista.front();
        lista.pop();

        if(p->getDolor() >= 8 || p->getTemp() >= 40 || p->getTemp() <= 35){
            servicios.consultar(0)->insert(new NodeAVL(p));
        } else if(p->getTrauma() == 1){
            if(p->getRequiereCirugia() == 1){
                servicios.consultar(5)->insert(new NodeAVL(p));
            } else{
                servicios.consultar(4)->insert(new NodeAVL(p));
            }
        } else if(p->getTipoDolor() == "pecho"){
            servicios.consultar(2)->insert(new NodeAVL(p));
        } else if(p->getSintomasNeurologicos() == 1){
            servicios.consultar(3)->insert(new NodeAVL(p));
        } else if(p->getAge() <= 14){
            servicios.consultar(6)->insert(new NodeAVL(p));
        } else if(p->getDiasHospitalizacion() > 0){
            servicios.consultar(7)->insert(new NodeAVL(p));
        } else{
            servicios.consultar(1)->insert(new NodeAVL(p));
        }

    } else{
        cout << "No quedan pacientes" << endl;
    }
}

void verDepartamentos(){

}

void buscarPaciente(){

}


int main(){
    Queue<Persona*> listaEspera;
    Queue<AVL*> servicios;
    leerArchivo(listaEspera);
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
                    atenderPacientes(listaEspera, servicios);
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