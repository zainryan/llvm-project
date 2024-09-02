#include "AMDGPUDumpPreRegAllocCode.h"
#include "llvm/CodeGen/MIRPrinter.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/InitializePasses.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/raw_ostream.h"
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

  // Dump the MIR to the file
  printMIR(DumpFile, MF);

  return false;
}

void AMDGPUDumpPreRegAllocCode::getAnalysisUsage(AnalysisUsage &AU) const {
  MachineFunctionPass::getAnalysisUsage(AU);
}
