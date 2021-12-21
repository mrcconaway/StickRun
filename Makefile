$(CLFAGS)= -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

test.exe: main.cpp game.h game.cpp
	g++ *.cpp $(CLFAGS)