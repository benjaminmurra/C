#!/bin/bash

result=$(ls Lab1/ | grep -e 'Bonus' -e 'Challenge1' -e 'Challenge2' -v | wc -l)

if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab1/."
    exit -1
fi

result=$(ls Lab1/Challenge1/ | grep -e 'commands.hst' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab1/Challenge1."
    exit -1
fi

result=$(ls Lab1/Challenge2/ | grep -e 'generate.sh' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab1/Challenge2."
    exit -1
fi

ndirs=$(ls Lab1/ | wc -l)
if (( $ndirs == 3 )); then
    result=$(ls Lab1/Bonus/ | grep -e 'command.sh' -v | wc -l)
    if (( $result > 0 )); then
        echo "Failure. There is an extra file or folder present in Lab1/Bonus."
        exit -1
    fi
fi

exit 0
