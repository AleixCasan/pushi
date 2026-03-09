*Este proyecto ha sido creado como parte del currículo de 42 por smilla-c, alecasan.*

<div align="center">

# 🔀 push_swap

**Sorting stacks with the minimum number of operations.**

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42_Barcelona-black)
![Year](https://img.shields.io/badge/Year-2026-green)

</div>

---

## 📋 Descripción

**push_swap** es un proyecto de algoritmos de la escuela 42 cuyo objetivo es ordenar una pila de números enteros utilizando exclusivamente un conjunto de 11 operaciones predefinidas y una segunda pila auxiliar.

El programa recibe como argumentos una lista de números enteros y produce por `stdout` la secuencia mínima de operaciones necesaria para dejar la pila **Stack A** ordenada de menor a mayor. La salida puede ser validada por el programa `checker` incluido en el proyecto.

### Características principales

- **Cuatro estrategias de ordenación** seleccionables mediante flags (`--simple`, `--medium`, `--complex`, `--adaptive`)
- **Modo adaptativo** por defecto: elige automáticamente la estrategia óptima según el tamaño y nivel de desorden de la entrada
- **Sistema de benchmarking** (`--bench`) que mide operaciones, desorden inicial y complejidad
- Gestión robusta de errores: desbordamiento de `int`, duplicados, argumentos no numéricos, flags desconocidas
- Compatible con argumento único entre comillas: `./push_swap "3 1 2"`

### Las 11 operaciones

| Operación | Descripción |
|-----------|-------------|
| `sa` | Swap de los 2 primeros elementos de Stack A |
| `sb` | Swap de los 2 primeros elementos de Stack B |
| `ss` | `sa` y `sb` simultáneamente |
| `pa` | Push del tope de Stack B al tope de Stack A |
| `pb` | Push del tope de Stack A al tope de Stack B |
| `ra` | Rotate Stack A (el tope pasa al fondo) |
| `rb` | Rotate Stack B (el tope pasa al fondo) |
| `rr` | `ra` y `rb` simultáneamente |
| `rra` | Reverse rotate Stack A (el fondo sube al tope) |
| `rrb` | Reverse rotate Stack B (el fondo sube al tope) |
| `rrr` | `rra` y `rrb` simultáneamente |

---

## ⚙️ Instrucciones

### Compilación

```bash
make        # Compila el ejecutable push_swap
make clean  # Elimina archivos objeto
make fclean # Elimina objetos y el ejecutable
make re     # Limpia y recompila desde cero
```

### Uso básico

```bash
# Ordenar una lista de números
./push_swap 3 1 4 1 5 9 2 6

# Argumento único entre comillas
./push_swap "5 3 1 4 2"

# Seleccionar estrategia manualmente
./push_swap --simple   3 1 2
./push_swap --medium   3 1 2
./push_swap --complex  3 1 2
./push_swap --adaptive 3 1 2   # igual que sin flag

# Validar con checker
./push_swap 3 2 1 | ./checker 3 2 1
```

### Flags disponibles

```bash
--simple      # Fuerza simple_sort  → O(n²),       recomendado para n ≤ 20
--medium      # Fuerza medium_sort  → O(n√n),      recomendado para n ≤ 100
--complex     # Fuerza radix_sort   → O(n log n),  recomendado para n > 100
--adaptive    # Selección automática (comportamiento por defecto)
--bench       # Activa el sistema de benchmarking (salida por fichero .txt)
```

### Ejemplos de salida

```bash
$ ./push_swap 3 2 1
sa
rra

$ ./push_swap --bench 5 3 1 4 2
pb
pb
ra
pa
pa
[bench] disorder: 80.00%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 5
[bench] sa: 0  sb: 0  ss: 0  pa: 2  pb: 2
[bench] ra: 1  rb: 0  rr: 0  rra: 0 rrb: 0 rrr: 0
```

### Gestión de errores

El programa imprime `Error` en `stderr` y termina con código `1` ante:

- Argumentos no numéricos (`abc`, `3.5`, `1e2`)
- Argumento vacío o solo un signo (`-`, `+`)
- Números duplicados (`1 2 1`)
- Desbordamiento de `int` (`2147483648`, `-2147483649`)
- Flags desconocidas (`--foo`)

---

## 🧠 Algoritmos — Explicación y justificación

El proyecto implementa cuatro algoritmos distintos, cada uno optimizado para un rango de tamaño diferente. El modo `--adaptive` los combina automáticamente.

---

### 1. `sort_three` / `select_strategy` — 2 a 5 elementos

Para tamaños muy pequeños se usan soluciones hardcoded de coste mínimo:

- **2 elementos:** un único `sa` si están invertidos.
- **3 elementos:** se cubren las 6 permutaciones posibles con como máximo 2 operaciones (`sa`, `ra`, `rra`, o combinaciones).
- **4–5 elementos:** `sort_five` empuja los mínimos uno a uno a Stack B hasta que quedan 3 en A, aplica `sort_three`, y devuelve todo con `pa`.

**Justificación:** No tiene sentido aplicar un algoritmo general a entradas tan pequeñas. Las soluciones directas son óptimas en número de operaciones y triviales de razonar.

---

### 2. `simple_sort` — 6 a ~20 elementos · O(n²)

Variante de **selection sort** adaptada a pilas:

1. Localiza la posición del mínimo actual en Stack A.
2. Rota A hacia adelante (`ra`) o hacia atrás (`rra`) para llevar el mínimo al tope, eligiendo la dirección más corta.
3. Hace `pb` para enviarlo a Stack B.
4. Repite hasta que quedan 3 elementos, aplica `sort_three`.
5. Devuelve todos con `pa`.

**Justificación:** Para n ≤ 20 el coste de O(n²) es aceptable y el número de operaciones suele ser inferior a los otros algoritmos porque no hay overhead de normalización ni de pasadas por bits. La optimización de rotar en la dirección más corta reduce significativamente el total.

---

### 3. `medium_sort` / `chunk_sort` — 20 a ~100 elementos · O(n√n)

Algoritmo de **chunk sort** en dos fases:

**Fase 1 — Push por chunks:**  
Se divide el rango de índices normalizados `[0, n-1]` en grupos de tamaño `√n`. Para cada chunk, se recorre Stack A y se envían a Stack B los elementos cuyo índice esté en el rango `[lo, hi]` del chunk actual, rotando A cuando el elemento no corresponde al chunk. Los chunks se procesan de menor a mayor.

**Fase 2 — Reconstrucción:**  
Mientras Stack B no esté vacío, se localiza el máximo actual, se rota B para llevarlo al tope (eligiendo `rb` o `rrb` según distancia) y se hace `pa`. Como siempre se extrae el máximo y se inserta en el tope de A, al final A queda ordenado ascendentemente (el mínimo en el tope).

**Paso previo — `index_values`:**  
Antes del sort se normalizan todos los valores a sus índices en el orden ascendente (`0, 1, 2, ..., n-1`). Esto garantiza que el rango sea siempre `[0, n-1]` independientemente de los valores reales.

**Justificación:** `√n` es el tamaño de chunk que minimiza el número total de rotaciones. Con chunks más pequeños hay más pasadas; con chunks más grandes hay más rotaciones dentro de cada pasada. El punto de equilibrio es `√n`, lo que da una complejidad práctica de O(n√n) y excelentes resultados para n entre 20 y 100 (típicamente por debajo de 700 operaciones para n=100).

---

### 4. `radix_sort` — >100 elementos · O(n log n)

Implementación de **LSD Radix Sort binario** sobre índices normalizados:

Para cada bit `i` desde el menos significativo hasta el más significativo de `n-1`:
- Si el bit `i` del tope de A es `0` → `pb` (va a B)
- Si el bit `i` del tope de A es `1` → `ra` (queda en A, al fondo)
- Al terminar la pasada, se devuelve todo B a A con `pa`

Después de `⌈log₂(n)⌉` pasadas, Stack A queda ordenado.

**Justificación:** Radix sort no compara elementos entre sí: opera sobre la representación binaria de los índices. Esto lo hace ideal para n grande porque el número de operaciones es predecible: exactamente `n × ⌈log₂(n)⌉` operaciones de desplazamiento más los `pa` de vuelta. Para n=500 son aproximadamente 9 pasadas × 500 = ~4500 operaciones, bien por debajo del límite de 5500. No requiere comparaciones costosas ni estructuras auxiliares adicionales.

---

### 5. `adaptive_sort` — Selección automática

Mide el **nivel de desorden** como el porcentaje de pares de inversión respecto al total posible `n(n-1)/2`, y elige:

| Condición | Estrategia elegida |
|-----------|-------------------|
| `n ≤ 3` | `select_strategy` |
| `n > 100` | `radix_sort` |
| desorden `< 20%` | `simple_sort` |
| desorden `< 50%` | `medium_sort` |
| desorden `≥ 50%` | `radix_sort` |

**Justificación:** Ningún algoritmo es universalmente óptimo. Una entrada casi ordenada se resuelve eficientemente con selection sort (pocas rotaciones hasta el mínimo); una entrada muy desordenada se beneficia de radix (coste uniforme independiente del orden). El umbral del 50% se determinó empíricamente comparando los conteos de operaciones de ambos algoritmos en entradas sintéticas de distintos niveles de desorden.

---

## 📚 Recursos

### Documentación y referencias

- [Wikipedia — Radix Sort](https://en.wikipedia.org/wiki/Radix_sort) — Fundamentos del algoritmo de ordenación por dígitos/bits
- [Wikipedia — Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) — Comparativa de algoritmos de ordenación y sus complejidades
- [Visualgo — Sorting Visualizations](https://visualgo.net/en/sorting) — Visualización interactiva de algoritmos de ordenación
- [GeeksForGeeks — Selection Sort](https://www.geeksforgeeks.org/selection-sort/) — Base teórica de `simple_sort`
- [CP-Algorithms — Inversions](https://cp-algorithms.com/sequences/inv.html) — Cálculo del número de inversiones como medida de desorden
- [42 Docs — push_swap subject](https://cdn.intra.42.fr/pdf/pdf/134758/en.subject.pdf) — Enunciado oficial del proyecto

### Uso de IA

Durante el desarrollo de este proyecto se utilizó IA (Claude, Anthropic) como herramienta de apoyo en las siguientes tareas:

| Tarea | Descripción |
|-------|-------------|
| **Documentación** | Generación de este README a partir de la guía de evaluación interna del proyecto |
| **Revisión de lógica** | Verificación de los casos límite en `sort_three` y de la condición de dirección óptima en `rotate_to_pos` |
| **Explicación de conceptos** | Comprensión de la complejidad O(n√n) del chunk sort y de la implementación LSD de radix sort |

La IA **no fue utilizada** para escribir el código de producción del proyecto. Todo el código fuente fue escrito por los autores.

---

<div align="center">

*42 Barcelona · 2026 · smilla-c & alecasan*

</div>

```
