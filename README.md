[tiempo_ordenamiento.csv](https://github.com/user-attachments/files/19500157/tiempo_ordenamiento.csv)# Analisis-Algoritmos-Ordenamiento-
Tarea para la materia de matemáticas discretas en la que se comparan distintos métodos de ordenamiento.
# Análisis Comparativo de Algoritmos de Ordenamiento

## Descripción General del Proyecto
Este proyecto implementa y compara el rendimiento de seis algoritmos de ordenamiento clásicos, midiendo su eficiencia computacional a través de múltiples métricas de tiempo de ejecución.

## Requisitos del Sistema
### Hardware
- Procesador: Intel de doble núcleo
- Memoria RAM: 16 GB
- Disco duro:  256 GB

### Software
- Compilador de C++: 
  - Code::Blocks
- Sistema Operativo:
  - Windows 10/11

## Algoritmos de Ordenamiento Implementados

### 1. Burbuja (Bubble Sort)
- **Complejidad Temporal**: O(n²)
- **Descripción**: Compara elementos adyacentes y los intercambia si están en el orden incorrecto
- **Características**:
  - Simple de implementar
  - Ineficiente para grandes conjuntos de datos
  - Estable y en el lugar

### 2. Mezcla (Merge Sort)
- **Complejidad Temporal**: O(n log n)
- **Descripción**: Divide el arreglo en mitades, ordena recursivamente y luego combina
- **Características**:
  - Algoritmo de división y conquista
  - Estable y predecible
  - Requiere espacio adicional O(n)

### 3. Rápido (Quick Sort)
- **Complejidad Temporal**: O(n log n) promedio, O(n²) peor caso
- **Descripción**: Selecciona un pivote y particiona el arreglo a su alrededor
- **Características**:
  - Muy eficiente en la práctica
  - Rápido para conjuntos de datos grandes
  - Inestable

### 4. Shell
- **Complejidad Temporal**: Entre O(n log n) y O(n²)
- **Descripción**: Mejora del ordenamiento por inserción usando intervalos variables
- **Características**:
  - Eficiente para tamaños medianos de datos
  - Menos overhead que Quicksort
  - Adaptativo

### 5. Montículos (Heap Sort)
- **Complejidad Temporal**: O(n log n)
- **Descripción**: Transforma el arreglo en un montículo binario y extrae elementos
- **Características**:
  - Rendimiento consistente
  - No requiere memoria adicional
  - Inestable

### 6. Selección (Selection Sort)
- **Complejidad Temporal**: O(n²)
- **Descripción**: Encuentra el mínimo en cada pasada y lo coloca en su posición
- **Características**:
  - Simple de entender
  - Ineficiente para grandes conjuntos
  - Realiza pocos intercambios

## Análisis de Resultados
Se pueden observar patrones de consistencia en las iteraciones de medición de tiempo, lo que sugiere que el proceso de evaluación no introduce una sobrecarga significativa en el rendimiento de los algoritmos de ordenamiento

### Factores Analizados
- Tiempo de ejecución en nanosegundos
- Comportamiento con diferentes tamaños de entrada
- Variabilidad en múltiples ejecuciones

### Observaciones Experimentales
1. **Algoritmos O(n²)** (Burbuja, Selección) muestran degradación significativa con conjuntos grandes
2. **Algoritmos O(n log n)** (Mezcla, Rápido, Montículos) mantienen rendimiento estable
3. **Shell Sort** muestra un comportamiento intermedio, eficiente para datos medianos

## Conclusiones

1. **Quicksort** y **Merge Sort** son generalmente los más eficientes para conjuntos de datos grandes
2. **Bubble Sort** y **Selection Sort** son adecuados solo para conjuntos pequeños
3. La elección del algoritmo depende de:
   - Tamaño del conjunto de datos
   - Característica de los datos (parcialmente ordenados, aleatorios)
   - Restricciones de memoria
   - Requisitos de estabilidad

## Recomendaciones
- Para grandes volúmenes: Quicksort o Merge Sort
- Para memoria limitada: Heap Sort
- Para datos casi ordenados: Shell Sort
- Para conjuntos muy pequeños: Insertion Sort

## Autores
Miguel Angel Nuñez Holguin
