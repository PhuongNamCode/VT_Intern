CC = gcc
CFLAGS = -Wall -Wextra

# Tên của thư viện tĩnh
STATIC_LIB = libmylib.a
# Tên của thư viện động
DYNAMIC_LIB = libmylib.so

# Đường dẫn và tên file nguồn
SOURCE = mylib.c
# Tên file đối tượng
OBJECT = mylib.o

all: static dynamic

static: $(OBJECT)
	ar rcs $(STATIC_LIB) $(OBJECT)

dynamic: $(OBJECT)
	$(CC) -shared -o $(DYNAMIC_LIB) $(OBJECT)

$(OBJECT): $(SOURCE)
	$(CC) $(CFLAGS) -c $(SOURCE)

clean:
	rm -f $(OBJECT) $(STATIC_LIB) $(DYNAMIC_LIB)