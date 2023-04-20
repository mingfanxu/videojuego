import os
import sys
import glob

COMPILADOR = "g++"
SDLMING = "C:/SDL2MINGW/x86_64-w64-mingw32"

CFLAGS = '-std=c++17 -O3 -I"'+SDLMING+'/include/SDL2"'
LDFLAGSG = '-L"'+SDLMING+'/lib" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mconsole -lm'

CPP_SOURCE="main.cpp " 
cpp = glob.glob('src/**/*.cpp',recursive=True)
for a in cpp:
    CPP_SOURCE+= a+" "
CPP_SOURCE= CPP_SOURCE.replace("\\","/")
CPP_HEADERS=''

TARGET = "main.exe"

print(f"{COMPILADOR} {CFLAGS} -o {TARGET} {CPP_SOURCE} {LDFLAGSG}")
os.system(f"{COMPILADOR} {CFLAGS} -o {TARGET} {CPP_SOURCE} {LDFLAGSG}")

os.system(f"{TARGET}")