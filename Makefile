CFLAGS = -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

a.exe: main.o olcPixelGameEngine.o game.o
	g++ -o StickRun.exe main.o olcPixelGameEngine.o game.o $(CFLAGS)
main.o: main.cpp olcPixelGameEngine.cpp olcPixelGameEngine.h game.cpp game.h
	g++ -c main.cpp
olcPixelGameEngine.o: olcPixelGameEngine.cpp olcPixelGameEngine.h
	g++ -c olcPixelGameEngine.cpp
game.o: game.h game.cpp 
	g++ -c game.cpp
clean:
	del *.o