CC = clang++
SRC = src/*.cpp
EXEC = pong
FLAGS = -g -c -Wall -std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

pong: $(SRC)
	@echo "Compiling....."
	@echo " "
	$(CC) $(FLAGS) $(INCLUDE) $(SRC)
	mkdir obj/
	mv *.o obj
	@echo " "
	@echo "Linking....."
	@echo " "
	$(CC) obj/*.o $(LIBS) -o $(EXEC)

clean:
	@echo "cleaning..."
	@echo " "
	rm obj/*.o
	rm $(EXEC)
