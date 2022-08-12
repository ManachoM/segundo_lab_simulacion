CXX = g++
LIBRARY=-L/usr/local/include/libcppsim
INCLUDE=-I/usr/local/include/libcppsim
CXXFLAGS = -std=c++14 -O3 -Wall -w -lm -g -lcppsim $(INCLUDE) $(LIBRARY)

main: Agricultor.o Feriante.o Evento.o Stock.o
	$(CXX) -o main src/main.cc  $(wildcard obj/*.o) $(CXXFLAGS)
 
Agricultor.o: Feriante.o Evento.o Stock.o
	$(CXX)  -c -o obj/Agricultor.o src/Agricultor.cc $(CXXFLAGS)

Feriante.o:
	$(CXX) -c -o obj/Feriante.o src/Feriante.cc  $(CXXFLAGS)

Evento.o:
	$(CXX)  -c -o obj/Evento.o src/Evento.cc $(CXXFLAGS)

Stock.o:
	$(CXX) -c -o obj/Stock.o src/Stock.cc $(CXXFLAGS)


