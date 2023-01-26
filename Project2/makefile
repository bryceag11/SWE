HEADERS = autocomplete.h SortingList.h term.h magicString.h
SOURCES = $(HEADERS:.h=.cpp)
OBJECTS = $(HEADERS:.h=.o)
MAINSOURCE = main.cpp
MAINOBJ = $(MAINSOURCE:.cpp=.o)
EXEC = Project2
$(EXEC): $(OBJECTS) $(MAINOBJ)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o
	rm -i `find ./ -type f -executable`
