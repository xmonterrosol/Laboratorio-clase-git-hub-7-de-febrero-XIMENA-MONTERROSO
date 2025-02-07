#include <iostream>
using namespace std;

class Animal {
protected:
    string nombre;
    int edad;
public:
    Animal(string n, int e) : nombre(n), edad(e) {}
    virtual void hacerSonido() { cout << nombre << " hace un sonido desconocido." << endl; }
};

class Perro : public Animal {
public:
    Perro(string n, int e) : Animal(n, e) {}
    void hacerSonido() override { cout << nombre << " dice: Guau!" << endl; }
};

class Automovil {
private:
    string marca;
    int velocidad;
public:
    Automovil(string m, int v) : marca(m), velocidad(v) {}
    void acelerar() { velocidad += 10; cout << "El automovil " << marca << " ahora va a " << velocidad << " km/h." << endl; }
};

class Persona { // Corregido el nombre de la clase
private:
    string nombre;
    int edad;
public:
    Persona(string n, int e) : nombre(n), edad(e) {}
    void saludar() { cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años." << endl; }
};

int main() {
    Perro miPerro("Bruno", 5);
    miPerro.hacerSonido();
    Automovil miCoche("Toyota", 60);
    miCoche.acelerar();
    Persona persona1("Angela", 18);
    persona1.saludar();
    return 0;
}