# VRPB Solver

Este proyecto implementa un solucionador para el **Vehicle Routing Problem with Backhauls (VRPB)** utilizando C++. El objetivo es encontrar rutas óptimas para vehículos que deben realizar entregas y recogidas, minimizando la distancia total recorrida.

## Estructura del proyecto

- `src/`  
  Contiene el código fuente principal (`main.cpp`, `headers.hpp`, etc.).
- `output/`  
  Carpeta donde se genera el ejecutable.

## Compilación

Para compilar el proyecto, usa el siguiente comando en la terminal:

```sh
g++ ./workspace/src/main.cpp ./workspace/src/headers.hpp -o ./workspace/output/VRPB_Solver -Wall -Wextra
```

Asegúrate de tener instalado un compilador de C++ (como `g++`).

## Uso

Ejecuta el programa compilado desde la carpeta `output`:

```sh
./VRPB_Solver
```

## Dependencias

- C++11 o superior
- No se requieren bibliotecas externas

## Contribución

Si deseas contribuir, por favor crea un fork del repositorio y envía un pull request.

## Licencia

Este proyecto está bajo la licencia MIT.