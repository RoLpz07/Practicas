#include<iostream>
#include<fstream>
using namespace std;

struct Persona {
  int id_del_registro;
  char nombre[50];
  char cedula[20];
  int edad;
  float peso;
  float altura;
  char genero;
};

int main(){
Persona p1 = {1, "Juan Pérez", "12345678", 25, 70.5, 1.75, 'M'};
Persona p2 = {2, "María García", "23456789", 30, 60.2, 1.65, 'F'};
Persona p3 = {3, "Pedro López", "34567890", 35, 80.1, 1.80, 'M'};

    fstream archivo("./personas.bin",ios::out| ios::binary);
    
    archivo.write(reinterpret_cast<char *>(&p1), sizeof(Persona));
    archivo.write(reinterpret_cast<char *>(&p2), sizeof(Persona));
    archivo.write(reinterpret_cast<char *>(&p3), sizeof(Persona));
    
    archivo.close();
    return 0;
}