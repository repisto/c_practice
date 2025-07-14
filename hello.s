	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	wzr, [sp, #12]
	mov	w8, #10                         ; =0xa
	str	w8, [sp, #8]
	ldr	w8, [sp, #8]
	subs	w8, w8, #1
	b.ne	LBB0_2
	b	LBB0_1
LBB0_1:
	mov	w8, #1                          ; =0x1
	str	w8, [sp, #8]
	b	LBB0_11
LBB0_2:
	ldr	w8, [sp, #8]
	subs	w8, w8, #2
	b.ne	LBB0_4
	b	LBB0_3
LBB0_3:
	mov	w8, #2                          ; =0x2
	str	w8, [sp, #8]
	b	LBB0_10
LBB0_4:
	ldr	w8, [sp, #8]
	subs	w8, w8, #3
	b.ne	LBB0_6
	b	LBB0_5
LBB0_5:
	mov	w8, #3                          ; =0x3
	str	w8, [sp, #8]
	b	LBB0_9
LBB0_6:
	ldr	w8, [sp, #8]
	subs	w8, w8, #4
	b.ne	LBB0_8
	b	LBB0_7
LBB0_7:
	mov	w8, #4                          ; =0x4
	str	w8, [sp, #8]
	b	LBB0_8
LBB0_8:
	b	LBB0_9
LBB0_9:
	b	LBB0_10
LBB0_10:
	b	LBB0_11
LBB0_11:
	mov	w0, #0                          ; =0x0
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
