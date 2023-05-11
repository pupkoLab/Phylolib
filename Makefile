CC := g++
CFLAGS := -g -std=c++11
PROJDIRS := src

SRCFILES := $(wildcard $(PROJDIRS)/*.cpp)
OBJFILES := $(patsubst %.cpp,%.o,$(SRCFILES))


$(info	VAR is $(OBJFILES))


all: phylolib.a


phylolib.a: $(OBJFILES)
	ar rvs phylolib.a $?


%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@