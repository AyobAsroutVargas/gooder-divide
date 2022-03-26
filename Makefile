CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
DEPS =  divide.h solucion.h problema.h mergeSort.h vectorProblem.h vectorSolucion.h generator.h QuickSort.h
OBJ = main.o problema.o solucion.o divide.o mergeSort.o vectorProblem.o vectorSolucion.o generator.o QuickSort.o

%.o: %.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean
clean:
	rm main *.o