#!/bin/bash

res_dir=./resources
players_dir="$res_dir/players"

run_bot() {
	map_name=./resources/maps
	echo "$1 vs $2 on map $3"
	run_map "$map_name/$3" "$1" "$players_dir/$2"
	run_map "$map_name/$3" "$players_dir/$2" "$1"
}

run_map() {
	# echo "$1 $2 $3"
	for i in 0 1 2
	do
		"$res_dir"/filler_vm -f "$1" -p1 "$2" -p2 "$3" > out
		error=$(cat out | grep "An error occured. aborting...")
		winner=$(cat filler.trace | grep won)
		echo "$winner"
		if [ ! -z "$error" ];
		then
			# mv logs.txt error_logs.txt
			mv out error
			exit
		fi
	done
}

test_player() {
	for bot in abanlin.filler champely.filler hcao.filler carli.filler grati.filler superjeannot.filler
	do
		run_bot "$1" "$bot" "$2"
	done
}

test_player "./$1" "$2"