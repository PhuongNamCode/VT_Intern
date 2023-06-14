PRO_DIR		:= .
PROJ_NAME	:= GPIO
OUTPUT_PATH	:= $(PRO_DIR)/output
abc = 123
build: main.o
	gcc output/main.o -o output/Results.exe
	./output/Results.exe
main.o: source/main.c
	gcc -c source/main.c -o output/main.o
clean: 
	rm output/*
print-%:
	@echo $($(subst print-,,$@))

