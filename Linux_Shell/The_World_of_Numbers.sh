read x
read y

sum=`expr $x + $y`
echo $sum
sum=`expr $x - $y`
echo $sum
sum=`expr $x \* $y`
echo $sum
sum=`expr $x / $y`
echo $sum
