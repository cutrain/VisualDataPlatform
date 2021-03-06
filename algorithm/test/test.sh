#! /bin/bash
export VD_PATH=`(cd ..;pwd)`
ct() {
	echo -ne "\033[$1;1m$2\033[0m"
}

cnt=0

ct 33 "start compile\n"
make && { ct 31 "make failed\n"} || { ct 32 "make succeed\n"}

for file in ./test/*
do
	if [[ -f $file && $file == *.js && $file != */common.js ]]
	then
		echo -ne "Now running test : "
		ct 33 "$file : "
		error=`node $file 2>&1`
		if [ ! -z "$error" ]
		then
			cnt=`expr $cnt + 1`
			ct 31 "failed\n$error\n"
		else
			ct 32 "passed\n"
		fi
	fi
done

[ $cnt -ne 0 ] && { ct 31 "$cnt test(s) failed\n"} || { ct 32 "all tests passed\n"}

