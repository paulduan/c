PRE_DIR=./pre
ASM_DIR=./asm
BIN_DIR=./bin
time:time_test.c
	gcc -E -o $(PRE_DIR)/time.i time_test.c
	gcc -S -o $(ASM_DIR)/time.s time_test.c
	gcc -o $(BIN_DIR)/time time_test.c

array:array_test.c
	gcc -E -o $(PRE_DIR)/array.i array_test.c
	gcc -S -o $(ASM_DIR)/array.s array_test.c
	gcc -o $(BIN_DIR)/array array_test.c
string:string_test.c
	gcc -E -o $(PRE_DIR)/string.i string_test.c
	gcc -S -o $(ASM_DIR)/string.s string_test.c
	gcc -o $(BIN_DIR)/string string_test.c

clean:
	rm -rf $(PRE_DIR) $(ASM_DIR) $(BIN_DIR)
	mkdir $(PRE_DIR) $(ASM_DIR) $(BIN_DIR)

.PHONY: clean

