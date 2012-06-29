#!/bin/bash
set -e

function test {
	name=$1
	args=`cat $name.args`
	command="../my_grep $args"
	actual="$name.actual"
	expected="$name.expected"

	echo
	echo $name:
	echo "$ $command"

	rm -f $actual
	if [ -f $actual ]; then
		cat $actual | sh -c "$command" > $actual || true
	else
		sh -c "$command" > $actual || true
	fi
	diff -y $expected $actual || true
}

make
cd test

for file in *.args; do
	name="${file%.*}"
	test $name
done
