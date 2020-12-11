#################################### Global ####################################
PROJECT=program-learning
set -e
cmd=$1
shift

if ! [ -d "$proj_root" ]; then
  exit 1;
fi

error() {
  printf "program-learning: \033[1;31merror: \033[0m%s\n" "$@" > /dev/stderr
  exit 1
}
warning() {
  printf "program-learning: \033[38;2;225;140;0mwarning: \033[0m%s\n" "$@"
}
############################## Project statistic ###############################
# shellcheck disable=SC2044
_stat() {
  total=0
  luogu=0
  NC=0
  EX=0
  CF=0
  for i in $(find . -name "*.cpp")
  do
    grep "// AC" "$i" > /dev/null && total=$((total + 1))
  done
  for i in $(find ./luogu -name "*.cpp")
  do
    grep "// AC" "$i" > /dev/null && luogu=$((luogu + 1))
  done
  for i in $(find ./nowcoder_acm -name "*.cpp")
  do
    grep "// AC" "$i" > /dev/null && NC=$((NC + 1))
  done
  for i in $(find ./CodeForces -name "*.cpp")
  do
    grep "// AC" "$i" > /dev/null && CF=$((CF + 1))
  done
  if [ "$#" -eq 0 ]; then
    echo "total: $total
luogu: $luogu
nowcoder: $NC
CodeForces: $CF"
  else
    sed -i -E -e '/total\saccepted\sproblems\scount:/s%[0-9]+%'"$total"'%' \
              -e '/\[Luogu\]\[luogu\]:/s%[0-9]+%'"$luogu"'%' \
              -e '/\[nowcoder\]\[nowcoder\]/s%[0-9]+%'"$NC"'%' \
              -e '/\[Examples on _OI Advance_\]\[oi_advance\]/s%[0-9]+%'"$EX"'%' \
              -e '/\[CodeForces\]\[CF\]/s%[0-9]+%'"$CF"'%' \
              "$proj_root/README.md"
  fi
  unset total luogu NC EX
}

################################## Templates ###################################

CPP_T="$proj_root/templates/cpp.cpp"
username=learntocode1024

# __fill SOURCE(- for defalt) DESTINATION URL
# Predefined Variables List
### $DATE
### $USERNAME
### $PROBLEMURL
### $FILEDIR
__fill() {
  SRC=${1}
  FILE=${2}
  URL=${3}
  if [ "-" = "$SRC" ]; then
    SRC=$CPP_T
  fi
  sed -e 's%$DATE%'"$(date +%m-%d-%y)"'%' \
      -e 's%$USERNAME%'"$username"'%' \
      -e 's%$FILEDIR%'"$FILE"'%' \
      -e 's%$PROBLEMURL%'"$URL"'%' \
      "$SRC" > "$proj_root/$file"
}

################################ Header Comment ################################
# shellcheck disable=SC2120
_luogu() {
  file="luogu/Luogu${1}.cpp"
  if echo "${1}" | grep -iq -E "^[0-9]+$"; then
    url=https://www.luogu.com.cn/problem/P${1}
  else
    url=https://www.luogu.com.cn/problem/${1}
  fi
  ls | grep -iq "$file" && error "luogu: File already Exist!"
  # curl -s "$url" | grep -q Exception && error "luogu: problem not exist: $1"
  __fill - "$file" "$url"
}

_NC() {
  exit 1
  file="NC${1}.cpp"
  url=https://ac.nowcoder.com/acm/problem/${1}
  ls | grep -iq "$file" && error "nowcoder: File already Exist!"
  curl -s "$url" | grep -q "<title>页面找不到了</title>" && error "nowcoder: problem not exist: $1"
  touch "${file}"
  echo "// luogu/Luogu${1}.cpp
// $url
// Created by learntocode1024 on $(date +%D).
// \


int main() {
  \

  return 0;
}" > "${file}"
}

_NC_contest() {
  exit 1
  dir="${1}_NC"
  mkdir "contest/$dir" && cd "$_"
}

_CF() {
  file="CodeForces/CF${1}.cpp"
  url=https://codeforces.com/problemset/problem/${1//[A-z]}/${1//[0-9]}
  if [ -d "CF${1//[A-z]}" ]; then
    file="CodeForces/CF${1//[A-z]}/${1//[0-9]}.cpp"
    url=https://codeforces.com/contest/${1//[A-z]}/problem/${1//[0-9]}
  fi
  ls | grep -iq "$file" && error "Codeforces: File already Exist!"
  #curl -s "$url" | grep -q "<title>页面找不到了</title>" && error "CodeForces: problem not exist: $1"
  __fill - "$file" "$url"
}

_CFCONTEST() {
  id="$1"
  url=https://codeforces.com/contest/${id}
  dir="CodeForces/CF${id}"
  test -d "$proj_root/$dir" && error "Codeforces: Contest directory already Exist!"
  #curl -s "https://codeforces.com/api/contest.standings?contestId=$id" | grep -q "FAILED" && error "CodeForces: contest not found: $id"
  mkdir "$proj_root/$dir"
  for rk in "A" "B" "C" "D" "E" "F"
  do
    file=$dir/$rk.cpp;
    __fill - "$file" "$url/problem/$rk"
  done
}

_CONTEST() {
  echo "$@" | read id cnt url
  dir="contest/${id}"
  mkdir "$proj_root/$dir"
  for rk in "A" "B" "C" "D" "E" "F" "G" "H" "I" "J" "K" "L" "M" "N"
  do
    if [ $cnt -eq 0 ]; then; break; fi
    currurl=$url
    file=$dir/$rk.cpp;
    __fill - "$file" "$currurl"
    cnt=$((cnt - 1))
  done
}

##################################### Init #####################################
# shellcheck disable=SC2120
_init() {
  str="$@"
  type=0

  for RE in "^Lu?o?gu?\s*\K(\w+)" \
            "^NC\s*\K([0-9]{4,6})" \
            "^EX\s*\K(\w{4,6})" \
            "cf\s*\K([0-9]{3,5}[A-Z]$)" \
            "cf\s*\K([0-9]{3,5}$)" \
            "contest\s*\K([\x00-\x7F]*)"
  do
    echo "$str" | grep -iq -P "$RE" && str=$(echo "$str" | grep -i -Po "$RE") && break
    type=$((type + 1))
  done
  case $type in
    0)
      _luogu "$str"
      ;;
    1)
      _NC "$str"
      ;;
    2)
      _EX "$str"
      ;;
    3)
      _CF "$str"
      ;;
    4)
      _CFCONTEST "$str"
      ;;
    5)
      _CONTEST "$str"
      ;;
    *)
      error "init: invalid file string: ${str:-(NULL)}"
      ;;
  esac
  unset type
}

################################# todo_sync ####################################
_todo_diff() {
  if ! [ -f $HOME/.todo/todo.txt ]; then
    warning "local todo.txt not exist"
  fi
  echo "Left: repo------------------------------------------------------Right: Local"
  set +e
  diff -yN .todo/todo.txt $HOME/.todo/todo.txt
  set -e
}

_todo_push() {
    cat "$HOME/.todo/todo.txt" > .todo/todo.txt
    cat "$HOME/.todo/done.txt" > .todo/done.txt
    git add .todo/*
    git commit -m "todo-list updated on $(date +%D)"
}

_todo_pull() {
  _todo_diff
  warning "all local items will be lost!!!"
  read "yn?Pull anyway?(y/n)"
  case $yn in
    y)
      cat ".todo/todo.txt" > "$HOME/.todo/todo.txt"
      ;;
    n)
      echo Exited
      exit
      ;;
    *)
      exit
  esac
}

_todo() {
  case $1 in
    push)
      _todo_push
      ;;
    pull)
      _todo_pull
      ;;
    diff)
      _todo_diff
      ;;
    *)
      error "todo: invalid action"
      ;;
  esac
}

##################################### main #####################################
$cmd "$@"
