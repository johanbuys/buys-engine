#OBJS specifies which files to compile as part of the project
OBJS = src/*.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall -m64 -I include

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/debug/$(OBJ_NAME)

debug : $(OBJS)
	$(CC) $(OBJS) -g $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/debug/$(OBJ_NAME)

release : $(OBJS)
	$(CC) $(OBJS) -O3 $(COMPILER_FLAGS) $(LINKER_FLAGS) -o bin/release/$(OBJ_NAME)