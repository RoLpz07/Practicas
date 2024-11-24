#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

struct Punto {
    int x, y;
};

double calcularDistancia(const Punto& p1, const Punto& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool estaDentroDelCuadrante(const Punto& p, int xMin, int xMax, int yMin, int yMax) {
    return p.x >= xMin && p.x <= xMax && p.y >= yMin && p.y <= yMax;
}

double encontrarDistanciaMaxima(Punto puntos[], int n, int xMin, int xMax, int yMin, int yMax) {
    double distanciaMaxima = 0.0;
    for (int i = 0; i < n; ++i) {
        if (!estaDentroDelCuadrante(puntos[i], xMin, xMax, yMin, yMax)) continue;
        for (int j = i + 1; j < n; ++j) {
            if (!estaDentroDelCuadrante(puntos[j], xMin, xMax, yMin, yMax)) continue;
            double distancia = calcularDistancia(puntos[i], puntos[j]);
            if (distancia > distanciaMaxima) {
                distanciaMaxima = distancia;
            }
        }
    }
    return distanciaMaxima;
}

void imprimirDistanciasDesdePunto(Punto puntos[], int n, int indice, int xMin, int xMax, int yMin, int yMax) {
    if (!estaDentroDelCuadrante(puntos[indice], xMin, xMax, yMin, yMax)) {
        cout << "El punto no está dentro del cuadrante." << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (i == indice) continue;
        if (estaDentroDelCuadrante(puntos[i], xMin, xMax, yMin, yMax)) {
            double distancia = calcularDistancia(puntos[indice], puntos[i]);
            cout << "Distancia del punto (" << puntos[indice].x << ", " << puntos[indice].y << ") al punto ("
                 << puntos[i].x << ", " << puntos[i].y << ") es: " << distancia << endl;
        }
    }
}

int main() {
    int xMin, xMax, yMin, yMax;
    cout << "Ingrese los límites del cuadrante (xMin, xMax, yMin, yMax): ";
    cin >> xMin >> xMax >> yMin >> yMax;

    int n;
    cout << "Ingrese el número de puntos: ";
    cin >> n;

    Punto puntos[n];
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese las coordenadas del punto " << i + 1 << " (x y): ";
        cin >> puntos[i].x >> puntos[i].y;
    }

    double distanciaMaxima = encontrarDistanciaMaxima(puntos, n, xMin, xMax, yMin, yMax);
    cout << "La distancia máxima entre dos puntos dentro del cuadrante es: " << distanciaMaxima << endl;

    int indice;
    cout << "Ingrese el índice del punto para calcular las distancias (1 a " << n << "): ";
    cin >> indice;
    --indice;

    imprimirDistanciasDesdePunto(puntos, n, indice, xMin, xMax, yMin, yMax);

    return 0;
}