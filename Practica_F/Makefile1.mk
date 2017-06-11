bin/Skyline: obj/montar.o obj/Skyline.o
	g++ $^ -o bin/Skyline.exe

obj/montar.o: src/montar.cpp
	g++ -c src/montar.cpp -Iinclude -o obj/montar.o

obj/Skyline.o: src/Skyline.cpp 
	g++ -c src/Skyline.cpp -Iinclude -o obj/Skyline.o

clean:
	rm bin/* obj/*