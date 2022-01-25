# Macro definitions for "standard" language compilations
CPPFLAGS=-g -DDEBUG

.SUFFIXES: .cpp .c .h .o
.c.o: ; gcc $(CPPFLAGS) -c $*.c
.cpp.o: ; g++ $(CPPFLAGS) -c $*.cpp

# Targets

# all:
# clean:
