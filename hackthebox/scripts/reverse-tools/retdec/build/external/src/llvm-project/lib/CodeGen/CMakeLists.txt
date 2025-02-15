add_llvm_library(LLVMCodeGen

  IntrinsicLowering.cpp

#  AggressiveAntiDepBreaker.cpp
#  AllocationOrder.cpp
#  Analysis.cpp
#  AtomicExpandPass.cpp
#  BasicTargetTransformInfo.cpp
#  BranchFolding.cpp
#  BuiltinGCs.cpp
#  CalcSpillWeights.cpp
#  CallingConvLower.cpp
#  CodeGen.cpp
#  CodeGenPrepare.cpp
#  CriticalAntiDepBreaker.cpp
#  DeadMachineInstructionElim.cpp
#  DetectDeadLanes.cpp
#  DFAPacketizer.cpp
#  DwarfEHPrepare.cpp
#  EarlyIfConversion.cpp
#  EdgeBundles.cpp
#  ExecutionDepsFix.cpp
#  ExpandISelPseudos.cpp
#  ExpandPostRAPseudos.cpp
#  FaultMaps.cpp
#  FuncletLayout.cpp
#  GCMetadata.cpp
#  GCMetadataPrinter.cpp
#  GCRootLowering.cpp
#  GCStrategy.cpp
#  GlobalMerge.cpp
#  IfConversion.cpp
#  ImplicitNullChecks.cpp
#  InlineSpiller.cpp
#  InterferenceCache.cpp
#  InterleavedAccessPass.cpp
#  LatencyPriorityQueue.cpp
#  LexicalScopes.cpp
#  LiveDebugValues.cpp
#  LiveDebugVariables.cpp
#  LiveIntervalAnalysis.cpp
#  LiveInterval.cpp
#  LiveIntervalUnion.cpp
#  LivePhysRegs.cpp
#  LiveRangeCalc.cpp
#  LiveRangeEdit.cpp
#  LiveRegMatrix.cpp
#  LiveStackAnalysis.cpp
#  LiveVariables.cpp
#  LLVMTargetMachine.cpp
#  LocalStackSlotAllocation.cpp
#  LowerEmuTLS.cpp
#  MachineBasicBlock.cpp
#  MachineBlockFrequencyInfo.cpp
#  MachineBlockPlacement.cpp
#  MachineBranchProbabilityInfo.cpp
#  MachineCombiner.cpp
#  MachineCopyPropagation.cpp
#  MachineCSE.cpp
#  MachineDominanceFrontier.cpp
#  MachineDominators.cpp
#  MachineFunctionAnalysis.cpp
#  MachineFunction.cpp
#  MachineFunctionPass.cpp
#  MachineFunctionPrinterPass.cpp
#  MachineInstrBundle.cpp
#  MachineInstr.cpp
#  MachineLICM.cpp
#  MachineLoopInfo.cpp
#  MachineModuleInfo.cpp
#  MachineModuleInfoImpls.cpp
#  MachinePassRegistry.cpp
#  MachinePostDominators.cpp
#  MachineRegionInfo.cpp
#  MachineRegisterInfo.cpp
#  MachineScheduler.cpp
#  MachineSink.cpp
#  MachineSSAUpdater.cpp
#  MachineTraceMetrics.cpp
#  MachineVerifier.cpp
#  PatchableFunction.cpp
#  MIRPrinter.cpp
#  MIRPrintingPass.cpp
#  OptimizePHIs.cpp
#  ParallelCG.cpp
#  PeepholeOptimizer.cpp
#  PHIElimination.cpp
#  PHIEliminationUtils.cpp
#  PostRAHazardRecognizer.cpp
#  PostRASchedulerList.cpp
#  PreISelIntrinsicLowering.cpp
#  ProcessImplicitDefs.cpp
#  PrologEpilogInserter.cpp
#  PseudoSourceValue.cpp
#  RegAllocBase.cpp
#  RegAllocBasic.cpp
#  RegAllocFast.cpp
#  RegAllocGreedy.cpp
#  RegAllocPBQP.cpp
#  RegisterClassInfo.cpp
#  RegisterCoalescer.cpp
#  RegisterPressure.cpp
#  RegisterScavenging.cpp
#  RenameIndependentSubregs.cpp
#  RegisterUsageInfo.cpp
#  RegUsageInfoCollector.cpp
#  RegUsageInfoPropagate.cpp
#  SafeStack.cpp
#  SafeStackColoring.cpp
#  SafeStackLayout.cpp
#  ScheduleDAG.cpp
#  ScheduleDAGInstrs.cpp
#  ScheduleDAGPrinter.cpp
#  ScoreboardHazardRecognizer.cpp
#  ShadowStackGCLowering.cpp
#  ShrinkWrap.cpp
#  SjLjEHPrepare.cpp
#  SlotIndexes.cpp
#  SpillPlacement.cpp
#  SplitKit.cpp
#  StackColoring.cpp
#  StackMapLivenessAnalysis.cpp
#  StackMaps.cpp
#  StackProtector.cpp
#  StackSlotColoring.cpp
#  TailDuplication.cpp
#  TailDuplicator.cpp
#  TargetFrameLoweringImpl.cpp
#  TargetInstrInfo.cpp
#  TargetLoweringBase.cpp
#  TargetLoweringObjectFileImpl.cpp
#  TargetOptionsImpl.cpp
#  TargetPassConfig.cpp
#  TargetRegisterInfo.cpp
#  TargetSchedule.cpp
#  TwoAddressInstructionPass.cpp
#  UnreachableBlockElim.cpp
#  VirtRegMap.cpp
#  WinEHPrepare.cpp
#  XRayInstrumentation.cpp

  ADDITIONAL_HEADER_DIRS
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/CodeGen
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/CodeGen/PBQP

  LINK_LIBS ${PTHREAD_LIB}
  )

add_dependencies(LLVMCodeGen intrinsics_gen)

#add_subdirectory(SelectionDAG)
#add_subdirectory(AsmPrinter)
#add_subdirectory(MIRParser)
#add_subdirectory(GlobalISel)
