#include <iostream>
#include <limits>

using namespace std;

union Coordenada {
    struct {
        int x;
        int y;
    };
};

string determinarCuadrante(int x, int y) {
    if (x > 0 && y > 0) return "Cuadrante I";
    if (x < 0 && y > 0) return "Cuadrante II";
    if (x < 0 && y < 0) return "Cuadrante III";
    if (x > 0 && y < 0) return "Cuadrante IV";
    if (x == 0 && y != 0) return "Eje Y";
    if (x != 0 && y == 0) return "Eje X";
    if (x == 0 && y == 0) return "Origen";
    return "Eje";
}

bool sonColineales(Coordenada p1, Coordenada p2, Coordenada p3) {
    return (p2.y - p1.y) * (p3.x - p2.x) == (p3.y - p2.y) * (p2.x - p1.x);
}

void imprimirEcuacionLinea(Coordenada p1, Coordenada p2) {
    int a = p2.y - p1.y;
    int b = p1.x - p2.x;
    int c = a * p1.x + b * p1.y;
    cout << "Ecuacion de la linea: " << a << "x + " << b << "y = " << c << endl;
}

int main() {
    int n;

    cout << "Ingrese el número de coordenadas: ";
    cin >> n;

    Coordenada coordenadas[n];

    for (int i = 0; i < n; ++i) {
        while (true) {
            cout << "Ingrese la coordenada " << i + 1 << " (x y): ";
            cin >> coordenadas[i].x >> coordenadas[i].y;

            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Entrada inválida. Por favor, ingrese dos números enteros separados por un espacio." << endl;
            } else {
                break; 
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "La coordenada (" << coordenadas[i].x << ", " << coordenadas[i].y << ") esta en el " 
             << determinarCuadrante(coordenadas[i].x, coordenadas[i].y) << endl;
    }

    for (int i = 0; i < n - 2; ++i) {
        if (sonColineales(coordenadas[i], coordenadas[i + 1], coordenadas[i + 2])) {
            imprimirEcuacionLinea(coordenadas[i], coordenadas[i + 1]);
        }
    }

    return 0;
}