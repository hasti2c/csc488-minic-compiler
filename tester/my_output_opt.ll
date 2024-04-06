; ModuleID = 'my_output_opt.bc'
source_filename = "output.bc"
target triple = "aarch64-unknown-linux-gnu"

declare i32 @getint()

declare void @putint(i32)

declare void @putcharacter(i8)

declare void @putnewline()

define i32 @f(i32 %0) {
f_entry:
  br label %cond

cond:                                             ; preds = %step, %f_entry
  %1 = phi i32 [ %1, %step ], [ %0, %f_entry ]
  %2 = phi i32 [ %4, %step ], [ 0, %f_entry ]
  %3 = icmp slt i32 %2, 100000000
  br i1 %3, label %body, label %after

body:                                             ; preds = %cond
  br label %step

step:                                             ; preds = %body
  %4 = add i32 %2, 1
  br label %cond

after:                                            ; preds = %cond
  ret i32 %1
}

define i32 @main() {
main_entry:
  %0 = call i32 @f(i32 10)
  call void @putint(i32 %0)
  ret i32 0
}
