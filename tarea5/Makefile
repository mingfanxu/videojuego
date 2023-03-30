COMPILADOR=g++
LIBRERIAS_PATH = C:\SDL2MINGW\x86_64-w64-mingw32

SRC =src

CFLAGS = -std=c++17 -02 -I$(LIBRERIAS_PATH)/include/SDL2

LFLAGS = -L$(LIBRERIAS_PATH)/lib -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2 -lSDL2_ttf

TARGET = main

CPP_SOURCE =$(wildcard *.cpp) $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/*/*.cpp)
CPP_HEADERS=$(wildcard *.cpp) $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/*/*.cpp)

$(TARGET): $(CPP_SOURCE) $(CPP_HEADERS)
$(COMPILADOR) $(CFLAGS) -o $(TARGET) $(CPP_SOURCE) $(LDFLAGS)

clean:
rm -f $(TARGET)