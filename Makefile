# Makefile for zex


hello: bin types.o zexsi.o responser.o serv.o help.o
	g++ -o bin/zexsi bin/zexsi.o bin/types.o bin/responser.o bin/serv.o bin/help.o

bin: 
	mkdir bin

zexsi.o: src/zexsi.cpp
	g++ -c src/zexsi.cpp -o bin/zexsi.o -lstdc++


types.o: src/types.cpp
	g++ -c src/types.cpp -o bin/types.o

responser.o: src/responser.cpp
	g++ -c src/responser.cpp -o bin/responser.o


serv.o: src/serv.cpp
	g++ -c src/serv.cpp -o bin/serv.o

help.o: src/help.cpp
	g++ -c src/help.cpp	-o bin/help.o



clear: 
	rm -f bin/*.o bin/zexsi
