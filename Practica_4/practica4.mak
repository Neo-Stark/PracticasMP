#Archivo: practica4.mak
#Uso: Mantiene la dependencia entre los ficheros de la practica4.

all: bin/01_RedimensionaArrayDinamico bin/02_Calificaciones_ArrayDinamicoStruct_ordenado

bin/01_RedimensionaArrayDinamico: src/01_RedimensionarArrayDinamico.cpp
	g++ src/01_RedimensionarArrayDinamico.cpp -o bin/01_RedimensionaArrayDinamico

bin/02_Calificaciones_ArrayDinamicoStruct_ordenado: obj/02_Calificaciones_ArrayDinamicoStruct_ordenado.o obj/RegAlumno.o
	g++  obj/02_Calificaciones_ArrayDinamicoStruct_ordenado.o obj/RegAlumno.o -o bin/02_Calificaciones_ArrayDinamicoStruct_ordenado

obj/02_Calificaciones_ArrayDinamicoStruct_ordenado.o: src/02_Calificaciones_ArrayDinamicoStruct_ordenado.cpp
	g++ -c src/02_Calificaciones_ArrayDinamicoStruct_ordenado.cpp -o obj/02_Calificaciones_ArrayDinamicoStruct_ordenado.o -Iinclude

obj/RegAlumno.o: src/RegAlumno.cpp
	g++ -c src/RegAlumno.cpp -o obj/RegAlumno.o -Iinclude

clean:
	rm bin/* obj/*