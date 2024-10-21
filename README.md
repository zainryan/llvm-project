export AMDGPU_ARCH=gfx1031<br>
export AMD_DUMP_PRE_REG_ALLOC_FILE=pre.log<br>
export WRITE_REG_ALLOC_FILE=alloc.txt<br>
or export READ_REG_ALLOC_FILE=alloc.txt<br>

llc -march=amdgcn -mcpu=$AMDGPU_ARCH -filetype=obj -o foo.o foo.ll -O3
