PRE_DIR=./pre
ASM_DIR=./asm
BIN_DIR=./bin

init:
	rm -rf $(PRE_DIR) $(ASM_DIR) $(BIN_DIR)
	mkdir $(PRE_DIR) $(ASM_DIR) $(BIN_DIR)

% : %_test.c
	gcc -E -o $(PRE_DIR)/$@.i $<
	gcc -S -o $(ASM_DIR)/$@.s $<
	gcc -o $(BIN_DIR)/$@ $<

clean:
	rm -rf $(PRE_DIR) $(ASM_DIR) $(BIN_DIR)
	mkdir $(PRE_DIR) $(ASM_DIR) $(BIN_DIR)

.PHONY: clean

.DEFAULT:
	@echo "no dependency echo default"