PRE_DIR=./pre
ASM_DIR=./asm
# view use xxd commond 
OBJ_DIR=./obj
DASM_DIR=./disasm
BIN_DIR=./bin
GCCDEBUG= -v -g3
clean:
	@rm -rf $(PRE_DIR) $(ASM_DIR) $(OBJ_DIR) $(DASM_DIR) $(BIN_DIR)
	@mkdir $(PRE_DIR) $(ASM_DIR) $(OBJ_DIR) $(DASM_DIR) $(BIN_DIR)
# 冒号前面是target 后面是prerequisites
# % 表示匹配当前目录所有_test.c结尾的文件
% : %_test.c
# $< 代表匹配的prerequisites 也就是 eg. string_test.c
# $@代表当前target eg. string
# ${ARG} 是可执行文件需要传入的参数 eg. make file ARG=bin/file
# ${GCCARG} 是gcc需要传入的参数 eg. 
# -E预编译(cpp) -S汇编(cc1) -c只编译不连接(as) collect2链接 -g3包含调试信息 
#  objdump 反汇编
#  ldd 查看动态链接库
#  等于cpp -o $(PRE_DIR)/$@.i $<
	@gcc -E -o $(PRE_DIR)/$@.i $<
	@gcc -S -o $(ASM_DIR)/$@.s $<
	@gcc -c -o $(OBJ_DIR)/$@.o $<
	@objdump -s -d $(OBJ_DIR)/$@.o > $(DASM_DIR)/$@.s
	@gcc ${GCCDEBUG} -o  ${GCCARG} $(BIN_DIR)/$@ $<
	@ldd $(BIN_DIR)/$@
	@$(BIN_DIR)/$@ ${ARG}
#yum install ncurses-devel
snake:
	@gcc Gluttonous_Snake.c -o $(BIN_DIR)/snake -lncurses
debug1:
	@gcc Gluttonous_Snake.c -o $(BIN_DIR)/snake -lncurses -DDEBUG=1
debug2:
	@gcc Gluttonous_Snake.c -o $(BIN_DIR)/snake -lncurses -DDEBUG=2
	

.PHONY: clean

.DEFAULT:
	@echo "no dependency echo default"
