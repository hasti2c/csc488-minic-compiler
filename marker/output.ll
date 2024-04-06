; ModuleID = 'output.bc'
source_filename = "output.bc"
target triple = "aarch64-unknown-linux-gnu"

@number = common global [25 x i32] zeroinitializer

declare i32 @getint()

declare void @putint(i32)

declare void @putcharacter(i8)

declare void @putnewline()

define void @quicksort(i32 %0, i32 %1) {
quicksort_entry:
  %first = alloca i32, align 4
  store i32 %0, ptr %first, align 4
  %last = alloca i32, align 4
  store i32 %1, ptr %last, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %pivot = alloca i32, align 4
  %temp = alloca i32, align 4
  %2 = load i32, ptr %first, align 4
  %3 = load i32, ptr %last, align 4
  %4 = icmp slt i32 %2, %3
  br i1 %4, label %then, label %after

then:                                             ; preds = %quicksort_entry
  %5 = load i32, ptr %first, align 4
  store i32 %5, ptr %pivot, align 4
  %6 = load i32, ptr %first, align 4
  store i32 %6, ptr %i, align 4
  %7 = load i32, ptr %last, align 4
  store i32 %7, ptr %j, align 4
  br label %cond

after:                                            ; preds = %after1, %quicksort_entry
  ret void

cond:                                             ; preds = %step, %then
  %8 = load i32, ptr %i, align 4
  %9 = load i32, ptr %j, align 4
  %10 = icmp slt i32 %8, %9
  br i1 %10, label %body, label %after1

body:                                             ; preds = %cond
  br label %cond2

step:                                             ; preds = %after11
  br label %cond

after1:                                           ; preds = %cond
  %11 = load i32, ptr %pivot, align 4
  %12 = getelementptr [25 x i32], ptr @number, i32 0, i32 %11
  %13 = load i32, ptr %12, align 4
  store i32 %13, ptr %temp, align 4
  %14 = load i32, ptr %pivot, align 4
  %15 = load i32, ptr %j, align 4
  %16 = getelementptr [25 x i32], ptr @number, i32 0, i32 %15
  %17 = load i32, ptr %16, align 4
  %18 = getelementptr [25 x i32], ptr @number, i32 0, i32 %14
  store i32 %17, ptr %18, align 4
  %19 = load i32, ptr %j, align 4
  %20 = load i32, ptr %temp, align 4
  %21 = getelementptr [25 x i32], ptr @number, i32 0, i32 %19
  store i32 %20, ptr %21, align 4
  %22 = load i32, ptr %first, align 4
  %23 = load i32, ptr %j, align 4
  %24 = sub i32 %23, 1
  call void @quicksort(i32 %22, i32 %24)
  %25 = load i32, ptr %j, align 4
  %26 = add i32 %25, 1
  %27 = load i32, ptr %last, align 4
  call void @quicksort(i32 %26, i32 %27)
  br label %after

cond2:                                            ; preds = %step4, %body
  %28 = load i32, ptr %i, align 4
  %29 = getelementptr [25 x i32], ptr @number, i32 0, i32 %28
  %30 = load i32, ptr %29, align 4
  %31 = load i32, ptr %pivot, align 4
  %32 = getelementptr [25 x i32], ptr @number, i32 0, i32 %31
  %33 = load i32, ptr %32, align 4
  %34 = icmp sle i32 %30, %33
  br i1 %34, label %slow, label %out

body3:                                            ; preds = %out
  %35 = load i32, ptr %i, align 4
  %36 = add i32 %35, 1
  store i32 %36, ptr %i, align 4
  br label %step4

step4:                                            ; preds = %body3
  br label %cond2

after5:                                           ; preds = %out
  br label %cond6

slow:                                             ; preds = %cond2
  %37 = load i32, ptr %i, align 4
  %38 = load i32, ptr %last, align 4
  %39 = icmp slt i32 %37, %38
  br label %out

out:                                              ; preds = %slow, %cond2
  %40 = phi i1 [ %34, %cond2 ], [ %39, %slow ]
  br i1 %40, label %body3, label %after5

cond6:                                            ; preds = %step8, %after5
  %41 = load i32, ptr %j, align 4
  %42 = getelementptr [25 x i32], ptr @number, i32 0, i32 %41
  %43 = load i32, ptr %42, align 4
  %44 = load i32, ptr %pivot, align 4
  %45 = getelementptr [25 x i32], ptr @number, i32 0, i32 %44
  %46 = load i32, ptr %45, align 4
  %47 = icmp sgt i32 %43, %46
  br i1 %47, label %body7, label %after9

body7:                                            ; preds = %cond6
  %48 = load i32, ptr %j, align 4
  %49 = sub i32 %48, 1
  store i32 %49, ptr %j, align 4
  br label %step8

step8:                                            ; preds = %body7
  br label %cond6

after9:                                           ; preds = %cond6
  %50 = load i32, ptr %i, align 4
  %51 = load i32, ptr %j, align 4
  %52 = icmp slt i32 %50, %51
  br i1 %52, label %then10, label %after11

then10:                                           ; preds = %after9
  %53 = load i32, ptr %i, align 4
  %54 = getelementptr [25 x i32], ptr @number, i32 0, i32 %53
  %55 = load i32, ptr %54, align 4
  store i32 %55, ptr %temp, align 4
  %56 = load i32, ptr %i, align 4
  %57 = load i32, ptr %j, align 4
  %58 = getelementptr [25 x i32], ptr @number, i32 0, i32 %57
  %59 = load i32, ptr %58, align 4
  %60 = getelementptr [25 x i32], ptr @number, i32 0, i32 %56
  store i32 %59, ptr %60, align 4
  %61 = load i32, ptr %j, align 4
  %62 = load i32, ptr %temp, align 4
  %63 = getelementptr [25 x i32], ptr @number, i32 0, i32 %61
  store i32 %62, ptr %63, align 4
  br label %after11

after11:                                          ; preds = %then10, %after9
  br label %step
}

define i32 @main() {
main_entry:
  %i = alloca i32, align 4
  %count = alloca i32, align 4
  %0 = call i32 @getint()
  store i32 %0, ptr %count, align 4
  store i32 0, ptr %i, align 4
  br label %cond

cond:                                             ; preds = %step, %main_entry
  %1 = load i32, ptr %i, align 4
  %2 = load i32, ptr %count, align 4
  %3 = icmp slt i32 %1, %2
  br i1 %3, label %body, label %after

body:                                             ; preds = %cond
  %4 = load i32, ptr %i, align 4
  %5 = call i32 @getint()
  %6 = getelementptr [25 x i32], ptr @number, i32 0, i32 %4
  store i32 %5, ptr %6, align 4
  br label %step

step:                                             ; preds = %body
  %7 = load i32, ptr %i, align 4
  %8 = add i32 %7, 1
  store i32 %8, ptr %i, align 4
  br label %cond

after:                                            ; preds = %cond
  %9 = load i32, ptr %count, align 4
  %10 = sub i32 %9, 1
  call void @quicksort(i32 0, i32 %10)
  store i32 0, ptr %i, align 4
  br label %cond1

cond1:                                            ; preds = %step3, %after
  %11 = load i32, ptr %i, align 4
  %12 = load i32, ptr %count, align 4
  %13 = icmp slt i32 %11, %12
  br i1 %13, label %body2, label %after4

body2:                                            ; preds = %cond1
  %14 = load i32, ptr %i, align 4
  %15 = getelementptr [25 x i32], ptr @number, i32 0, i32 %14
  %16 = load i32, ptr %15, align 4
  call void @putint(i32 %16)
  br label %step3

step3:                                            ; preds = %body2
  %17 = load i32, ptr %i, align 4
  %18 = add i32 %17, 1
  store i32 %18, ptr %i, align 4
  br label %cond1

after4:                                           ; preds = %cond1
  ret i32 0
}
