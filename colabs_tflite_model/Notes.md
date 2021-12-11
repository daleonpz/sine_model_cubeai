# Debug mode
arm-none-eabi-size   sine_AI.elf 
arm-none-eabi-objdump -h -S  sine_AI.elf  > "sine_AI.list"
arm-none-eabi-objcopy  -O binary  sine_AI.elf  "sine_AI.bin"
text    data     bss     dec     hex filename
38680     2024   17328   58032    e2b0 sine_AI.elf
Finished building: default.size.stdout

Finished building: sine_AI.bin

Finished building: sine_AI.list

Output: 0.944097 | Duration: 211
Output: 0.944097 | Duration: 210
Output: 0.944097 | Duration: 213
Output: 0.944097 | Duration: 210
Output: 0.944097 | Duration: 211
Output: 0.944097 | Duration: 212
Output: 0.944097 | Duration: 213
Output: 0.944097 | Duration: 210
Output: 0.944097 | Duration: 211
Output: 0.944097 | Duration: 209
Output: 0.944097 | Duration: 211
Output: 0.944097 | Duration: 213
Output: 0.944097 | Duration: 210
Output: 0.944097 | Duration: 212
Output: 0.944097 | Duration: 210
Output: 0.944097 | Duration: 210

# Release mode
Finished building target: sine_AI.elf

arm-none-eabi-size   sine_AI.elf 
arm-none-eabi-objdump -h -S  sine_AI.elf  > "sine_AI.list"
arm-none-eabi-objcopy  -O binary  sine_AI.elf  "sine_AI.bin"
text       data     bss     dec     hex filename
21000    1660   17324   39984    9c30 sine_AI.elf
Finished building: default.size.stdout

Finished building: sine_AI.bin

Finished building: sine_AI.list


Flash   = text + data 
RAM     = data + bss



