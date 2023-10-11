CXX=g++
CFLAGS=-I. -Wall -g
TARGET=Main
SRCS=Main.cpp tile.cpp Trap.cpp ReclaimTrap.cpp WoundTrap.cpp emptyLair.cpp Lair.cpp HorizontalHero.cpp ReverseHero.cpp Hero.cpp StoryTeller.cpp ResearchLab.cpp Bank.cpp Facility.cpp Menu.cpp Engine.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
	clear
