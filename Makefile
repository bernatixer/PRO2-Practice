OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized  -Wno-sign-compare -std=c++0x

program.exe: program.o Especie.o Poblacio.o Individu.o ParCrom.o ArbreGen.o
	g++ -o program.exe program.o Especie.o Poblacio.o Individu.o ParCrom.o ArbreGen.o

ArbreGen.o: ArbreGen.cc ArbreGen.hh
	g++ -c ArbreGen.cc $(OPCIONS)

ParCrom.o: ParCrom.cc ParCrom.hh
	g++ -c ParCrom.cc $(OPCIONS)

Individu.o: Individu.cc Individu.hh
	g++ -c Individu.cc $(OPCIONS)

Poblacio.o: Poblacio.cc Poblacio.hh
	g++ -c Poblacio.cc $(OPCIONS)

Especie.o: Especie.cc Especie.hh
	g++ -c Especie.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.gch
