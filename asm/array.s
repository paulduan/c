	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 4
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function main
LCPI0_0:
	.quad	4632233691727265792     ## double 50
LCPI0_1:
	.quad	4619567317775286272     ## double 7
LCPI0_2:
	.quad	4614838538166547251     ## double 3.3999999999999999
LCPI0_3:
	.quad	4611686018427387904     ## double 2
LCPI0_4:
	.quad	4652007308841189376     ## double 1000
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$560, %rsp              ## imm = 0x230
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -468(%rbp)
	movl	%edi, -472(%rbp)
	movq	%rsi, -480(%rbp)
	leaq	-416(%rbp), %rax
	movq	%rax, %rdi
	leaq	l___const.main.a(%rip), %rsi
	movl	$408, %edx              ## imm = 0x198
	callq	_memcpy
	movl	$2, -484(%rbp)
	movl	-484(%rbp), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -504(%rbp)        ## 4-byte Spill
	callq	_arrayName
	leaq	-464(%rbp), %rcx
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	LCPI0_1(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	LCPI0_2(%rip), %xmm2    ## xmm2 = mem[0],zero
	movsd	LCPI0_3(%rip), %xmm3    ## xmm3 = mem[0],zero
	movsd	LCPI0_4(%rip), %xmm4    ## xmm4 = mem[0],zero
	xorl	%esi, %esi
	movq	%rcx, %rdx
	movq	%rdx, %rdi
	movl	$40, %edx
	movq	%rcx, -512(%rbp)        ## 8-byte Spill
	movsd	%xmm0, -520(%rbp)       ## 8-byte Spill
	movsd	%xmm1, -528(%rbp)       ## 8-byte Spill
	movsd	%xmm2, -536(%rbp)       ## 8-byte Spill
	movsd	%xmm3, -544(%rbp)       ## 8-byte Spill
	movsd	%xmm4, -552(%rbp)       ## 8-byte Spill
	callq	_memset
	movsd	-552(%rbp), %xmm0       ## 8-byte Reload
                                        ## xmm0 = mem[0],zero
	movsd	%xmm0, -464(%rbp)
	movsd	-544(%rbp), %xmm1       ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	movsd	%xmm1, -456(%rbp)
	movsd	-536(%rbp), %xmm2       ## 8-byte Reload
                                        ## xmm2 = mem[0],zero
	movsd	%xmm2, -448(%rbp)
	movsd	-528(%rbp), %xmm3       ## 8-byte Reload
                                        ## xmm3 = mem[0],zero
	movsd	%xmm3, -440(%rbp)
	movsd	-520(%rbp), %xmm4       ## 8-byte Reload
                                        ## xmm4 = mem[0],zero
	movsd	%xmm4, -432(%rbp)
	movq	-512(%rbp), %rdi        ## 8-byte Reload
	movq	-512(%rbp), %rsi        ## 8-byte Reload
	movq	-512(%rbp), %rdx        ## 8-byte Reload
	movl	$5, %ecx
	callq	_printArray
	callq	_returnArray
	movq	%rax, -496(%rbp)
	movl	$0, -500(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10, -500(%rbp)
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-500(%rbp), %esi
	movq	-496(%rbp), %rax
	movslq	-500(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-500(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -500(%rbp)
	jmp	LBB0_1
LBB0_4:
	movl	-468(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -556(%rbp)        ## 4-byte Spill
	jne	LBB0_6
## %bb.5:
	movl	-556(%rbp), %eax        ## 4-byte Reload
	addq	$560, %rsp              ## imm = 0x230
	popq	%rbp
	retq
LBB0_6:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_printArray             ## -- Begin function printArray
	.p2align	4, 0x90
_printArray:                            ## @printArray
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movl	%ecx, -28(%rbp)
	movl	$0, -32(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-32(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	LBB1_4
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movq	-8(%rbp), %rax
	movslq	-32(%rbp), %rcx
	movsd	(%rax,%rcx,8), %xmm0    ## xmm0 = mem[0],zero
	leaq	L_.str.6(%rip), %rdi
	movb	$1, %al
	callq	_printf
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	jmp	LBB1_1
LBB1_4:
	movl	$0, -36(%rbp)
LBB1_5:                                 ## =>This Inner Loop Header: Depth=1
	movl	-36(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	LBB1_8
## %bb.6:                               ##   in Loop: Header=BB1_5 Depth=1
	movq	-16(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movsd	(%rax,%rcx,8), %xmm0    ## xmm0 = mem[0],zero
	leaq	L_.str.7(%rip), %rdi
	movb	$1, %al
	callq	_printf
## %bb.7:                               ##   in Loop: Header=BB1_5 Depth=1
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
	jmp	LBB1_5
LBB1_8:
	movl	$0, -40(%rbp)
LBB1_9:                                 ## =>This Inner Loop Header: Depth=1
	movl	-40(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	LBB1_12
## %bb.10:                              ##   in Loop: Header=BB1_9 Depth=1
	movq	-24(%rbp), %rax
	movslq	-40(%rbp), %rcx
	movsd	(%rax,%rcx,8), %xmm0    ## xmm0 = mem[0],zero
	leaq	L_.str.8(%rip), %rdi
	movb	$1, %al
	callq	_printf
## %bb.11:                              ##   in Loop: Header=BB1_9 Depth=1
	movl	-40(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -40(%rbp)
	jmp	LBB1_9
LBB1_12:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_arrayName              ## -- Begin function arrayName
	.p2align	4, 0x90
_arrayName:                             ## @arrayName
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	leaq	-96(%rbp), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	movq	%rax, -104(%rbp)
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -108(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -108(%rbp)
	jge	LBB2_4
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movl	-108(%rbp), %esi
	movq	-104(%rbp), %rax
	movslq	-108(%rbp), %rcx
	movsd	(%rax,%rcx,8), %xmm0    ## xmm0 = mem[0],zero
	leaq	L_.str.3(%rip), %rdi
	movb	$1, %al
	callq	_printf
## %bb.3:                               ##   in Loop: Header=BB2_1 Depth=1
	movl	-108(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -108(%rbp)
	jmp	LBB2_1
LBB2_4:
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -112(%rbp)
LBB2_5:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -112(%rbp)
	jge	LBB2_8
## %bb.6:                               ##   in Loop: Header=BB2_5 Depth=1
	movl	-112(%rbp), %esi
	movslq	-112(%rbp), %rax
	movsd	-96(%rbp,%rax,8), %xmm0 ## xmm0 = mem[0],zero
	leaq	L_.str.5(%rip), %rdi
	movb	$1, %al
	callq	_printf
## %bb.7:                               ##   in Loop: Header=BB2_5 Depth=1
	movl	-112(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -112(%rbp)
	jmp	LBB2_5
LBB2_8:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB2_10
## %bb.9:
	addq	$112, %rsp
	popq	%rbp
	retq
LBB2_10:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_returnArray            ## -- Begin function returnArray
	.p2align	4, 0x90
_returnArray:                           ## @returnArray
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	movl	%eax, %edi
	callq	_time
                                        ## kill: def $eax killed $eax killed $rax
	movl	%eax, %edi
	callq	_srand
	movl	$0, -4(%rbp)
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10, -4(%rbp)
	jge	LBB3_4
## %bb.2:                               ##   in Loop: Header=BB3_1 Depth=1
	callq	_rand
	movslq	-4(%rbp), %rcx
	leaq	_returnArray.r(%rip), %rdx
	movl	%eax, (%rdx,%rcx,4)
	movl	-4(%rbp), %esi
	movslq	-4(%rbp), %rcx
	movl	(%rdx,%rcx,4), %edx
	leaq	L_.str.9(%rip), %rdi
	movb	$0, %al
	callq	_printf
## %bb.3:                               ##   in Loop: Header=BB3_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB3_1
LBB3_4:
	leaq	_returnArray.r(%rip), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.p2align	4               ## @__const.main.a
l___const.main.a:
	.asciz	"C \350\257\255\350\250\200\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.asciz	"RUNOOB\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.asciz	"\347\274\226\347\250\213\350\257\255\350\250\200\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	12                      ## 0xc
	.asciz	"java \350\257\255\350\250\200\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.asciz	"hi\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.asciz	"\347\274\226\347\250\213\350\257\255\350\250\200\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
	.long	123                     ## 0x7b

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"len of array:%d\n"

L_.str.1:                               ## @.str.1
	.asciz	"*(arr + %d) : %d\n"

L_.str.2:                               ## @.str.2
	.asciz	"\344\275\277\347\224\250\346\214\207\351\222\210\347\232\204\346\225\260\347\273\204\345\200\274\n"

L_.str.3:                               ## @.str.3
	.asciz	"*(p + %d) : %f\n"

L_.str.4:                               ## @.str.4
	.asciz	"\344\275\277\347\224\250 balance \344\275\234\344\270\272\345\234\260\345\235\200\347\232\204\346\225\260\347\273\204\345\200\274\n"

L_.str.5:                               ## @.str.5
	.asciz	"*(balance + %d) : %f\n"

L_.str.6:                               ## @.str.6
	.asciz	"param1 %lf\n"

L_.str.7:                               ## @.str.7
	.asciz	"param2 %lf\n"

L_.str.8:                               ## @.str.8
	.asciz	"param3:%lf\n"

.zerofill __DATA,__bss,_returnArray.r,40,4 ## @returnArray.r
L_.str.9:                               ## @.str.9
	.asciz	"r[%d] = %d\n"

.subsections_via_symbols
