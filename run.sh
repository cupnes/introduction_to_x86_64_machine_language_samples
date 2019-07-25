#!/bin/bash

set -ue
# set -uex

if [ $# -lt 1 ]; then
	echo "usage: $0 FILESYSTEM_PATH [QEMU_ADDITIONAL_OPTION ...]" > /dev/stderr
	exit 1
fi

fs_path=$1
shift

qemu-system-x86_64 \
	-m 4G \
	-drive if=pflash,format=raw,readonly,file=$HOME/OVMF/OVMF_CODE.fd \
	-drive if=pflash,format=raw,file=$HOME/OVMF/OVMF_VARS.fd \
	-drive dir=${fs_path},driver=vvfat,rw=on \
	$@
