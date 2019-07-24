#!/bin/sh
qemu-system-x86_64 \
	-m 4G \
	-drive if=pflash,format=raw,readonly,file=$HOME/OVMF/OVMF_CODE.fd \
	-drive if=pflash,format=raw,file=$HOME/OVMF/OVMF_VARS.fd \
	-drive dir=fs,driver=vvfat,rw=on \
	$@
