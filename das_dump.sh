#!/bin/bash

# set -uex
set -ue

work_dir=$(mktemp -d)
for b in $@; do
	printf "\x${b}" >>${work_dir}/a.bin
done
objdump -D -b binary -m i386:x86-64 ${work_dir}/a.bin
rm -r ${work_dir}
