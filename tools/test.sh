#!/bin/bash
#############################################################
# test.sh
# A command-lime tool to help do local tests on OI programs
# Author: learntocode1024
# Date: 2020-09-07
#############################################################
trap 'printf "\nKeyboard Interruption\nexiting...\n"; rm -rf "${DIR:?}"; exit' INT
# trap 'printf "\nKeyboard Interruption\nexiting...\n"; exit' INT
PWD=`pwd`
DIR=${PWD}/test.d
DATA=${DIR}/data
BIN=${DIR}/bin
LOCAL=${BIN}/local
ANS=${BIN}/ans
RAND=${BIN}/random

RED='\033[0;31m'
NC='\033[0m'

error() {
    echo -e "$0: ${RED}error:${NC} $@" >&2
    exit 1
}

t=""
mem=""
stat=""
i=${1:-10}

if [ -d "${DIR:?}" ]
then
    rm -rf "${DIR:?}/"
fi
mkdir "$DIR"
mkdir "$BIN"
mkdir "$DATA"

if ! [ -f ./local.cpp ] || ! [ -f ./random.cpp ] || ! [ -f ./ans.cpp ]
then
error "no C++ source files in ./"
fi
/usr/bin/g++ -g "./local.cpp" -o "$LOCAL" || error "Compiler Error"
/usr/bin/g++ -g "./ans.cpp" -o "$ANS" || error "Compiler Error"
/usr/bin/g++ -g "./random.cpp" -o "$RAND" || error "Compiler Error"

printf "Tested On "
date
flag=0

for cnt in $(seq 1 $i)
do
    "$RAND" > "$DATA/$cnt.in"
done
for cnt in $(seq 1 $i)
do
    "$ANS" < "$DATA/$cnt.in" > "$DATA/$cnt.out"
done

echo "Check Point   Status         Time Usage   Memory Usage"
for cnt in $(seq 1 $i)
do
    mem=""
    t=""
    /usr/bin/time -f "%e %M" -o "${DIR:?}/temp"  "$LOCAL" < "$DATA/$cnt.in" > "$DATA/my$cnt.out"
    t=$(cat "${DIR:?}/temp"  | awk '{print $1}')
    mem=$(cat "${DIR:?}/temp" | awk '{print $2}')
    t="${t}s"
    
    if diff "$DATA/$cnt.out" "$DATA/my$cnt.out" > /dev/null
    then
        stat="Accepted"
        rm -f "$DATA/$cnt.out" "$DATA/my$cnt.out" "$DATA/$cnt.in"
    else
        stat="Wrong Answer"
        flag=1
    fi
    if [ "$mem" -gt 4096 ]
    then
        mem="$(($mem/1024))MiB"
    else
        mem="${mem}KiB"
    fi
    printf "Point#%-8s%-15s%10s%15s\n" $cnt "$stat" $t $mem
done
if [ "$flag" -eq 0 ]
then
    echo ALL ACCEPTED!!!!!
    rm -rf "${DIR:?}"
else
    echo Failed
    rm -f "${DIR:?}/temp"
fi