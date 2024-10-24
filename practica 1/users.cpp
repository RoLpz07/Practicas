#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){

    int N;
    string nombre;
    int dni;
    string email;

    ofstream archivo("../data/users.txt");
    
    if( !archivo.is_open()){
        cout<<"No se puede abrir ni crear el archivo"<<endl;
        return 0;
    }

    cout<<"Cuantos registros de personas va a ingresar?"<<endl;
    cin>>N;
   
    for(int i=0; i<N; i++){
        cout<<"Ingrese el nombre de la persona "<<i+1<<endl;
        cin>>nombre;
        cout<<"Ingrese el DNI de la persona "<<i+1<<endl;
        cin>>dni;
        cout<<"Ingrese el email de la persona "<<i+1<<endl;
        cin>>email;
        archivo<<nombre<<" "<<dni<<" "<<email<<endl;
    }

    archivo.close();

    return 0;
}