#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

class Consola
{
public:
    void mostarMenu()
    {
        cout << "\n-MENU-" << endl;
        cout << "1: Modulo" << endl;
        cout << "2: Division" << endl;
        cout << "3: Historial" << endl;
        cout << "4: Salir" << endl;
        cout << "Seleccione una opcion: ";
    }
};

class Recibirdata
{
public:
    void ingresonumeros(int &num1, int &num2)
    {
        cout << "Ingresa tu numero 1: ";
        cin >> num1;
        cout << "Ingresa tu numero 2: ";
        cin >> num2;
    }
};

class Division
{
public:
    int div(int num1, int num2)
    {
        if (num2 == 0)
            return 0;
        return num1 / num2;
    }
};

class Modulo
{
public:
    int mod(int num1, int num2)
    {
        return num1 % num2;
    }
};

class Historial
{
public:
    vector<string> operaciones;

public:
    void agregar(string operacion, int num1, int num2, int resultado)
    {
        string linea = operacion + ": " + to_string(num1) + " , " + to_string(num2) + " = " + to_string(resultado);
        operaciones.push_back(linea);
    }

    vector<string> obtenerOperaciones()
    {
        return operaciones;
    }

    void mostrar()
    {
        if (operaciones.empty())
        {
            cout << "No hay operaciones en el historial." << endl;
        }
        else
        {
            cout << "\n--- HISTORIAL ---" << endl;
            for (int i = 0; i < operaciones.size(); i++)
            {
                cout << operaciones[i] << endl;
            }
        }
    }
};

class PantallaConsola
{
public:
    void mostrarResultado(int resultado)
    {
        cout << "Resultado: " << resultado << endl;
    }
};

class PantallaArchivo
{
public:
    void guardarResultado(int resultado, string nombreArchivo)
    {
        ofstream archivo(nombreArchivo, ios::app);

        if (archivo.is_open())
        {
            archivo << "Resultado: " << resultado << endl;
            archivo.close();
            cout << "Resultado guardado en archivo." << endl;
        }
        else
        {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }
};

class Imprimir
{
private:
    PantallaConsola consola;
    PantallaArchivo archivo;

public:
    void mostrarEnConsola(int resultado)
    {
        consola.mostrarResultado(resultado);
    }

    void guardarEnArchivo(int resultado, string nombreArchivo)
    {
        archivo.guardarResultado(resultado, nombreArchivo);
    }
};

int main()
{
    Consola menu;
    Recibirdata recibir;
    Division division;
    Modulo modulo;
    Historial historial;
    Imprimir imprimir;

    int opcion;
    int num1, num2, resultado;

    do
    {
        menu.mostarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            recibir.ingresonumeros(num1, num2);
            resultado = modulo.mod(num1, num2);
            historial.agregar("Modulo", num1, num2, resultado);
            imprimir.mostrarEnConsola(resultado);
            imprimir.guardarEnArchivo(resultado, "resultados.txt");
            break;

        case 2:
            recibir.ingresonumeros(num1, num2);
            resultado = division.div(num1, num2);
            historial.agregar("Division", num1, num2, resultado);
            imprimir.mostrarEnConsola(resultado);
            imprimir.guardarEnArchivo(resultado, "resultados.txt");
            break;

        case 3:
            historial.mostrar();
            break;

        case 4:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    return 0;
}