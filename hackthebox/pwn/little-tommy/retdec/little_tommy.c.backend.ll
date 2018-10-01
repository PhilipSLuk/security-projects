source_filename = "test"
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"

%_IO_FILE = type { i32 }

@0 = external local_unnamed_addr global i32
@global_var_804a040.2 = local_unnamed_addr global i32 0
@global_var_80489e0.5 = constant [108 x i8] c"\0A#################### Welcome to Little Tommy's Handy yet Elegant and Advanced Program ####################\00"
@global_var_8048a4c.6 = constant [118 x i8] c"\0A1. Create account\0A2. Display account\0A3. Delete account\0A4. Add memo\0A5. Print flag\0A\0APlease enter an operation number: \00"
@global_var_8048c0c.7 = constant i32 134514404
@global_var_804a048.8 = local_unnamed_addr global i32 0
@global_var_8048ac2.9 = constant [14 x i8] c"\0AFirst name: \00"
@global_var_8048ad0.10 = constant [12 x i8] c"Last name: \00"
@global_var_8048adc.11 = constant [37 x i8] c"\0AThank you, your account number %d.\0A\00"
@global_var_8048b01.12 = constant [26 x i8] c"\0ASorry, no account found.\00"
@global_var_8048b1c.13 = constant [101 x i8] c"\0A################ Account no. %d ################\0AFirst name: %s\0ALast name: %s\0AAccount balance: %d\0A\0A\00"
@global_var_8048b81.14 = constant [30 x i8] c"\0AAccount deleted successfully\00"
@global_var_8048b9f.15 = constant [20 x i8] c"\0APlease enter memo:\00"
@global_var_804a04c.16 = local_unnamed_addr global i32 0
@global_var_8048bb4.17 = constant [64 x i8] c"\0AThank you, please keep this reference number number safe: %d.\0A\00"
@global_var_8048bf4.18 = constant [14 x i8] c"/bin/cat flag\00"
@global_var_8048c02.19 = constant [7 x i8] c"\0ANope.\00"
@1 = external global i32

define i32 @main(i32 %argc, i8** %argv) local_unnamed_addr {
dec_label_pc_804865c:
  %eax.global-to-local = alloca i32, align 4
  %ebx.global-to-local = alloca i32, align 4
  %ecx.global-to-local = alloca i32, align 4
  %edx.global-to-local = alloca i32, align 4
  %esp.global-to-local = alloca i32, align 4
  store i32 0, i32* %esp.global-to-local, align 4
  %tmp107 = call i8* @__decompiler_undefined_function_1()
  %stack_var_-276 = alloca i8*, align 4
  %stack_var_-288 = alloca i32, align 4
  %stack_var_4 = alloca i32, align 4
  %v2_804865c = ptrtoint i32* %stack_var_4 to i32
  store i32 %v2_804865c, i32* %ecx.global-to-local, align 4
  %v15_804866b = ptrtoint i32* %stack_var_-288 to i32
  store i32 0, i32* %eax.global-to-local, align 4
  %v3_8048684 = call i32 @puts(i8* getelementptr inbounds ([108 x i8], [108 x i8]* @global_var_80489e0.5, i32 0, i32 0))
  store i32 %v3_8048684, i32* %eax.global-to-local, align 4
  %v2_8048714 = ptrtoint i8** %stack_var_-276 to i32
  br label %dec_label_pc_8048693

dec_label_pc_8048693:                             ; preds = %dec_label_pc_8048807, %dec_label_pc_804882b, %dec_label_pc_8048840, %dec_label_pc_804887e, %dec_label_pc_8048893, %dec_label_pc_80488b9, %dec_label_pc_804894f, %dec_label_pc_80486cc.dec_label_pc_8048693.backedge_crit_edge, %dec_label_pc_804865c
  %v0_8048693 = phi i32 [ %v15_804866b, %dec_label_pc_804865c ], [ %v0_8048693.pre.pre, %dec_label_pc_80486cc.dec_label_pc_8048693.backedge_crit_edge ], [ %v1_804893a, %dec_label_pc_804894f ], [ %v1_8048910, %dec_label_pc_80488b9 ], [ %v1_80488b1, %dec_label_pc_8048893 ], [ %v1_804888b, %dec_label_pc_804887e ], [ %v1_804886d, %dec_label_pc_8048840 ], [ %v1_8048838, %dec_label_pc_804882b ], [ %v1_804881a, %dec_label_pc_8048807 ]
  %stack_var_-280.0 = phi i8* [ %tmp107, %dec_label_pc_804865c ], [ %stack_var_-280.0, %dec_label_pc_80486cc.dec_label_pc_8048693.backedge_crit_edge ], [ %stack_var_-280.0, %dec_label_pc_804894f ], [ %stack_var_-280.0, %dec_label_pc_80488b9 ], [ %stack_var_-280.0, %dec_label_pc_8048893 ], [ %stack_var_-280.0, %dec_label_pc_804887e ], [ %stack_var_-280.0, %dec_label_pc_8048840 ], [ %stack_var_-280.0, %dec_label_pc_804882b ], [ %v4_80487da, %dec_label_pc_8048807 ]
  %v1_8048696 = add i32 %v0_8048693, -16
  %v2_8048696 = inttoptr i32 %v1_8048696 to i32*
  store i32 ptrtoint ([118 x i8]* @global_var_8048a4c.6 to i32), i32* %v2_8048696, align 4
  %v1_804869b = call i32 (i8*, ...) @printf(i8* bitcast (i32* @1 to i8*))
  store i32 %v1_804869b, i32* %eax.global-to-local, align 4
  %v0_80486a3 = call i32 @getchar()
  store i32 %v0_80486a3, i32* %eax.global-to-local, align 4
  br label %dec_label_pc_80486af

dec_label_pc_80486af:                             ; preds = %dec_label_pc_80486af, %dec_label_pc_8048693
  %v0_80486af = call i32 @getchar()
  store i32 %v0_80486af, i32* %eax.global-to-local, align 4
  %v1_80486b4 = trunc i32 %v0_80486af to i8
  %v13_80486ba = icmp ne i8 %v1_80486b4, 10
  %v13_80486c3 = icmp eq i8 %v1_80486b4, -1
  %v1_80486ca = icmp eq i1 %v13_80486c3, false
  %or.cond = icmp eq i1 %v13_80486ba, %v1_80486ca
  br i1 %or.cond, label %dec_label_pc_80486af, label %dec_label_pc_80486cc

dec_label_pc_80486cc:                             ; preds = %dec_label_pc_80486af
  %sext = mul i32 %v0_80486a3, 16777216
  %v4_80486cc = sdiv i32 %sext, 16777216
  %v1_80486d3 = add nsw i32 %v4_80486cc, -49
  store i32 %v1_80486d3, i32* %eax.global-to-local, align 4
  store i32 %v1_80486d3, i32* @0, align 4
  %v1_80486db = mul nsw i32 %v1_80486d3, 4
  %v2_80486db = add i32 %v1_80486db, ptrtoint (i32* @global_var_8048c0c.7 to i32)
  %v3_80486db = inttoptr i32 %v2_80486db to i32*
  %v4_80486db = load i32, i32* %v3_80486db, align 4
  store i32 %v4_80486db, i32* %eax.global-to-local, align 4
  switch i32 %v4_80486cc, label %dec_label_pc_80486cc.dec_label_pc_8048693.backedge_crit_edge [
    i32 49, label %dec_label_pc_80486e4
    i32 50, label %dec_label_pc_8048822
    i32 51, label %dec_label_pc_8048875
    i32 52, label %dec_label_pc_80488b9
    i32 53, label %dec_label_pc_8048915
  ]

dec_label_pc_80486cc.dec_label_pc_8048693.backedge_crit_edge: ; preds = %dec_label_pc_80486cc
  %v0_8048693.pre.pre = load i32, i32* %esp.global-to-local, align 4
  br label %dec_label_pc_8048693

dec_label_pc_80486e4:                             ; preds = %dec_label_pc_80486cc
  %v0_80486e4 = load i32, i32* %esp.global-to-local, align 4
  %v1_80486e7 = add i32 %v0_80486e4, -16
  %v2_80486e7 = inttoptr i32 %v1_80486e7 to i32*
  store i32 72, i32* %v2_80486e7, align 4
  %sext6 = mul i32 %v0_80486af, 16777216
  %v1_80486e9 = sdiv i32 %sext6, 16777216
  %v2_80486e9 = call i32* @malloc(i32 %v1_80486e9)
  %v4_80486e9 = ptrtoint i32* %v2_80486e9 to i32
  store i32 %v4_80486e9, i32* %eax.global-to-local, align 4
  %v0_80486ee = load i32, i32* %esp.global-to-local, align 4
  store i32 %v4_80486e9, i32* @global_var_804a048.8, align 4
  %v2_80486f9 = inttoptr i32 %v0_80486ee to i32*
  store i32 ptrtoint ([14 x i8]* @global_var_8048ac2.9 to i32), i32* %v2_80486f9, align 4
  %v1_80486fe = call i32 (i8*, ...) @printf(i8* bitcast (i32* @1 to i8*))
  %v0_8048703 = load i32, i32* %esp.global-to-local, align 4
  %v0_8048706 = load i32, i32* @global_var_804a040.2, align 4
  %v2_804870e = add i32 %v0_8048703, 8
  %v3_804870e = inttoptr i32 %v2_804870e to i32*
  store i32 %v0_8048706, i32* %v3_804870e, align 4
  %v1_804870f = add i32 %v0_8048703, 4
  %v2_804870f = inttoptr i32 %v1_804870f to i32*
  store i32 256, i32* %v2_804870f, align 4
  store i32 %v2_8048714, i32* %eax.global-to-local, align 4
  %v3_804871a = inttoptr i32 %v0_8048703 to i32*
  store i32 %v2_8048714, i32* %v3_804871a, align 4
  %tmp131 = urem i32 %v0_80486af, 256
  %v1_804871b = inttoptr i32 %tmp131 to i8*
  %v4_804871b = call i8* @fgets(i8* %v1_804871b, i32 ptrtoint (i32* @1 to i32), %_IO_FILE* bitcast (i32* @1 to %_IO_FILE*))
  %v0_8048720 = load i32, i32* %esp.global-to-local, align 4
  %v0_8048723 = load i32, i32* @global_var_804a048.8, align 4
  store i32 %v0_8048723, i32* %edx.global-to-local, align 4
  %v1_804872d = add i32 %v0_8048720, 8
  %v2_804872d = inttoptr i32 %v1_804872d to i32*
  store i32 30, i32* %v2_804872d, align 4
  store i32 %v2_8048714, i32* %eax.global-to-local, align 4
  %v2_8048735 = add i32 %v0_8048720, 4
  %v3_8048735 = inttoptr i32 %v2_8048735 to i32*
  store i32 %v2_8048714, i32* %v3_8048735, align 4
  %v0_8048736 = load i32, i32* %edx.global-to-local, align 4
  %v3_8048736 = inttoptr i32 %v0_8048720 to i32*
  store i32 %v0_8048736, i32* %v3_8048736, align 4
  %v4_8048737 = call i8* @strncpy(i8* %v1_804871b, i8* bitcast (i32* @1 to i8*), i32 ptrtoint (i32* @1 to i32))
  %v0_804873c = load i32, i32* %esp.global-to-local, align 4
  %v0_804873f = load i32, i32* @global_var_804a048.8, align 4
  store i32 %v0_804873f, i32* %eax.global-to-local, align 4
  %v3_8048747 = inttoptr i32 %v0_804873c to i32*
  store i32 %v0_804873f, i32* %v3_8048747, align 4
  %v2_8048748 = call i32 @strlen(i8* %v1_804871b)
  %v4_8048750 = inttoptr i32 %v2_8048748 to i8*
  %v9_804875d = icmp sgt i32 %v2_8048748, 30
  %v0_8048773 = load i32, i32* @global_var_804a048.8, align 4
  store i32 %v0_8048773, i32* %eax.global-to-local, align 4
  br i1 %v9_804875d, label %dec_label_pc_8048773, label %dec_label_pc_804875f

dec_label_pc_804875f:                             ; preds = %dec_label_pc_80486e4
  %v1_804876a = add i32 %v2_8048748, -1
  store i32 %v1_804876a, i32* %edx.global-to-local, align 4
  %v3_804876d = add i32 %v0_8048773, %v1_804876a
  %v4_804876d = inttoptr i32 %v3_804876d to i8*
  store i8 0, i8* %v4_804876d, align 1
  br label %dec_label_pc_804877c

dec_label_pc_8048773:                             ; preds = %dec_label_pc_80486e4
  %v1_8048778 = add i32 %v0_8048773, 31
  %v2_8048778 = inttoptr i32 %v1_8048778 to i8*
  store i8 0, i8* %v2_8048778, align 1
  br label %dec_label_pc_804877c

dec_label_pc_804877c:                             ; preds = %dec_label_pc_8048773, %dec_label_pc_804875f
  %v0_804877c = load i32, i32* %esp.global-to-local, align 4
  %v1_804877f = add i32 %v0_804877c, -16
  %v2_804877f = inttoptr i32 %v1_804877f to i32*
  store i32 ptrtoint ([12 x i8]* @global_var_8048ad0.10 to i32), i32* %v2_804877f, align 4
  %v1_8048784 = call i32 (i8*, ...) @printf(i8* bitcast (i32* @1 to i8*))
  %v0_8048789 = load i32, i32* %esp.global-to-local, align 4
  %v0_804878c = load i32, i32* @global_var_804a040.2, align 4
  %v2_8048794 = add i32 %v0_8048789, 8
  %v3_8048794 = inttoptr i32 %v2_8048794 to i32*
  store i32 %v0_804878c, i32* %v3_8048794, align 4
  %v1_8048795 = add i32 %v0_8048789, 4
  %v2_8048795 = inttoptr i32 %v1_8048795 to i32*
  store i32 256, i32* %v2_8048795, align 4
  store i32 %v2_8048714, i32* %eax.global-to-local, align 4
  %v3_80487a0 = inttoptr i32 %v0_8048789 to i32*
  store i32 %v2_8048714, i32* %v3_80487a0, align 4
  %v2_80487a1 = load i8*, i8** %stack_var_-276, align 4
  %v3_80487a1 = ptrtoint i8* %v2_80487a1 to i32
  %v6_80487a1 = call i8* @fgets(i8* %v4_8048750, i32 %v3_80487a1, %_IO_FILE* bitcast (i32* @1 to %_IO_FILE*))
  %v0_80487a6 = load i32, i32* %esp.global-to-local, align 4
  %v0_80487a9 = load i32, i32* @global_var_804a048.8, align 4
  %v1_80487ae = add i32 %v0_80487a9, 32
  store i32 %v1_80487ae, i32* %edx.global-to-local, align 4
  %v1_80487b4 = add i32 %v0_80487a6, 8
  %v2_80487b4 = inttoptr i32 %v1_80487b4 to i32*
  store i32 30, i32* %v2_80487b4, align 4
  store i32 %v2_8048714, i32* %eax.global-to-local, align 4
  %v2_80487bc = add i32 %v0_80487a6, 4
  %v3_80487bc = inttoptr i32 %v2_80487bc to i32*
  store i32 %v2_8048714, i32* %v3_80487bc, align 4
  %v0_80487bd = load i32, i32* %edx.global-to-local, align 4
  %v3_80487bd = inttoptr i32 %v0_80487a6 to i32*
  store i32 %v0_80487bd, i32* %v3_80487bd, align 4
  %v2_80487be = load i8*, i8** %stack_var_-276, align 4
  %v7_80487be = call i8* @strncpy(i8* %v4_8048750, i8* %v2_80487be, i32 ptrtoint (i32* @1 to i32))
  %v0_80487c3 = load i32, i32* %esp.global-to-local, align 4
  %v0_80487c6 = load i32, i32* @global_var_804a048.8, align 4
  %v1_80487cb = add i32 %v0_80487c6, 32
  store i32 %v1_80487cb, i32* %eax.global-to-local, align 4
  %v3_80487d1 = inttoptr i32 %v0_80487c3 to i32*
  store i32 %v1_80487cb, i32* %v3_80487d1, align 4
  %v3_80487d2 = call i32 @strlen(i8* %v4_8048750)
  %v4_80487da = inttoptr i32 %v3_80487d2 to i8*
  %v9_80487e7 = icmp sgt i32 %v3_80487d2, 30
  %v0_80487fe = load i32, i32* @global_var_804a048.8, align 4
  store i32 %v0_80487fe, i32* %eax.global-to-local, align 4
  br i1 %v9_80487e7, label %dec_label_pc_80487fe, label %dec_label_pc_80487e9

dec_label_pc_80487e9:                             ; preds = %dec_label_pc_804877c
  %v1_80487f4 = add i32 %v3_80487d2, -1
  store i32 %v1_80487f4, i32* %edx.global-to-local, align 4
  %v3_80487f7 = add i32 %v3_80487d2, 31
  %v4_80487f7 = add i32 %v3_80487f7, %v0_80487fe
  %v5_80487f7 = inttoptr i32 %v4_80487f7 to i8*
  store i8 0, i8* %v5_80487f7, align 1
  br label %dec_label_pc_8048807

dec_label_pc_80487fe:                             ; preds = %dec_label_pc_804877c
  %v1_8048803 = add i32 %v0_80487fe, 63
  %v2_8048803 = inttoptr i32 %v1_8048803 to i8*
  store i8 0, i8* %v2_8048803, align 1
  br label %dec_label_pc_8048807

dec_label_pc_8048807:                             ; preds = %dec_label_pc_80487fe, %dec_label_pc_80487e9
  %v0_8048807 = load i32, i32* @global_var_804a048.8, align 4
  store i32 %v0_8048807, i32* %eax.global-to-local, align 4
  %v0_804880c = load i32, i32* %esp.global-to-local, align 4
  %v2_804880f = add i32 %v0_804880c, -12
  %v3_804880f = inttoptr i32 %v2_804880f to i32*
  store i32 %v0_8048807, i32* %v3_804880f, align 4
  %v1_8048810 = add i32 %v0_804880c, -16
  %v2_8048810 = inttoptr i32 %v1_8048810 to i32*
  store i32 ptrtoint ([37 x i8]* @global_var_8048adc.11 to i32), i32* %v2_8048810, align 4
  %v1_8048815 = call i32 (i8*, ...) @printf(i8* bitcast (i32* @1 to i8*))
  store i32 %v1_8048815, i32* %eax.global-to-local, align 4
  %v0_804881a = load i32, i32* %esp.global-to-local, align 4
  %v1_804881a = add i32 %v0_804881a, 16
  br label %dec_label_pc_8048693

dec_label_pc_8048822:                             ; preds = %dec_label_pc_80486cc
  %v0_8048822 = load i32, i32* @global_var_804a048.8, align 4
  store i32 %v0_8048822, i32* %eax.global-to-local, align 4
  %v1_8048827 = icmp eq i32 %v0_8048822, 0
  %v1_8048829 = icmp eq i1 %v1_8048827, false
  br i1 %v1_8048829, label %dec_label_pc_8048840, label %dec_label_pc_804882b

dec_label_pc_804882b:                             ; preds = %dec_label_pc_8048822
  %v0_804882b = load i32, i32* %esp.global-to-local, align 4
  %v1_804882e = add i32 %v0_804882b, -16
  %v2_804882e = inttoptr i32 %v1_804882e to i32*
  store i32 ptrtoint ([26 x i8]* @global_var_8048b01.12 to i32), i32* %v2_804882e, align 4
  %v3_8048833 = call i32 @puts(i8* %stack_var_-280.0)
  store i32 %v3_8048833, i32* %eax.global-to-local, align 4
  %v0_8048838 = load i32, i32* %esp.global-to-local, align 4
  %v1_8048838 = add i32 %v0_8048838, 16
  br label %dec_label_pc_8048693

dec_label_pc_8048840:                             ; preds = %dec_label_pc_8048822
  store i32 %v0_8048822, i32* %eax.global-to-local, align 4
  %v1_8048845 = add i32 %v0_8048822, 64
  %v2_8048845 = inttoptr i32 %v1_8048845 to i32*
  %v3_8048845 = load i32, i32* %v2_8048845, align 4
  store i32 %v3_8048845, i32* %edx.global-to-local, align 4
  %v1_804884d = add i32 %v0_8048822, 32
  store i32 %v1_804884d, i32* %ecx.global-to-local, align 4
  store i32 %v0_8048822, i32* %ebx.global-to-local, align 4
  store i32 %v0_8048822, i32* %eax.global-to-local, align 4
  %v0_804885c = load i32, i32* %esp.global-to-local, align 4
  %v2_804885f = add i32 %v0_804885c, -16
  %v3_804885f = inttoptr i32 %v2_804885f to i32*
  store i32 %v3_8048845, i32* %v3_804885f, align 4
  %v0_8048860 = load i32, i32* %ecx.global-to-local, align 4
  %v2_8048860 = add i32 %v0_804885c, -20
  %v3_8048860 = inttoptr i32 %v2_8048860 to i32*
  store i32 %v0_8048860, i32* %v3_8048860, align 4
  %v0_8048861 = load i32, i32* %ebx.global-to-local, align 4
  %v2_8048861 = add i32 %v0_804885c, -24
  %v3_8048861 = inttoptr i32 %v2_8048861 to i32*
  store i32 %v0_8048861, i32* %v3_8048861, align 4
  %v0_8048862 = load i32, i32* %eax.global-to-local, align 4
  %v2_8048862 = add i32 %v0_804885c, -28
  %v3_8048862 = inttoptr i32 %v2_8048862 to i32*
  store i32 %v0_8048862, i32* %v3_8048862, align 4
  %v1_8048863 = add i32 %v0_804885c, -32
  %v2_8048863 = inttoptr i32 %v1_8048863 to i32*
  store i32 ptrtoint ([101 x i8]* @global_var_8048b1c.13 to i32), i32* %v2_8048863, align 4
  %v1_8048868 = call i32 (i8*, ...) @printf(i8* bitcast (i32* @1 to i8*))
  store i32 %v1_8048868, i32* %eax.global-to-local, align 4
  %v0_804886d = load i32, i32* %esp.global-to-local, align 4
  %v1_804886d = add i32 %v0_804886d, 32
  br label %dec_label_pc_8048693

dec_label_pc_8048875:                             ; preds = %dec_label_pc_80486cc
  %v0_8048875 = load i32, i32* @global_var_804a048.8, align 4
  store i32 %v0_8048875, i32* %eax.global-to-local, align 4
  %v1_804887a = icmp eq i32 %v0_8048875, 0
  %v1_804887c = icmp eq i1 %v1_804887a, false
  br i1 %v1_804887c, label %dec_label_pc_8048893, label %dec_label_pc_804887e

dec_label_pc_804887e:                             ; preds = %dec_label_pc_8048875
  %v0_804887e = load i32, i32* %esp.global-to-local, align 4
  %v1_8048881 = add i32 %v0_804887e, -16
  %v2_8048881 = inttoptr i32 %v1_8048881 to i32*
  store i32 ptrtoint ([26 x i8]* @global_var_8048b01.12 to i32), i32* %v2_8048881, align 4
  %v3_8048886 = call i32 @puts(i8* %stack_var_-280.0)
  store i32 %v3_8048886, i32* %eax.global-to-local, align 4
  %v0_804888b = load i32, i32* %esp.global-to-local, align 4
  %v1_804888b = add i32 %v0_804888b, 16
  br label %dec_label_pc_8048693

dec_label_pc_8048893:                             ; preds = %dec_label_pc_8048875
  store i32 %v0_8048875, i32* %eax.global-to-local, align 4
  %v0_8048898 = load i32, i32* %esp.global-to-local, align 4
  %v2_804889b = add i32 %v0_8048898, -16
  %v3_804889b = inttoptr i32 %v2_804889b to i32*
  store i32 %v0_8048875, i32* %v3_804889b, align 4
  %tmp132 = bitcast i8* %stack_var_-280.0 to i32*
  call void @free(i32* %tmp132)
  store i32 ptrtoint (i32* @1 to i32), i32* %eax.global-to-local, align 4
  %v0_80488a1 = load i32, i32* %esp.global-to-local, align 4
  %v2_80488a7 = inttoptr i32 %v0_80488a1 to i32*
  store i32 ptrtoint ([30 x i8]* @global_var_8048b81.14 to i32), i32* %v2_80488a7, align 4
  %v3_80488ac = call i32 @puts(i8* %stack_var_-280.0)
  store i32 %v3_80488ac, i32* %eax.global-to-local, align 4
  %v0_80488b1 = load i32, i32* %esp.global-to-local, align 4
  %v1_80488b1 = add i32 %v0_80488b1, 16
  br label %dec_label_pc_8048693

dec_label_pc_80488b9:                             ; preds = %dec_label_pc_80486cc
  %v0_80488b9 = load i32, i32* %esp.global-to-local, align 4
  %v1_80488bc = add i32 %v0_80488b9, -16
  %v2_80488bc = inttoptr i32 %v1_80488bc to i32*
  store i32 ptrtoint ([20 x i8]* @global_var_8048b9f.15 to i32), i32* %v2_80488bc, align 4
  %v3_80488c1 = call i32 @puts(i8* %stack_var_-280.0)
  %v0_80488c6 = load i32, i32* %esp.global-to-local, align 4
  %v0_80488c9 = load i32, i32* @global_var_804a040.2, align 4
  %v2_80488d1 = add i32 %v0_80488c6, 8
  %v3_80488d1 = inttoptr i32 %v2_80488d1 to i32*
  store i32 %v0_80488c9, i32* %v3_80488d1, align 4
  %v1_80488d2 = add i32 %v0_80488c6, 4
  %v2_80488d2 = inttoptr i32 %v1_80488d2 to i32*
  store i32 256, i32* %v2_80488d2, align 4
  store i32 %v2_8048714, i32* %eax.global-to-local, align 4
  %v3_80488dd = inttoptr i32 %v0_80488c6 to i32*
  store i32 %v2_8048714, i32* %v3_80488dd, align 4
  %v2_80488de = load i8*, i8** %stack_var_-276, align 4
  %v3_80488de = ptrtoint i8* %v2_80488de to i32
  %v6_80488de = call i8* @fgets(i8* %stack_var_-280.0, i32 %v3_80488de, %_IO_FILE* bitcast (i32* @1 to %_IO_FILE*))
  %v0_80488e3 = load i32, i32* %esp.global-to-local, align 4
  store i32 %v2_8048714, i32* %eax.global-to-local, align 4
  %v3_80488ef = inttoptr i32 %v0_80488e3 to i32*
  store i32 %v2_8048714, i32* %v3_80488ef, align 4
  %v3_80488f0 = call i8* @strdup(i8* %stack_var_-280.0)
  %v5_80488f0 = ptrtoint i8* %v3_80488f0 to i32
  %v0_80488f5 = load i32, i32* %esp.global-to-local, align 4
  store i32 %v5_80488f0, i32* @global_var_804a04c.16, align 4
  store i32 %v5_80488f0, i32* %eax.global-to-local, align 4
  %v2_8048905 = add i32 %v0_80488f5, 4
  %v3_8048905 = inttoptr i32 %v2_8048905 to i32*
  store i32 %v5_80488f0, i32* %v3_8048905, align 4
  %v2_8048906 = inttoptr i32 %v0_80488f5 to i32*
  store i32 ptrtoint ([64 x i8]* @global_var_8048bb4.17 to i32), i32* %v2_8048906, align 4
  %v1_804890b = call i32 (i8*, ...) @printf(i8* bitcast (i32* @1 to i8*))
  store i32 %v1_804890b, i32* %eax.global-to-local, align 4
  %v0_8048910 = load i32, i32* %esp.global-to-local, align 4
  %v1_8048910 = add i32 %v0_8048910, 16
  br label %dec_label_pc_8048693

dec_label_pc_8048915:                             ; preds = %dec_label_pc_80486cc
  %v0_8048915 = load i32, i32* @global_var_804a048.8, align 4
  store i32 %v0_8048915, i32* %eax.global-to-local, align 4
  %v1_804891a = icmp eq i32 %v0_8048915, 0
  br i1 %v1_804891a, label %dec_label_pc_804893f, label %dec_label_pc_804891e

dec_label_pc_804891e:                             ; preds = %dec_label_pc_8048915
  store i32 %v0_8048915, i32* %eax.global-to-local, align 4
  %v1_8048923 = add i32 %v0_8048915, 64
  %v2_8048923 = inttoptr i32 %v1_8048923 to i32*
  %v3_8048923 = load i32, i32* %v2_8048923, align 4
  store i32 %v3_8048923, i32* %eax.global-to-local, align 4
  %v10_8048926 = icmp eq i32 %v3_8048923, 1801680230
  %v1_804892b = icmp eq i1 %v10_8048926, false
  br i1 %v1_804892b, label %dec_label_pc_804893f, label %dec_label_pc_804892d

dec_label_pc_804892d:                             ; preds = %dec_label_pc_804891e
  %v0_804892d = load i32, i32* %esp.global-to-local, align 4
  %v1_8048930 = add i32 %v0_804892d, -16
  %v2_8048930 = inttoptr i32 %v1_8048930 to i32*
  store i32 ptrtoint ([14 x i8]* @global_var_8048bf4.18 to i32), i32* %v2_8048930, align 4
  %v3_8048935 = call i32 @system(i8* %stack_var_-280.0)
  br label %dec_label_pc_804894f

dec_label_pc_804893f:                             ; preds = %dec_label_pc_804891e, %dec_label_pc_8048915
  %v0_804893f = load i32, i32* %esp.global-to-local, align 4
  %v1_8048942 = add i32 %v0_804893f, -16
  %v2_8048942 = inttoptr i32 %v1_8048942 to i32*
  store i32 ptrtoint ([7 x i8]* @global_var_8048c02.19 to i32), i32* %v2_8048942, align 4
  %v3_8048947 = call i32 @puts(i8* %stack_var_-280.0)
  br label %dec_label_pc_804894f

dec_label_pc_804894f:                             ; preds = %dec_label_pc_804893f, %dec_label_pc_804892d
  %storemerge = phi i32 [ %v3_8048935, %dec_label_pc_804892d ], [ %v3_8048947, %dec_label_pc_804893f ]
  store i32 %storemerge, i32* %eax.global-to-local, align 4
  %v0_804893a.sink = load i32, i32* %esp.global-to-local, align 4
  %v1_804893a = add i32 %v0_804893a.sink, 16
  br label %dec_label_pc_8048693

; uselistorder directives
  uselistorder i32 %v0_8048915, { 1, 0, 2, 3 }
  uselistorder i32 %v5_80488f0, { 0, 2, 1 }
  uselistorder i32 %v0_8048875, { 1, 0, 2, 3 }
  uselistorder i32 %v0_8048822, { 1, 0, 4, 3, 2, 5, 6 }
  uselistorder i32 %v0_80487fe, { 1, 0, 2 }
  uselistorder i32 %v0_8048773, { 1, 0, 2 }
  uselistorder i32 %v4_80486cc, { 1, 0 }
  uselistorder i32 %v0_80486af, { 1, 0, 2, 3 }
  uselistorder i8* %stack_var_-280.0, { 15, 14, 11, 12, 13, 9, 10, 8, 7, 6, 5, 4, 3, 2, 1, 0 }
  uselistorder i32 %v2_8048714, { 3, 2, 1, 0, 4, 5, 6, 7, 8, 9, 10, 11 }
  uselistorder i8** %stack_var_-276, { 2, 3, 1, 0 }
  uselistorder i32* %esp.global-to-local, { 25, 28, 1, 2, 3, 4, 5, 27, 6, 7, 8, 9, 10, 11, 12, 13, 14, 26, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 0, 29 }
  uselistorder i32* %eax.global-to-local, { 7, 0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 36, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 }
  uselistorder i32 (i8*)* @strlen, { 1, 0 }
  uselistorder i8* (i8*, i8*, i32)* @strncpy, { 1, 0 }
  uselistorder i32 30, { 0, 2, 1, 3 }
  uselistorder i8* (i8*, i32, %_IO_FILE*)* @fgets, { 2, 1, 0 }
  uselistorder %_IO_FILE* bitcast (i32* @1 to %_IO_FILE*), { 2, 0, 1 }
  uselistorder i32 ptrtoint (i32* @1 to i32), { 3, 0, 1, 2 }
  uselistorder i32 256, { 1, 2, 0, 3 }
  uselistorder i32 8, { 4, 0, 1, 2, 3 }
  uselistorder i32 4, { 4, 5, 0, 1, 2, 3, 6 }
  uselistorder i32 16777216, { 1, 0, 3, 2 }
  uselistorder i1 false, { 1, 2, 3, 0 }
  uselistorder i32 ()* @getchar, { 1, 0 }
  uselistorder i32 (i8*, ...)* @printf, { 1, 0, 5, 4, 3, 2 }
  uselistorder i32* @1, { 1, 0, 2 }
  uselistorder i8* bitcast (i32* @1 to i8*), { 5, 4, 0, 1, 2, 3, 6 }
  uselistorder i32 -16, { 8, 9, 7, 5, 6, 3, 4, 0, 1, 2, 10 }
  uselistorder i32 (i8*)* @puts, { 5, 4, 3, 2, 1, 0 }
  uselistorder i32 0, { 7, 8, 9, 1, 2, 6, 0, 3, 4, 5 }
  uselistorder i32 1, { 7, 6, 5, 0, 2, 3, 1, 4 }
  uselistorder label %dec_label_pc_8048693, { 6, 5, 4, 3, 2, 1, 0, 7, 8 }
}

declare i32 @printf(i8*, ...) local_unnamed_addr

declare void @free(i32*) local_unnamed_addr

declare i8* @strdup(i8*) local_unnamed_addr

declare i32 @getchar() local_unnamed_addr

declare i8* @fgets(i8*, i32, %_IO_FILE*) local_unnamed_addr

declare i32* @malloc(i32) local_unnamed_addr

declare i32 @puts(i8*) local_unnamed_addr

declare i32 @system(i8*) local_unnamed_addr

declare i32 @strlen(i8*) local_unnamed_addr

declare i8* @strncpy(i8*, i8*, i32) local_unnamed_addr

declare i8* @__decompiler_undefined_function_1() local_unnamed_addr
