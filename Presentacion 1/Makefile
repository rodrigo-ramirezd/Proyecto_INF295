# Nombre del programa ejecutable de salida
TARGET = VRPB_Solver

# Archivos fuente del proyecto
SRCS = ./workspace/src/main.cpp ./workspace/src/functions.cpp

# Directorio de la salida (ejecutable)
OUTPUTDIR = ./workspace/output

# Compilador C++
CXX = g++ -g -std=c++17

# Opciones de compilación (warnings, estándares, depuración)
CXXFLAGS = -Wall -Wextra

# Objeto de salida completo
EXE = $(OUTPUTDIR)/$(TARGET)

.PHONY: all clean run

# Regla por defecto: compila el programa
all: $(EXE)

$(EXE): $(SRCS)
	$(CXX) $(SRCS) -o $(EXE) $(CXXFLAGS)

# Regla para ejecutar el programa
# Anteponer "gdb" para depuración
run: $(EXE)
	$(EXE)

# Regla para limpiar los archivos compilados
clean:
	rm -f $(EXE)
