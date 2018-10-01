//===- llvm-build generated file --------------------------------*- C++ -*-===//
//
// Component Library Depenedency Table
//
// Automatically generated file, do not edit!
//
//===----------------------------------------------------------------------===//

struct AvailableComponent {
  /// The name of the component.
  const char *Name;

  /// The name of the library for this component (or NULL).
  const char *Library;

  /// Whether the component is installed.
  bool IsInstalled;

  /// The list of libraries required when linking this component.
  const char *RequiredLibraries[10];
} AvailableComponents[27] = {
  { "all", nullptr, true, { "nativecodegen", "tablegen", "engine", "passes", "gtest_main", "all-targets" } },
  { "all-targets", nullptr, true, { "x86" } },
  { "analysis", "LLVMAnalysis", true, { "core", "support" } },
  { "asmparser", "LLVMAsmParser", true, { "core", "support" } },
  { "bitreader", "LLVMBitReader", true, { "core", "support" } },
  { "bitwriter", "LLVMBitWriter", true, { "analysis", "core", "support" } },
  { "codegen", "LLVMCodeGen", true, { "analysis", "bitreader", "bitwriter", "core", "mc", "scalaropts", "support", "target", "transformutils" } },
  { "core", "LLVMCore", true, { "support" } },
  { "engine", nullptr, true, { "native" } },
  { "gtest", "gtest", false, { "support" } },
  { "gtest_main", "gtest_main", false, { "gtest" } },
  { "instcombine", "LLVMInstCombine", true, { "analysis", "core", "support", "transformutils" } },
  { "ipo", "LLVMipo", true, { "analysis", "core", "instcombine", "irreader", "object", "scalaropts", "support", "transformutils" } },
  { "irreader", "LLVMIRReader", true, { "asmparser", "bitreader", "core", "support" } },
  { "mc", "LLVMMC", true, { "support" } },
  { "mcparser", "LLVMMCParser", true, { "mc", "support" } },
  { "native", nullptr, true, { "x86" } },
  { "nativecodegen", nullptr, true, { "x86codegen" } },
  { "object", "LLVMObject", true, { "bitreader", "core", "mc", "mcparser", "support" } },
  { "passes", "LLVMPasses", true, { "analysis", "codegen", "core", "ipo", "instcombine", "scalaropts", "support", "transformutils" } },
  { "scalaropts", "LLVMScalarOpts", true, { "analysis", "core", "instcombine", "support", "transformutils" } },
  { "support", "LLVMSupport", true, {  } },
  { "tablegen", "LLVMTableGen", true, { "support" } },
  { "target", "LLVMTarget", true, { "analysis", "core", "mc", "support" } },
  { "transformutils", "LLVMTransformUtils", true, { "analysis", "core", "support" } },
  { "x86", nullptr, true, { "x86codegen" } },
  { "x86codegen", "LLVMX86CodeGen", true, {  } },
};
