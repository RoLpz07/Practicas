#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    int x, y;
};

int determinante(Punto p1, Punto p2, Punto p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int relacionLineas(Punto p1, Punto p2, Punto p3, Punto p4) {
    int d1 = determinante(p1, p2, p3);
    int d2 = determinante(p1, p2, p4);
    int d3 = determinante(p3, p4, p1);
    int d4 = determinante(p3, p4, p2);

    if (d1 * d2 < 0 && d3 * d4 < 0) {
        return 1;
    } else if (d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0) {
        return 0;
    } else {
        return -1;
    }
}

int relacionLineas(Punto p1, Punto p2, Punto p3, Punto p4, bool perpendiculares) {
    if (perpendiculares) {
        int dx1 = p2.x - p1.x;
        int dy1 = p2.y - p1.y;
        int dx2 = p4.x - p3.x;
        int dy2 = p4.y - p3.y;

        if (dx1 * dx2 + dy1 * dy2 == 0) {
            return 1;
        } else if (dx1 * dy2 == dy1 * dx2) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return relacionLineas(p1, p2, p3, p4);
    }
}

double anguloCruce(Punto p1, Punto p2, Punto p3, Punto p4, bool enGrados = false) {
    double dx1 = p2.x - p1.x;
    double dy1 = p2.y - p1.y;
    double dx2 = p4.x - p3.x;
    double dy2 = p4.y - p3.y;

    double dotProduct = dx1 * dx2 + dy1 * dy2;
    double mag1 = sqrt(dx1 * dx1 + dy1 * dy1);
    double mag2 = sqrt(dx2 * dx2 + dy2 * dy2);

    double angle = acos(dotProduct / (mag1 * mag2));

    if (enGrados) {
        angle = angle * 180.0 / M_PI;
    }

    return angle;
}

int contadorLlamadas = 0;

void procesoCualquiera() {
    contadorLlamadas++;
    // Proceso cualquiera
}

int obtenerContadorLlamadas() {
    return contadorLlamadas;
}

int main() {
    Punto p1, p2, p3, p4;

    cout << "Ingrese las coordenadas del primer punto de la primera linea (x y): ";
    cin >> p1.x >> p1.y;
    cout << "Ingrese las coordenadas del segundo punto de la primera linea (x y): ";
    cin >> p2.x >> p2.y;
    cout << "Ingrese las coordenadas del primer punto de la segunda linea (x y): ";
    cin >> p3.x >> p3.y;
    cout << "Ingrese las coordenadas del segundo punto de la segunda linea (x y): ";
    cin >> p4.x >> p4.y;

    cout << "Relacion de las lineas: " << relacionLineas(p1, p2, p3, p4) << endl;
    cout << "Relacion de las lineas (perpendicular y paralelo): " << relacionLineas(p1, p2, p3, p4, true) << endl;

    cout << "Angulo en el punto de cruce (radianes): " << anguloCruce(p1, p2, p3, p4) << endl;
    cout << "Desear el angulo en grados (s/n): ";
    char respuesta;
    cin >> respuesta;
        if (respuesta == 's') {
        cout << "Angulo en el punto de cruce (grados): " << anguloCruce(p1, p2, p3, p4, true) << endl;
        }


    procesoCualquiera();
    procesoCualquiera();
    cout << "Cantidad de veces que se llamo a procesoCualquiera: " << obtenerContadorLlamadas() << endl;

    return 0;
}