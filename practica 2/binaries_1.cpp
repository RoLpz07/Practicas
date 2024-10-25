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
  Persona x;
  fstream archivo("./personas.bin",ios::in| ios::binary);

  while(archivo.read(reinterpret_cast<char *>(&x), sizeof(Persona))){
    cout<<"ID del registro: "<<x.id_del_registro<<endl;
    cout<<"Nombre: "<<x.nombre<<endl;
    cout<<"Cédula: "<<x.cedula<<endl;
    cout<<"Edad: "<<x.edad<<endl;
    cout<<"Peso: "<<x.peso<<endl;
    cout<<"Altura: "<<x.altura<<endl;
    cout<<"Género: "<<x.genero<<endl;
    cout<<endl;
  }

  archivo.close();
  return 0;
}