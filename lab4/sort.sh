#!/bin/sh
ARR=(1 8 6 9 2 4 7)
echo ${ARR[*]}

declare -i b

for ((i=0; i<7; i++)) do
	for ((j=0; j<7; j++)) do
		if [ "${ARR[i]}" -lt "${ARR[j]}" ]; then
			b=${ARR[$i]}
			ARR[$i]=${ARR[$j]}
			ARR[$j]=$b
		fi
	done
done

echo ${ARR[*]}
