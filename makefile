PRE_DIR=./pre
ASM_DIR=./asm
# view use xxd commond 
OBJ_DIR=./obj
DASM_DIR=./disasm
BIN_DIR=./bin
clean:
	rm -rf $(PRE_DIR) $(ASM_DIR) $(OBJ_DIR) $(DASM_DIR) $(BIN_DIR)
	mkdir $(PRE_DIR) $(ASM_DIR) $(OBJ_DIR) $(DASM_DIR) $(BIN_DIR)

% : %_test.c
	gcc -E -o $(PRE_DIR)/$@.i $<
	gcc -S -o $(ASM_DIR)/$@.s $<
	gcc -c -o $(OBJ_DIR)/$@.o $<
	objdump -s -d $(OBJ_DIR)/$@.o > $(DASM_DIR)/$@.s
	gcc -o $(BIN_DIR)/$@ $<


.PHONY: clean

.DEFAULT:
	@echo "no dependency echo default"
