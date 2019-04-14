#! bin/bash
var=1
while [ $var -le 8 ]
do
	echo `expr $var \* $var`
	((var = var+1))
done

for ((i=1; i<10;i++))
do
	for((j=10-i;j>0;j--))
	do
		echo -n '*'
	done
	echo
done
