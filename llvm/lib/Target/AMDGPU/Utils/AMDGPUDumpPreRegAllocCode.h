#ifndef LLVM_LIB_TARGET_AMDGPU_AMDGPUDUMPPREREGALLOCCODE_H
#define LLVM_LIB_TARGET_AMDGPU_AMDGPUDUMPPREREGALLOCCODE_H

#include "llvm/CodeGen/MachineFunctionPass.h"

namespace llvm {

class AMDGPUDumpPreRegAllocCode : public MachineFunctionPass {
public:
  static char ID;

  AMDGPUDumpPreRegAllocCode() : MachineFunctionPass(ID) {}

  bool runOnMachineFunction(MachineFunction &MF) override;

  void getAnalysisUsage(AnalysisUsage &AU) const override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_AMDGPU_AMDGPUDUMPPREREGALLOCCODE_H
