#! bin/bash
read first second third
echo "input first $first"
echo "input second $second"
echo "input third $third"
echo "enter the name of file"
read file_name
if [ -d $file_name ]; then
	echo "it is a dir"
elif [ -f $file_name ]; then
	echo "it is a file"
elif [ -c $file_name -o -b $file_name ]; then 
	echo "it is a device file"
else 
	echo "dont know"
fi
read op
case $op in
	Q)
		echo "QUIT"
		;;
	*)
		echo "invalid op"
		;;
esac

for x in "1" "2" "3"
do
	echo "$x is x"
done
num=1
while [ $num -le 20 ]
do
	out=`expr $num \* $num`
	echo `expr $num \* $num`
	echo $out
	num=`expr $num + 1`
done

