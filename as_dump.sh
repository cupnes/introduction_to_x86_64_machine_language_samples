#!/bin/bash

set -uex
# set -ue

# echo $@ | as -a



work_dir=$(mktemp -d)
echo $@ | as -o ${work_dir}/a.out
objdump -d ${work_dir}/a.out
rm -r ${work_dir}
