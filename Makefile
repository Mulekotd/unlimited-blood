build:
	g++ -I src/include -L src/lib -o "unlimited_blood" main.cpp src/*.cpp -lmingw32 -lSDL2main -lSDL2 -mwindows