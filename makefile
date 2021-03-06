CC=g++
CFLAGS=-c -DLINUX -I. -LSDL/lib
LDFLAGS=-lSDL -lSDL_gfx -lSDL_ttf
SOURCES=Main.cpp Game.cpp Board.cpp IO.cpp Pieces.cpp Start_menu.cpp Pause_menu.cpp Options_menu.cpp Difficulty.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tetris

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)
