#CXX := g++

CXX := clang

CXX_FLAGS := -std=c++17 -Wall

CXX_LIB := -fPIC

CXX_SO := -shared

OPTIMIZE := -g3

LINK := -lstdc++

EX := .so

release: main.o
	 #$(CXX) $(CXX_FLAGS) $(OPTIMIZE) -Wl,-rpath,./ -L./ -I./ main.o -o dimarraytest -ldimarray.so.1.0
	 $(CXX) $(CXX_FLAGS) $(OPTIMIZE) -Wl,-rpath,./ -L./ -I./ main.o libdimarray.so -o dimarraytest $(LINK)

main.o: lib
	$(CXX) -c $(CXX_FLAGS) $(OPTIMIZE) main.cpp -o main.o

lib.o:
	$(CXX) -c $(CXX_FLAGS) $(CXX_LIB) $(OPTIMIZE) dimarray.cpp -o dimarray.o

lib: lib.o
	$(CXX) $(CXX_FLAGS) $(CXX_SO) $(OPTIMIZE) dimarray.o -o libdimarray$(EX)

clean:
	-rm *.o
	-rm *so

