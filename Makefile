SMFL_PATH=/opt/homebrew/Cellar/sfml/2.5.1_1/

CFLAGS=-Wno-implicit-function-declaration -std=c++20

final: main.o Vector.o Entity.o Renderer3D.o
	g++ $(CFLAGS) main.o Vector.o Entity.o Renderer3D.o -L$(SMFL_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -o final

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp -I$(SMFL_PATH)/include

Vector.o: Vector.cpp
	g++ $(CFLAGS) -c Vector.cpp

Entity.o: Entity.cpp
	g++ $(CFLAGS) -c Entity.cpp -I$(SMFL_PATH)/include

Renderer3D.o: Renderer3D.cpp
	g++ $(CFLAGS) -c Renderer3D.cpp -I$(SMFL_PATH)/include

clean:
	rm -f *.o