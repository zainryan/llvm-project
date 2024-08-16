#include "AMDGPUDumpPreRegAllocCode.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/InitializePasses.h"
#include "llvm/Support/FileSystem.h"
#include <cstdlib>
#include <string>

using namespace llvm;

char AMDGPUDumpPreRegAllocCode::ID = 0;

bool AMDGPUDumpPreRegAllocCode::runOnMachineFunction(MachineFunction &MF) {
  // Check if the environment variable is set
  const char *DumpFileName = std::getenv("AMD_DUMP_PRE_REG_ALLOC_FILE");
  if (!DumpFileName) {
    return false;
  }

  // Open the file specified by the environment variable
  std::error_code EC;
  raw_fd_ostream DumpFile(DumpFileName, EC, sys::fs::OF_Text);

  if (EC) {
    errs() << "Error opening file " << DumpFileName << ": " << EC.message() << "\n";
    return false;
  }

  // Dump the machine code to the file
  DumpFile << "Pre-RegAlloc Machine Code for function: " << MF.getName() << "\n";

  for (auto &MBB : MF) {
    DumpFile << "Basic Block: " << MBB.getName() << "\n";
    for (auto &MI : MBB) {
      MI.print(DumpFile);
    }
  }

  return false;
}

void AMDGPUDumpPreRegAllocCode::getAnalysisUsage(AnalysisUsage &AU) const {
  MachineFunctionPass::getAnalysisUsage(AU);
}
