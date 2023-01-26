HEADERS = autocomplete.h SortingList.h term.h
SOURCES = $(HEADERS:.h=.cpp)
OBJECTS = $(HEADERS:.h=.o)
MAINSOURCE = Lab9.cpp
MAINOBJ = $(MAINSOURCE:.cpp=.o)
EXEC = Lab9
$(EXEC): $(OBJECTS) $(MAINOBJ)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o
	rm -i `find ./ -type f -executable`
