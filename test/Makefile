CC = gcc
CFLAGS = -Wall
LDFLAGS = -L"/home/phuongnam/Desktop/VT_Intern/test/obj" -lmylib
SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
EXECUTABLE = $(BINDIR)/program

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) obj/libmylib.a
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)
obj/libmylib.a: obj/mylib.o
	ar rcs obj/libmylib.a obj/mylib.o
clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE) obj/libmylib.a