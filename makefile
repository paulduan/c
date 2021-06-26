PRE_DIR=./pre
ASM_DIR=./asm
# view use xxd commond 
OBJ_DIR=./obj
DASM_DIR=./disasm
BIN_DIR=./bin
HEX_DIR=./hex
LDD_DIR=./ldd
DETAIL_DIR=./detail
GCCDEBUG= -v -g3
clean:
	@rm -rf $(PRE_DIR) $(ASM_DIR) $(OBJ_DIR) $(DASM_DIR) $(BIN_DIR) $(HEX_DIR) $(LDD_DIR) $(DETAIL_DIR)
	@mkdir $(PRE_DIR) $(ASM_DIR) $(OBJ_DIR) $(DASM_DIR) $(BIN_DIR) $(HEX_DIR) $(LDD_DIR) $(DETAIL_DIR)
# 冒号前面是target 后面是prerequisites
# % 表示匹配当前目录所有_test.c结尾的文件
# $< 代表匹配的prerequisites 也就是 eg. string_test.c
# $@代表当前target eg. string
# ${ARG} 是可执行文件需要传入的参数 eg. make file ARG=bin/file
# -E预编译(cpp预处理器) -S汇编(cc1编译器) -c只编译不连接(as汇编器) collect2(ld)链接器 -g3包含调试信息 
#  objdump 反汇编
#  ldd 查看动态链接库
% : %_test.c
	@gcc -E -o $(PRE_DIR)/$@.i $<
	@gcc -S -o $(ASM_DIR)/$@.s $<
	@gcc -c -o $(OBJ_DIR)/$@.o $<
	@objdump -s -d $(OBJ_DIR)/$@.o > $(DASM_DIR)/$@.s
	@gcc ${GCCDEBUG} -o $(BIN_DIR)/$@ $< > $(DETAIL_DIR)/$@.detail  2>&1
	@xxd $(BIN_DIR)/$@ > ${HEX_DIR}/$@.hex
	@ldd $(BIN_DIR)/$@ > ${LDD_DIR}/$@.ldd
	@$(BIN_DIR)/$@ ${ARG}
#yum install ncurses-devel
snake:
	@gcc Gluttonous_Snake.c -o $(BIN_DIR)/snake -lncurses
debug1:
	@gcc Gluttonous_Snake.c -o $(BIN_DIR)/snake -lncurses -DDEBUG=1
debug2:
	@gcc Gluttonous_Snake.c -o $(BIN_DIR)/snake -lncurses -DDEBUG=2
	
vim_% : bin/%
	@vim -b -c ":%!xxd" $<
.PHONY: clean

.DEFAULT:
	@echo "no dependency echo default"
