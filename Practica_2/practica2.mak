#Archivo: practica2.mak
#Uso: Mantiene la dependencia entre los ficheros de la practica2.

all: bin/PosicionPrimerBlanco bin/SaltaPrimeraPalabra bin/DemosCadenasClasicas

bin/PosicionPrimerBlanco: obj/PosicionPrimerBlanco.o
	g++ obj/PosicionPrimerBlanco.o -o bin/PosicionPrimerBlanco

bin/SaltaPrimeraPalabra: obj/SaltaPrimeraPalabra.o
	g++ obj/SaltaPrimeraPalabra.o -o bin/SaltaPrimeraPalabra

bin/DemosCadenasClasicas: obj/DemosCadenasClasicas.o obj/MiCadenaClasica.o
	g++ $^ -o bin/DemosCadenasClasicas

obj/$.o: src/$.cpp
	g++ -c src/$.cpp -Iinclude -o obj/$.o

mrproper: 
	rm bin/* obj/*.o
