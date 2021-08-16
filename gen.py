import re 

with open("./wasm_source.txt", "r") as f:
    lines = f.readlines()
    lines = [x.strip() for x in lines]

# XNNPACK_WASM_ASM_MICROKERNEL_SRCS /*.S/
asm_lines = [line for line in lines if re.search(r"\.S", line) is not None]
# XNNPACK_WASM_SIMD_SRCS
simd_lines = [line for line in lines if re.search(r"wasmsimd", line) is not None]
# XNNPACK_WASM_MICROKERNEL_SRCS
rest_lines = [line for line in lines if line not in asm_lines and line not in simd_lines]
assert len(lines) == len(asm_lines) + len(simd_lines) + len(rest_lines)

output = "SET(XNNPACK_WASM_ASM_MICROKERNEL_SRCS \n{})\nSET(XNNPACK_WASM_SIMD_SRCS \n{})\nSET(XNNPACK_WASM_MICROKERNEL_SRCS \n{})".format('\n'.join(asm_lines), '\n'.join(simd_lines), '\n'.join(rest_lines))
print(output)