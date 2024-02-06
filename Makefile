CCC := g++
CFLAGS := -std=c++20 -O3 -Wall -Wextra -Weffc++ -Wpedantic -Weffc++ -g -fno-elide-constructors
TBBFlags :=#-ltbb -ltbbmalloc -ltbbmalloc_proxy
#CFLAGS := -std=c++20 -L/usr/local/lib -ltbb -ltbbmalloc -ltbbmalloc_proxy
SFMLFLAGS := -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

SRC := src#Source directory
BIN := bin#Output directory

#All test related files need to have the name test in them
IN_TEST_FILES := $(notdir $(wildcard $(SRC)/*test*))

#Gives the files the correct format
SRC_TEST := $(addprefix $(SRC)/,$(IN_TEST_FILES))
BIN_TEST := $(addprefix $(BIN)/,$(IN_TEST_FILES:.cc=.o))

#The files that are necessary for the game
IN_GAME_FILES := $(filter-out $(IN_TEST_FILES), $(notdir $(wildcard $(SRC)/*.cc)))

#Gives the files the correct format
SRC_GAME := $(addprefix $(SRC)/,$(IN_GAME_FILES))
BIN_GAME := $(addprefix $(BIN)/,$(IN_GAME_FILES:.cc=.o))

all: game

game: $(BIN_GAME)
	$(CCC) $(TBBFlags) $(CFLAGS) $(BIN_GAME) -o Fractals $(SFMLFLAGS)

test: $(filter-out main.cc, $(BIN_GAME)) $(BIN_TEST)
	$(CCC) $(CFLAGS) $(filter-out $(BIN)/main.o, $(BIN_GAME)) $(BIN_TEST) -o Test $(SFMLFLAGS)

#Create the compiled binary files and put them in bin/
$(BIN)/%.o: $(SRC)/%.cc
	$(CCC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_GAME) $(BIN_TEST) Fractals Test

.PHONY:
run:
	./Fractals

.PHONY:
run_test:
	./Test

.PHONY:
run_leak:
	valgrind --tool=memcheck --leak-check=yes ./Test

# -o  is a g++ flag for setting the name of the output file.
#
# -c  is a g++ flag that creates binary files but does not link them together.
#
# $<  is a makefile placeholder for the input file name. That is the one that
#     the one that needs to be compiled.
#
# $@  is a makefile placeholder for the output file name. That is the one that
#     we want to make.
#
# OBS!!: The comments on lines 5-6 have to be directly after the directories.

