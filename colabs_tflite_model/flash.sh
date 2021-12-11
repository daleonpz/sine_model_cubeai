#!/bin/sh

CLI_PATH="/home/me/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin"
BIN="Debug/sine_AI.bin"
CLI="${CLI_PATH}/STM32_Programmer_CLI -c port=swd freq=4000"

${CLI}  -w ${BIN} 0x08000000  -rst
