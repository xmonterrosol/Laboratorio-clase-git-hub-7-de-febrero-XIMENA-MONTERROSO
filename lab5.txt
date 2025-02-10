#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Producto {
private:
    string nombre;
    int codigo;
    float precio;
    int stock;

public:
    // Constructor
    Producto(string nom = "", int cod = 0, float prec = 0.0, int stk = 0)
        : nombre(nom), codigo(cod), precio(prec), stock(stk) {
    }

    // Método para mostrar información del producto
    void mostrar() const {
        cout << "Código: " << codigo << ", Producto: " << nombre
            << ", Precio: Q" << precio << ", Stock: " << stock << endl;
    }

    // Método para obtener el código del producto
    int obtenerCodigo() const {
        return codigo;
    }

    // Método para obtener el stock del producto
    int obtenerStock() const {
        return stock;
    }

    // Método para actualizar el stock del producto
    void actualizarStock(int cantidad) {
        if (cantidad > stock) {
            cout << "No hay suficiente stock disponible." << endl;
        }
        else {
            stock -= cantidad;
            cout << "Stock actualizado. Nuevo stock: " << stock << endl;
        }
    }

    // Método para obtener el valor total del stock
    double obtenerValor() const {
        return stock * precio;
    }
};

void agregarProducto(vector<Producto>& inventario) {
    string nombre;
    int codigo, stock;
    float precio;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el código: ";
    cin >> codigo;

    cout << "Ingrese el precio: ";
    cin >> precio;

    cout << "Ingrese la cantidad en stock: ";
    cin >> stock;

    inventario.push_back(Producto(nombre, codigo, precio, stock));
}

void mostrarInventario(const vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "No hay productos en el inventario." << endl;
        return;
    }

    for (const auto& producto : inventario) {
        producto.mostrar();
    }
}

void buscarProducto(const vector<Producto>& inventario) {
    int codigo;

    cout << "Ingrese el código del producto a buscar: ";
    cin >> codigo;

    for (const auto& producto : inventario) {
        if (producto.obtenerCodigo() == codigo) {
            cout << "Producto encontrado: ";
            producto.mostrar();
            return;
        }
    }

    cout << "Producto no encontrado." << endl;
}

void actualizarStock(vector<Producto>& inventario) {
    int codigo, cantidad;

    cout << "Ingrese el código del producto a actualizar: ";
    cin >> codigo;

    for (auto& producto : inventario) {
        if (producto.obtenerCodigo() == codigo) {
            cout << "Ingrese la cantidad a restar del stock: ";
            cin >> cantidad;
            producto.actualizarStock(cantidad);
            return;
        }
    }

    cout << "Producto no encontrado." << endl;
}

void calcularValorTotal(const vector<Producto>& inventario) {
    double total = 0.0;

    for (const auto& producto : inventario) {
        total += producto.obtenerValor();
    }

    cout << "Valor total del inventario: Q" << total << endl;
}

int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        cout << "\nSistema de Inventario\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Buscar producto por código\n";
        cout << "4. Actualizar stock\n";
        cout << "5. Calcular valor total del inventario\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregarProducto(inventario);
            break;
        case 2:
            mostrarInventario(inventario);
            break;
        case 3:
            buscarProducto(inventario);
            break;
        case 4:
            actualizarStock(inventario);
            break;
        case 5:
            calcularValorTotal(inventario);
            break;
        case 6:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}