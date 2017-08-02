XX = g++

EXE = main

OBJ = call_python.o

PYTHON_INCLUDE_PATH=/usr/include/python2.7
PYTHON_LD_LIBRARY_PATH=/usr/lib

COMMON = -I./ \
         -I$(PYTHON_INCLUDE_PATH)

CFLAGS = -g -std=c++11

LDFLAGS = -L./ \
          -L$(PYTHON_LD_LIBRARY_PATH) \
		  -lpython2.7


all: $(EXE)
	@echo ------------ DONE FOR ALL --------------

$(EXE): $(OBJ)
	g++ $(COMMON) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(EXE) main.cc

%.o: %.cc
	g++ $(COMMON) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXE) $(OBJ)
