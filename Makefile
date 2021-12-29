CFLAGS = -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

LFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

a.exe: build
	g++ -o StickRun.exe main.o olcPixelGameEngine.o player.o game.o enemyBox.o scoreSystem.o $(CFLAGS)
a.out: build
	g++ -o StickRun.out main.o olcPixelGameEngine.o player.o game.o enemyBox.o scoreSystem.o $(LFLAGS)
run: a.exe
	./StickRun.exe
run-linux: a.out
	./StickRun.out
	
main.o: main.cpp olcPixelGameEngine.cpp olcPixelGameEngine.h game.cpp game.h
	g++ -c main.cpp

olcPixelGameEngine.o: olcPixelGameEngine.cpp olcPixelGameEngine.h
	g++ -c olcPixelGameEngine.cpp

game.o: game.h game.cpp player.h player.cpp olcPixelGameEngine.h enemyBox.h enemyBox.cpp scoreSystem.h scoreSystem.cpp
	g++ -c game.cpp

player.o: player.h player.cpp
	g++ -c player.cpp

enemyBox.o: enemyBox.h enemyBox.cpp
	g++ -c enemyBox.cpp
scoreSystem.o: scoreSystem.h scoreSystem.cpp
	g++ -c scoreSystem.cpp

build: main.o olcPixelGameEngine.o game.o player.o enemyBox.o scoreSystem.o

clean:
	-del *.o
	-rm *.o
