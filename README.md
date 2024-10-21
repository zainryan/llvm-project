export AMDGPU_ARCH=gfx1031
export AMD_DUMP_PRE_REG_ALLOC_FILE=pre.log
export WRITE_REG_ALLOC_FILE=alloc.txt
or export READ_REG_ALLOC_FILE=alloc.txt

llc -march=amdgcn -mcpu=$AMDGPU_ARCH -filetype=obj -o foo.o foo.ll -O3
