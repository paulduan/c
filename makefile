PRE_DIR=./pre
ASM_DIR=./asm
OBJ_DIR=./obj
BIN_DIR=./bin
clean:
	rm -rf $(PRE_DIR) $(ASM_DIR) $(OBJ_DIR) $(BIN_DIR)
	mkdir $(PRE_DIR) $(ASM_DIR) $(OBJ_DIR) $(BIN_DIR)

% : %_test.c
	gcc -E -o $(PRE_DIR)/$@.i $<
	gcc -S -o $(ASM_DIR)/$@.s $<
	gcc -c -o $(OBJ_DIR)/$@.o $<
	gcc -o $(BIN_DIR)/$@ $<


.PHONY: clean

.DEFAULT:
	@echo "no dependency echo default"