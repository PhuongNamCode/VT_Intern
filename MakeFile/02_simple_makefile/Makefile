CC=gcc # Nếu muốn thay đổi trình biên dịch thì chỉ cần thay đổi ở đây, đây là công dụng của các biến môi trường 
INCDIRS=-I.
OPT=-O0
CFLAGS=-g $(INCDIRS) $(OPT)

CFILES=x.c y.c
OBJECTS=x.o y.o

BINARY=bin

all: $(BINARY)


$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^
# bin: x.o y.o
# 	gcc -o bin x.o y.o  
# ./bin for exacute the results 
# regular expression where % is a wildcard 
# $@ lấy những gì của %.o pass vô đây vào $^ lấy những gì của %.c pass vô đây 
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^ 
clean:
	rm -rf $(BINARY) $(OBJECTS)
