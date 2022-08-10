#!/bin/bash

./sorting > sorting_out

value=$?

if [ "$value" -eq 0 ]; 
then
	let value=12
else
	let value=value-10
	let value=value*2
fi

printf "\n*******************************************************\n"
printf "*                                                     *\n"
printf "*              TESTING PROGRAM COMPLETE               *\n"
printf "*                                                     *\n"
printf "*******************************************************\n"

if [ "$value" -lt 12 ];
then
	printf "\nPoints earned: %d\n" "$value"
	printf "You must score 12 points in the main test in order to continue.\nExiting...\n"
	exit $value
else
	printf "\nPoints before file comparison: %d\n\n" "$value"
fi

printf "Checking the heap->print output vs. expected output ...\n"

first=$(head -1 sorting_out)
first_expected="PRINT: 31 11 59 84 34 92 39 72 24 98 17 73 99 13 53 12 28 22 29 11 66 21 16 74 20 22 35 79 17 38 "
second=$(tail -1 sorting_out)
second_expected="OUTPUT: 31 11 59 84 34 92 39 72 24 98 17 73 99 13 53 12 28 22 29 11 66 21 16 74 20 22 35 79 17 38 "

printf "\nCorrect heap->print output: \"%s\"\n" "$first_expected"
printf "Your heap->print output   : \"%s\"\n" "$first"

if [ "$first" == "$first_expected" ];
then
	let value=value+2
	printf "\nYour heap->print function is correctly producing output. +2 points.\n\n"
else
	printf "\nYour heap->print function is not producing the correct output.\n\nFinal points earned: %d\n" "$value"
	exit $value
fi

printf "Correct sortPeople output: \"%s\"\n" "$second_expected"
printf "Your sortPeople output   : \"%s\"\n" "$second"
if [ "$second" == "$second_expected" ];
then
	let value=value+6
	printf "\nYour sortPeople function is correctly producing output. +6 points.\n\n"
else
	printf "\nYour sortPeople function is not producing the correct output.\n\nFinal points earned: %d\n" "$value"
	exit $value
fi

printf "Grading complete. Final points earned: %d\n" "$value"
exit 0
