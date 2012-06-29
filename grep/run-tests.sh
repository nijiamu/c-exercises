#!/bin/bash
set -e

function test {
	name=$1
	args=`cat $name.args`
	command="../my_grep $args"
	echo
	echo $name:
	echo "$ $command"
	rm -f $name.actual
	if [ -f $name.input ]; then
		cat $name.input | $command > $name.actual || true
	else
		$command > $name.actual || true
	fi
	diff $name.expected $name.actual || true
}

make
cd test

for file in *.args; do
	name="${file%.*}"
	test $name
done
