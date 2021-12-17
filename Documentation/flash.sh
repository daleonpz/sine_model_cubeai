#!/bin/sh

PATH_PROGRAMMER="/home/me/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin"
PROGRAMMER="${PATH_PROGRAMMER}/STM32_Programmer_CLI"

echo "sudo ${PROGRAMMER} -c port=usb1 -w $1 0x08000000"

# sudo ./STM32_Programmer_CLI -c port=usb1 -w  ~/Downloads/temp/STM32CubeFunctionPack_DATALOG1_V1.3.0/Projects/STM32L4R9ZI-STWIN/Applications/HSDatalog/Binary/HSDatalog.bin 0x08000000 
