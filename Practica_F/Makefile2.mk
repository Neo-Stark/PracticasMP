bin/Matrizdispersa.exe : obj/MatrizDispersa.o obj/principal.o
	g++ obj/MatrizDispersa.o obj/principal.o -o bin/Matrizdispersa.exe

obj/MatrizDispersa.o: src/MatrizDispersa.cpp
	g++ -c src/MatrizDispersa.cpp -o obj/MatrizDispersa.o -Iinclude 

obj/principal.o: src/principal.cpp 
	g++ -c src/principal.cpp -o obj/principal.o -Iinclude

clean:
	rm bin/* obj/*