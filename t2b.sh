#!/bin/bash

set -ue

if [ $# -ne 1 ]; then
	echo "Usage: $0 FILE" > /dev/stderr
	exit 1
fi

FILE=$1

cut -d'#' -f1 ${FILE} | cut -d':' -f2 | tr ' ' '\n' | tr '\t' '\n' | grep -v '^$' | while read val; do
	printf "\x${val}"
done
