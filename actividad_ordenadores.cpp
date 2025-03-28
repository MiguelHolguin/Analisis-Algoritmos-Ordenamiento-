#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Función de intercambio: Intercambia dos valores de enteros usando punteros
void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Algoritmo de Burbuja: Ordena comparando elementos adyacentes y moviendolos
void ordenamientoBurbuja(int s[], int n) {
    // Recorre el arreglo n-1 veces
    for (int i = 0; i < n - 1; i++) {
        // Compara y mueve elementos adyacentes en cada pasada
        for (int j = 0; j < n - i - 1; j++) {
            // Si el elemento actual es mayor que el siguiente, los intercambia
            if (s[j] > s[j+1]) {
                intercambiar(&s[j], &s[j+1]);
            }
        }
    }
}

// Función auxiliar de Mezcla: Combina dos subarreglos ordenados
void mezcla(int s[], int inicio, int medio, int fin) {
    // Calcula tamaños de los subarreglos
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    // Crea arreglos temporales para los subarreglos
    int *izq = new int[n1];
    int *der = new int[n2];

    // Copia datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        izq[i] = s[inicio + i];
    for (int j = 0; j < n2; j++)
        der[j] = s[medio + 1 + j];

    // Indices para recorrer los arreglos
    int i = 0, j = 0, k = inicio;

    // Mezcla los subarreglos de manera ordenada
    while (i < n1 && j < n2) {
        if (izq[i] <= der[j]) {
            s[k] = izq[i];
            i++;
        } else {
            s[k] = der[j];
            j++;
        }
        k++;
    }

    // Copia elementos restantes de izq, si los hay
    while (i < n1) {
        s[k] = izq[i];
        i++;
        k++;
    }

    // Copia elementos restantes de der, si los hay
    while (j < n2) {
        s[k] = der[j];
        j++;
        k++;
    }

    // Libera memoria de arreglos temporales
    delete[] izq;
    delete[] der;
}

// Algoritmo de Mezcla (Merge Sort): Ordena dividiendo y combinando
void ordenamientoMezcla(int s[], int n) {
    // Recorre el arreglo con tamaños de subarreglo crecientes
    for (int tam = 1; tam < n; tam *= 2) {
        for (int inicio = 0; inicio < n - 1; inicio += 2 * tam) {
            // Calcula indices medios y finales de los subarreglos
            int medio = min(inicio + tam - 1, n - 1);
            int fin = min(inicio + 2 * tam - 1, n - 1);
            // Combina los subarreglos
            mezcla(s, inicio, medio, fin);
        }
    }
}

// Función de partición para Quicksort: Selecciona un pivote y lo coloca en su posición
int particion(int arr[], int inicio, int fin) {
    // Elige el último elemento como pivote
    int pivote = arr[fin];
    int i = (inicio - 1);

    // Recorre el subarreglo y mueve elementos menores que el pivote
    for (int j = inicio; j <= fin - 1; j++) {
        if (arr[j] <= pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    // Coloca el pivote en su posición correcta
    intercambiar(&arr[i + 1], &arr[fin]);
    return (i + 1);
}

// Algoritmo Rápido (Quicksort): Ordena recursivamente usando partición
void ordenamientoRapido(int arr[], int inicio, int fin) {
    // Condición de parada para recursividad
    if (inicio < fin) {
        // Obtiene el índice de partición
        int pi = particion(arr, inicio, fin);

        // Ordena recursivamente las dos mitades
        ordenamientoRapido(arr, inicio, pi - 1);
        ordenamientoRapido(arr, pi + 1, fin);
    }
}

// Algoritmo Shell: Mejora del algoritmo de inserción
void ordenamientoShell(int a[], int n) {
    // Reduce el intervalo de comparación progresivamente
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Realiza ordenamiento por inserción para cada intervalo
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            // Mueve elementos hasta encontrar la posición correcta
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}

// Función auxiliar de Monticulos (Heap Sort): Mantiene la propiedad de montículo
void monticulo(int s[], int i, int n) {
    int mayor = i;
    int izquierdo = 2 * i + 1;
    int derecho = 2 * i + 2;

    // Encuentra el mayor entre raíz, hijo izquierdo y derecho
    if (izquierdo < n && s[izquierdo] > s[mayor])
        mayor = izquierdo;

    if (derecho < n && s[derecho] > s[mayor])
        mayor = derecho;

    // Si el mayor no es la raíz, intercambia y reordena el subárbol
    if (mayor != i) {
        intercambiar(&s[i], &s[mayor]);
        monticulo(s, mayor, n);
    }
}

// Algoritmo de Monticulos (Heap Sort): Ordena usando un árbol de montículos
void ordenamientoMonticulos(int s[], int n) {
    // Construye un montículo (reordena el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--)
        monticulo(s, i, n);

    // Extrae elementos del montículo uno por uno
    for (int i = n - 1; i > 0; i--) {
        intercambiar(&s[0], &s[i]);
        monticulo(s, 0, i);
    }
}

// Algoritmo de Selección: Encuentra el mínimo en cada pasada
void ordenamientoSeleccion(int arreglo[], int n) {
    // Recorre todo el arreglo
    for (int i = 0; i < n - 1; i++) {
        // Encuentra el índice del elemento mínimo
        int indiceMinimo = i;
        for (int j = i + 1; j < n; j++) {
            if (arreglo[j] < arreglo[indiceMinimo]) {
                indiceMinimo = j;
            }
        }

        // Intercambia el elemento mínimo con el primer elemento no ordenado
        if (indiceMinimo != i) {
            intercambiar(&arreglo[i], &arreglo[indiceMinimo]);
        }
    }
}

// Función para escribir resultados en un archivo CSV
void escribirCSV(const vector<vector<long long>>& tiempos, int num_algoritmos, int num_pruebas) {
    // Abre el archivo de salida
    ofstream archivo("tiempo_ordenamiento.csv");
    if (!archivo) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }

    // Escribe encabezados de columnas
    archivo << "Prueba,Burbuja,Mezcla,Rapido,Shell,Monticulos,Seleccion\n";

    // Escribe tiempos de cada prueba
    for (int i = 0; i < num_pruebas; i++) {
        archivo << (i + 1); // Número de prueba
        for (int j = 0; j < num_algoritmos; j++) {
            archivo << "," << tiempos[j][i];
        }
        archivo << "\n";
    }

    // Calcula y escribe promedios
    archivo << "Promedio";
    for (int j = 0; j < num_algoritmos; j++) {
        long long suma = 0;
        for (int i = 0; i < num_pruebas; i++) {
            suma += tiempos[j][i];
        }
        archivo << "," << (suma / num_pruebas);
    }
    archivo << "\n";

    archivo.close();
}

// Función principal: Punto de entrada del programa
int main() {
    // Inicializa generador de números aleatorios
    srand(time(NULL));

    // Variables para tamaño del arreglo y número de pruebas
    int n, num_pruebas = 1000;

    // Solicita al usuario el número de elementos
    cout << "Ingrese el numero de elementos a ordenar: ";
    cin >> n;
    cout << "Ahora generaremos mils listas con elementos ordenamos aleatorioamente y que seran reordenamos utilizando distintos metodos de organizacion.\n ";

    // Vector para almacenar tiempos de cada algoritmo
    vector<vector<long long>> tiempos(6, vector<long long>(num_pruebas, 0));

    // Realiza múltiples pruebas de rendimiento
    for (int k = 0; k < num_pruebas; k++) {
        // Crea un arreglo base aleatorio
        int *arr_base = new int[n];
        for (int i = 0; i < n; i++) {
            arr_base[i] = 1 + rand() % 1000;
        }

        // Crea copias del arreglo base para cada algoritmo
        int *arr_burbuja    = new int[n];
        int *arr_mezcla     = new int[n];
        int *arr_rapido     = new int[n];
        int *arr_shell      = new int[n];
        int *arr_monticulos = new int[n];
        int *arr_seleccion  = new int[n];

        // Copia el arreglo base a cada copia
        copy(arr_base, arr_base + n, arr_burbuja);
        copy(arr_base, arr_base + n, arr_mezcla);
        copy(arr_base, arr_base + n, arr_rapido);
        copy(arr_base, arr_base + n, arr_shell);
        copy(arr_base, arr_base + n, arr_monticulos);
        copy(arr_base, arr_base + n, arr_seleccion);

        // Medir tiempo para Burbuja
        auto inicio = chrono::steady_clock::now();
        ordenamientoBurbuja(arr_burbuja, n);
        auto fin = chrono::steady_clock::now();
        tiempos[0][k] = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

        // Medir tiempo para Mezcla
        inicio = chrono::steady_clock::now();
        ordenamientoMezcla(arr_mezcla, n);
        fin = chrono::steady_clock::now();
        tiempos[1][k] = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

        // Medir tiempo para Rápido
        inicio = chrono::steady_clock::now();
        ordenamientoRapido(arr_rapido, 0, n - 1);
        fin = chrono::steady_clock::now();
        tiempos[2][k] = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

        // Medir tiempo para Shell
        inicio = chrono::steady_clock::now();
        ordenamientoShell(arr_shell, n);
        fin = chrono::steady_clock::now();
        tiempos[3][k] = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

        // Medir tiempo para Montículos
        inicio = chrono::steady_clock::now();
        ordenamientoMonticulos(arr_monticulos, n);
        fin = chrono::steady_clock::now();
        tiempos[4][k] = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

        // Medir tiempo para Selección
        inicio = chrono::steady_clock::now();
        ordenamientoSeleccion(arr_seleccion, n);
        fin = chrono::steady_clock::now();
        tiempos[5][k] = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

        // Liberar memoria correctamente
        delete[] arr_base;
        delete[] arr_burbuja;
        delete[] arr_mezcla;
        delete[] arr_rapido;
        delete[] arr_shell;
        delete[] arr_monticulos;
        delete[] arr_seleccion;
    }

    // Escribir resultados en CSV
    escribirCSV(tiempos, 6, num_pruebas);
    cout << "Archivo CSV generado exitosamente con los tiempos de ejecucion tomados en nanosegundos en el directorio de trabajo actual, donde se ejecuta el programa(nombre del archivo:timepo_ordenamiento).\n";

    return 0;
}
