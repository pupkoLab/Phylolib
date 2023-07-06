CC := g++
CFLAGS := -g -std=c++11
SRCDIR := src/
OBJDIR := build/
TARGET := lib/phylolib.a


SRCFILES := $(patsubst $(SRCDIR)%.cpp,%.cpp, $(wildcard $(SRCDIR)*.cpp))
OBJFILES := $(patsubst %.cpp,$(OBJDIR)%.o,$(SRCFILES))


$(info	VAR is $(OBJFILES))

all: $(TARGET)


$(TARGET): $(OBJFILES)
	ar rvs $(TARGET) $?


$(OBJDIR)%.o:  $(SRCDIR)%.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@