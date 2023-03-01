COMPILADOR=g++
SDLLIB =C:\SDL2

ARCHIVOS  =$(wildcard *.cpp) $(wildcard src/*.cpp) $(wildcard /src/*/*.cpp)
CABEZERAS =$(wildcard *.Hpp) $(wildcard src/*.Hpp) $(wildcard /src/*/*.Hpp)

CFLAGS = -std=c++17 -Wunknown-warning-option -I$(SDLLIB)/SDL2
CFLAGSDEBUG = -std=c++17 -g -Wunknown-warning-option -I$(SDLLIB)/SDL2
LFLAGS = -L$ "$(SDLLIB)/lib 'pkg-config --static --libs --cflags SDL2'

PROG = inter               


$(PROG) : $(ARCHIVOS) $(CABEZERAS)
$(COMPILADOR) $(CFLAGS) $(ARCHIVOS) -O $(PROG) $(LFLAGS)

debug: $(ARCHIVOS)  $(CABEZERAS)
$(COMPILADOR) $(CFLAGS) $(ARCHIVOS) -O $(PROG) $(LFLAGS)



correr:
$(PROG)
