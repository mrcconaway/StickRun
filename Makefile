CFLAGS = -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

LFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

a.exe: 
	g++ -o test.exe *.cpp $(CFLAGS)
a.out: 
	g++ -o test.out *.cpp $(LFLAGS)

clean:
	-del *.o
	-del test.exe
	-rm *.o
	-rm test.out
