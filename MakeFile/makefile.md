
# Make File
## Giới thiệu
Makefile là một công cụ quan trọng trong quá trình xây dựng phần mềm, giúp tổ chức quy trình xây dựng, quản lý các phụ thuộc, và tự động hóa công việc xây dựng, giúp tiết kiệm thời gian và đảm bảo tính nhất quán trong quá trình phát triển phần mềm.<br>
Đối với makefile mỗi lần build lại thì chỉ cần build lại những file thay đổi chính vì vật giúp tiết kiệm thời gian.
Make chứa thông tin và các command cần thực thi, thay vì gõ lệnh dài từng lần để chạy thì mình đặt cho nó cái tên cái rule rồi gọi nó ra để chạy. <br>
## Makefile Syntax
<code>
targets: prerequisites<br>
&emsp;command <br>
&emsp;command <br>
&emsp;command <br>
</code>
targets : filenames cách nhau bởi dấu cách <br>
command : chuỗi các bước thực hiện để tạo ra target(s) <br>
prerequisites : là những file cần thiết trong quá trình command thực hiện<br>
* Lưu ý : trước command là dấu Tab chứ không phải là dấu cách. <br>
Ví dụ : <br>

```
build: main.o
	gcc output/main.o -o output/Results.exe
	./output/Results.exe
main.o: source/main.c
	gcc -c source/main.c -o output/main.o
clean: 
	rm output/*
```

## Biến trong make file 
```
PRO_DIR		:= .
PROJ_NAME	:= PhuongNamCode
OUTPUT_PATH	:= $(PRO_DIR)/output
abc = 123
```
Khai báo biến giống như khai báo trong C, biến này chỉ có thể là dạng strings sử dụng := hoặc = <br>
Để hiển thị gía trị của biến sử dụng: <br>
```
@echo $($(subst print-,,$@))
```
$@ sử dụng để lấy giá trị targetnames <br>
Thay thế  print- bằng giá trị null
## Wildcards
\* và % đều được gọi trong wildcards Make nhưng chúng mang ý nghĩa khác nhau <br>
1. \* <br>
Tìm kiếm filenames phù hợp
```
# in ra thông tin của tất cả .c file
print: $(wildcard *.c)
	ls -la  $?
```  
2. % <br>
Nó có nhiều chức năng ví duj như chức năng ghép nối nhiều chuỗi thành 1 chuỗi hoặc có thể thay thế bằng 1 chuỗi khác. 
```
print-%:
	@echo $($(subst print-,,$@))
```
## Câu lệnh trong make file
Từ khóa Phony để phân biệt hành động và tên file thường đứng trước hành động ( ví dụ hành động clean thì đứng trước hành động này là 
.PHONY clean)<br>
Thêm @ vào trước lệnh thì sẽ không hiển thị thao tác của hành động đó <br>
Phép gán trong Make : <br>
+ "=" gán cố định
+ ":=" tương tự như "="
+ "+=" phép gán nối dài (append), ví dụ khi viết hai dòng
```
 CSRCS+= main.c  
 CSRCS+= sum.c   
 => CSRCS = main.c sum.c   
```
Để lấy giá trị của phép gán ta làm như sau : 
```
${TARGET}   
 hoặc  
 $(CFLAGS) 
 ```
 CFLAGS / LDFLASG
Các flags chứa các options để pass vào cho compiler.
Chú ý -DDEBUG tương ứng với define DEBUG để pass vào source code, ví dụ trong main.c ở trên.<br>
CC / CXX
Compiler để compile, trong vd này sử dụng gcc/g++ để chạy trên máy tính chứ không phải board nhúng, khi cross compiler thì bạn chỉ cần đặt đúng compiler tương ứng với platform cho board là được, ví dụ : 
```
CC=arm-linux-gcc  
CXX=arm-linux-g++  
```
Lệnh shell: Lệnh Shell được đưa vào trong cặp khóa $( ) như dưới đây: <br>
```
OBJS:= $(patsubst %.cpp, $(OBJSDIR)/%.o, $(CPPSRCS))   
mkdir -p $(shell dirname $@)   
 ```
![Macro MakeFile](image1.png)
[Link tham khảo](https://eslinuxprogramming.blogspot.com/2015/04/gnu-make.html)

## Thành phần trong MakeFile 
Makefile có chứa 5 thành phần :

    Các Rule rõ ràng, tường mình (explicit rules).
    Cách Rule không rõ ràng (implicit rules).
    Các biến được định nghĩa (variable definition).
    Các chỉ thị (directive).
    Các comment (bắt đầu bằng dấu # )
Implicit Rules

    Compiling a C program: n.o is made automatically from n.c with a command of the form $(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@
    Compiling a C++ program: n.o is made automatically from n.cc or n.cpp with a command of the form $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
    Linking a single object file: n is made automatically from n.o by running the command $(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@
Các biến quan trọng sử dụng trong Implicit Rules : 

    CC: Program for compiling C programs; default cc
    CXX: Program for compiling C++ programs; default g++
    CFLAGS: Extra flags to give to the C compiler
    CXXFLAGS: Extra flags to give to the C++ compiler
    CPPFLAGS: Extra flags to give to the C preprocessor
    LDFLAGS: Extra flags to give to compilers when they are supposed to invoke the linker
Ghi vào file khác trong makefile sử dụng ">" : <br>
```
echo "int main() { return 0; }" > blah.c
```
## Static Pattern Rules
Quy tắc này là một cách khác để viết ít hơn trong makefile có cú pháp như sau : 
```
targets...: target-pattern: prereq-patterns ...
   commands
```
Ví dụ sau là một ví dụ biên dịch file .c thành file .o theo một cách thủ công : 
```
objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
foo.o: foo.c
bar.o: bar.c
all.o: all.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all
```
Còn đây là cách hiệu quả hơn sử dụng static pattern rule :
```
objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
# Syntax - targets ...: target-pattern: prereq-patterns ...
# In the case of the first target, foo.o, the target-pattern matches foo.o and sets the "stem" to be "foo".
# It then replaces the '%' in prereq-patterns with that stem
$(objects): %.o: %.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all
```
% .c ý nghĩa là lần lượt tìm kiếm các file .c để biên dịch thành các file .o

## Static Pattern Rules và Filter

```
obj_files = foo.result bar.o lose.o
src_files = foo.raw bar.c lose.c

all: $(obj_files)
# Note: PHONY is important here. Without it, implicit rules will try to build the executable "all", since the prereqs are ".o" files.
.PHONY: all 

# Ex 1: .o files depend on .c files. Though we don't actually make the .o file.
$(filter %.o,$(obj_files)): %.o: %.c
	echo "target: $@ prereq: $<"

# Ex 2: .result files depend on .raw files. Though we don't actually make the .result file.
$(filter %.result,$(obj_files)): %.result: %.raw
	echo "target: $@ prereq: $<" 

%.c %.raw:
	touch $@

clean:
	rm -f $(src_files)
```
Sử dụng để lọc các tên file có đuôi theo yêu cầu.

## Double-Colon Rules
Quy tắc 2 Dấu hai chấm hiếm khi được sử dụng nhưng cho phép xác định nhiều quy tắc cho cùng một mục tiêu.  Nếu đây là những dấu hai chấm đơn, một cảnh báo sẽ được in ra và chỉ bộ lệnh thứ hai sẽ chạy.<br>
Ví dụ : <br>
```
all: blah

blah::
	echo "hello"

blah::
	echo "hello again"
```
## Đệ quy sử dụng make 
Việc sử dụng đệ quy make có nghĩa là sử dụng make như một lệnh trong tệp thực hiện.  Kỹ thuật này rất hữu ích khi bạn muốn các tệp thực hiện riêng biệt cho các hệ thống con khác nhau tạo thành một hệ thống lớn hơn.  Ví dụ: giả sử bạn có một thư mục con của thư mục con có tệp tạo tệp riêng và bạn muốn tệp tạo tệp của thư mục chứa chạy tệp tạo trên thư mục con.  Bạn có thể làm điều đó bằng cách viết này:
```
subsystem:
        cd subdir && $(MAKE)
hoặc :
subsystem:
        $(MAKE) -C subdir
```
```
new_contents = "hello:\n\ttouch inside_file"
all:
	mkdir -p subdir
	printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
	cd subdir && $(MAKE)

clean:
	rm -rf subdir
```
Export : giúp cho 1 biến trong file makefile này có thể sử dụng trong file make được tạo ra bởi đệ quy 
```
new_contents = "hello:\n\techo \$$(cooly)"

all:
	mkdir -p subdir
	printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
	@echo "---MAKEFILE CONTENTS---"
	@cd subdir && cat makefile
	@echo "---END MAKEFILE CONTENTS---"
	cd subdir && $(MAKE)

# Note that variables and exports. They are set/affected globally.
cooly = "The subdirectory can see me!"
export cooly
# This would nullify the line above: unexport cooly

clean:
	rm -rf subdir
```
Sử dụng .EXPORT_ALL_VARIABLES để export tất cả các biến.

## Đối số trong dòng lệnh và ghi đè 
Trong make chúng ta có thể truyền đối số trong command line 
```
make option_one=hi 
```
Code : 
```
# Overrides command line arguments
override option_one = did_override
# Does not override command line arguments
option_two = not_override
all: 
	echo $(option_one)
	echo $(option_two)
```
Nếu có thêm override đằng trước thì cho dù truyền đối số mới vô thì giá trị của biến đó cũng không thay đổi.
## Lệnh điều kiện trong makefile
1. Conditional if/else<br>
```
foo = ok

all:
ifeq ($(foo), ok)
	echo "foo equals ok"
else
	echo "nope"
endif
```
2. Check if a variable is empty
```
nullstring =
foo = $(nullstring) # end of line; there is a space here

all:
ifeq ($(strip $(foo)),)
	echo "foo is empty after being stripped"
endif
ifeq ($(nullstring),)
	echo "nullstring doesn't even have spaces"
endif
```
3. Check if a variable is defined
```
bar =
foo = $(bar)

all:
ifdef foo
	echo "foo is defined"
endif
ifndef bar
	echo "but bar is not"
endif
```
4. $(MAKEFLAGS)
```
all:
# Search for the "-i" flag. MAKEFLAGS is just a list of single characters, one per flag. So look for "i" in this case.
ifneq (,$(findstring i, $(MAKEFLAGS)))
	echo "i was passed to MAKEFLAGS"
endif
```
## Hàm trong Makefile
1. First Functions <br>
Hàm chủ yếu được gọi khi xử lí văn bản. Gọi hàm $(fn, arguments). Có rất nhiều hàm được build sẵn trong make [builtin functions](https://www.gnu.org/software/make/manual/html_node/Functions.html)
```
bar := ${subst not, totally, "I am not superman"}
all: 
	@echo $(bar)
```
Sử dụng subst để thay thế not bằng totally<br>
Nếu muốn thay thế dấu cách hoặc dấu phẩy, hãy sử dụng biến :
```
comma := ,
empty:=
space := $(empty) $(empty)
foo := a b c
bar := $(subst $(space),$(comma),$(foo))

all: 
	@echo $(bar)
```
## Chuỗi thay thế 
Tìm các từ được phân tách bằng khoảng trắng trong văn bản khớp với mẫu và thay thế chúng bằng từ thay thế.  Mẫu ở đây có thể chứa '%' hoạt động như một ký tự đại diện, khớp với bất kỳ số lượng ký tự nào trong một từ.  Nếu thay thế cũng chứa '%', thì '%' được thay thế bằng văn bản khớp với '%' trong mẫu.  Chỉ '%' đầu tiên trong mẫu và thay thế được xử lý theo cách này;  mọi '%' tiếp theo không thay đổi.
```
foo := a.o b.o l.a c.o
one := $(patsubst %.o,%.c,$(foo))
# This is a shorthand for the above
two := $(foo:%.o=%.c)
# This is the suffix-only shorthand, and is also equivalent to the above.
three := $(foo:.o=.c)

all:
	echo $(one)
	echo $(two)
	echo $(three)
```
## Hàm foreach 
```
$(foreach var,list,text)
```
```
foo := who are you
# For each "word" in foo, output that same word with an exclamation after
bar := $(foreach wrd,$(foo),$(wrd)!)

all:
	# Output is "who! are! you!"
	@echo $(bar)
```
## Hàm if 
```
foo := $(if this-is-not-empty,then!,else!)
empty :=
bar := $(if $(empty),then!,else!)

all:
	@echo $(foo)
	@echo $(bar)
```
## Other Features
1. Include Makefiles<br>
Include là chỉ thị giúp make có thể đọc thêm được 1 hay nhiều files khác 
```
include filenames...
```
2. The vpath Directive <br>
Công dụng chính của vpath là giúp quản lý các đường dẫn tìm kiếm file dễ dàng hơn trong quá trình biên dịch. Thay vì phải chỉ định đường dẫn đầy đủ của từng file trong Makefile, bạn có thể sử dụng vpath để xác định các thư mục chứa các file đầu vào, và Make sẽ tự động tìm kiếm các file đó trong các thư mục được chỉ định.
```
vpath %.c src
```
Make sẽ tìm kiếm các file "foo.c" và "bar.c" trong thư mục "src" (hoặc trong các thư mục con của "src") để biên dịch thành các file đối tượng tương ứng.
Nếu không sẽ phải chỉ cụ thể đường dẫn : 
```
SRC_DIR = src
OBJ_DIR = obj

all: $(OBJ_DIR)/foo.o $(OBJ_DIR)/bar.o

$(OBJ_DIR)/foo.o: $(SRC_DIR)/foo.c
    gcc -c $(SRC_DIR)/foo.c -o $(OBJ_DIR)/foo.o

$(OBJ_DIR)/bar.o: $(SRC_DIR)/bar.c
    gcc -c $(SRC_DIR)/bar.c -o $(OBJ_DIR)/bar.o
```
3. Multiline <br>
```
some_file: 
	echo This line is too long, so \
		it is broken up into multiple lines
```


## Phân biệt phép gán trong Makefile
![Hình ảnh ](image2.png)

Make file cũng có thể include 1 file abc.mk khác 

[CrossCompling](https://eslinuxprogramming.blogspot.com/2015/04/cross-compiler.html)
Dưới đây là một số tùy chọn thông dụng cho trình biên dịch C GCC (GNU Compiler Collection):

Tùy chọn chung:
```
-c: Biên dịch các tệp nguồn mà không liên kết.
-o <file>: Chỉ định tên tệp đầu ra.
-E: Chỉ tiền xử lý; không biên dịch, lắp ráp hoặc liên kết.
-g: Tạo thông tin gỡ lỗi.
-O<level>: Chỉ định mức tối ưu hóa (-O0 cho không tối ưu hóa, -O1, -O2, -O3, -Os, v.v.).
-Wall: Bật tất cả các thông báo cảnh báo.
-Werror: Xem các cảnh báo như lỗi.
-I<dir>: Thêm thư mục vào đường tìm kiếm các tệp include.
-L<dir>: Thêm thư mục vào đường tìm kiếm các thư viện.
```
Tùy chọn ngôn ngữ:
```
-std=<standard>: Chỉ định chuẩn ngôn ngữ C sẽ được sử dụng (-std=c89, -std=c99, -std=c11, -std=c17, -std=c18, -std=c2x, v.v.).
-ansi: Tương đương với -std=c89.
-pedantic: Hiển thị tất cả các cảnh báo yêu cầu bởi chuẩn ISO C và ISO C++ nghiêm ngặt.
-f<feature>: Bật hoặc tắt các tính năng ngôn ngữ cụ thể (-funsigned-char, -fsigned-char, -fno-builtin, v.v.).
```
Tùy chọn tối ưu hóa:
```
-f<flag>: Bật hoặc tắt các tối ưu hóa cụ thể (-finline-functions, -fomit-frame-pointer, -fstrict-aliasing, -fno-common, v.v.).
-march=<arch>: Chỉ định kiến trúc mục tiêu (-march=native, -march=core2, -march=armv7-a, v.v.).
```
Tùy chọn liên kết:
```
-l<library>: Liên kết với một thư viện cụ thể (-lm, -lpthread, -lncurses, v.v.).
-L<dir>: Thêm thư mục vào đường tìm kiếm thư viện.
-Wl,<option>: Truyền một tùy chọn cho trình liên kết (-Wl,-rpath,<dir>, -Wl,-z,relro, -Wl,-Bstatic, v.v.).
```

