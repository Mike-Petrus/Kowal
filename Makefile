OBJS = main.cpp

CC = g++

COMPILER_FLAGS = -Wall

OBJ_NAME = Kowal

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -f Kowal Kowal.o *o
