#!/bin/bash

# set -uex
set -ue

work_dir=$(mktemp -d)

if [ $# -gt 0 ]; then
	if [ "$1" = "-f" ]; then
		shift
		as -o ${work_dir}/a.out $@
	else
		echo $@ | as -o ${work_dir}/a.out
	fi
else
	as -o ${work_dir}/a.out
fi

objdump -d ${work_dir}/a.out
rm -r ${work_dir}
