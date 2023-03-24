default:
	g++ main.cpp -o minifinity.exe -O2 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm -L C:\msys64\mingw64\ -l:bin