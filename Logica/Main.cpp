#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

struct Nodo {
    int dato;
    int altura;
    Nodo* izq;
    Nodo* der;
    Nodo(int val) : dato(val), altura(1), izq(nullptr), der(nullptr) {}
};

int altura(Nodo* n) {
    return n ? n->altura : 0;
}

int factorBalance(Nodo* n) {
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

void atenderPacientes(){

}

void verDepartamentos(){

}

void buscarPaciente(){

}

int main(){
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