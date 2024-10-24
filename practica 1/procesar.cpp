#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream archivo("../data/users.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        string nombre, cedula, correo;

        iss >> nombre >> cedula >> correo;

        cout << "mi nombre es " << nombre << ", numero de cedula: " << cedula << ", mi correo es " << correo << endl;
    }

    archivo.close();
    return 0;
}