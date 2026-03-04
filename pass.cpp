#include "llvm/IR/Analysis.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include <llvm/ADT/StringRef.h>
#include <llvm/Config/llvm-config.h>
#include <llvm/IR/Function.h>
#include <llvm/Support/Compiler.h>

using namespace llvm;

struct FunctionNamePass:PassInfoMixin<FunctionNamePass>{
    PreservedAnalyses run(Function&f,FunctionAnalysisManager &){
        errs()<<"[Functional name] Found: "<<f.getName()<<"\n";
        return PreservedAnalyses::all();
    }
};

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo(){
    return {
        LLVM_PLUGIN_API_VERSION,
        "FunctionNamePass",
        LLVM_VERSION_STRING,
        [](PassBuilder &pB){
            pB.registerPipelineParsingCallback([](StringRef name,FunctionPassManager &fPM,...){
                if(name=="func-names"){
                    fPM.addPass(FunctionNamePass());
                    return true;
                }
                return false;
            });
        }
    };
}