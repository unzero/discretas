#!/bin/bash/
rm res.txt
rm resul.txt
echo COMPILANDO
g++ $1.cpp -o $1
#g++ permut.cpp
g++ new_message.cpp -Wall
g++ equals.cpp -o equals
echo COMPILADO
echo EJECUTANDO
#g++ equals.cpp
#echo VERIFICANDO
#./a.out
for a in $(seq 1 $2)
do
	./a.out
	./$1
	cat output.txt >> res.txt

	cat input.txt >> alpha
	#cat input.txt > alpha.txt
done
echo COMPARANDO
./equals
echo FSH
