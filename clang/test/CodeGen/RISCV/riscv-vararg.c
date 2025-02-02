// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple riscv32 -S -emit-llvm \
// RUN: %s -o - | FileCheck --check-prefix=CHECK-RV32 %s

// CHECK-RV32-LABEL: @test_vararg(
// CHECK-RV32-NEXT:  entry:
// CHECK-RV32-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4, addrspace(5)
// CHECK-RV32-NEXT:    [[VA:%.*]] = alloca ptr, align 4, addrspace(5)
// CHECK-RV32-NEXT:    [[RETVAL2:%.*]] = alloca i32, align 4, addrspace(5)
// CHECK-RV32-NEXT:    store ptr [[FMT:%.*]], ptr addrspace(5) [[FMT_ADDR]], align 4
// CHECK-RV32-NEXT:    [[VA1:%.*]] = addrspacecast ptr addrspace(5) [[VA]] to ptr
// CHECK-RV32-NEXT:    call void @llvm.va_start(ptr [[VA1]])
// CHECK-RV32-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr addrspace(5) [[VA]], align 4
// CHECK-RV32-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 4
// CHECK-RV32-NEXT:    store ptr [[ARGP_NEXT]], ptr addrspace(5) [[VA]], align 4
// CHECK-RV32-NEXT:    [[TMP0:%.*]] = load i32, ptr [[ARGP_CUR]], align 4
// CHECK-RV32-NEXT:    store i32 [[TMP0]], ptr addrspace(5) [[RETVAL2]], align 4
// CHECK-RV32-NEXT:    [[VA3:%.*]] = addrspacecast ptr addrspace(5) [[VA]] to ptr
// CHECK-RV32-NEXT:    call void @llvm.va_end(ptr [[VA3]])
// CHECK-RV32-NEXT:    [[TMP1:%.*]] = load i32, ptr addrspace(5) [[RETVAL2]], align 4
// CHECK-RV32-NEXT:    ret i32 [[TMP1]]
//
int test_vararg(char *fmt,...) {
  __builtin_va_list va;
  __builtin_va_start(va, fmt);
  int retval = __builtin_va_arg(va, int);
  __builtin_va_end(va);
  return retval;
}
