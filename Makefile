CFLAGS = -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

a.exe: olcExampleProgram.cpp olcPixelGameEngine.h
	g++ -o olcExampleProgram.exe olcExampleProgram.cpp $(CFLAGS)