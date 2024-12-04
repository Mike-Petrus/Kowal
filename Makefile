OBJS = main.cpp src/Core/Engine.cpp src/Input/Input.cpp src/Timer/Timer.cpp src/Ships/Kowal/Kowal.cpp src/Weapons/Weapon.cpp \
src/Weapons/Cannon/Cannon.cpp src/Projectiles/Bullet/Bullet.cpp

CC = g++

COMPILER_FLAGS = -Wall

LINKER_FLAGS = -lSDL2 -lSDL2_image

OBJ_NAME = Kowal

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -f Kowal Kowal.o *o
