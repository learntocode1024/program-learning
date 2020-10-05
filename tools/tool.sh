#!/bin/zsh

#################################### Global ####################################
PROJECT=program-learning
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
    echo "### Online Judge practices statistics  \

project start time: Oct 1 2020  \

total accepted problems count: $total  \


[Luogu][luogu]: $luogu  \

[nowcoder][nowcoder] (NC): $NC  \

[Examples on _OI Advance_][oi_advance]  (EX): $EX  \

[CodeForces][CF]: $CF  " > >(xclip -selection c) > >(tee)

    printf "------------\nCopied into Clipboard\n"
  fi
  unset total luogu NC EX
}

################################ Header Comment ################################
# shellcheck disable=SC2120
_luogu() {
  file="Luogu${1}.cpp"
  if echo "${1}" | grep -iq -E "^[0-9]+$"; then
    url=https://www.luogu.com.cn/problem/P${1}
  else
    url=https://www.luogu.com.cn/problem/${1}
  fi
  ls | grep -iq "$1" && error "luogu: File already Exist!"
  curl -s "$url" | grep -q Exception && error "luogu: problem not exist: $1"
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

_NC() {
  file="NC${1}.cpp"
  url=https://ac.nowcoder.com/acm/problem/${1}
  ls | grep -iq "$1" && error "nowcoder: File already Exist!"
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

_CF() {
  file="CF${1}.cpp"
  url=https://codeforces.com/problemset/problem/${1//[A-z]}/${1//[0-9]}
  ls | grep -iq "$1" && error "Codeforces: File already Exist!"
  curl -s "$url" | grep -q "<title>页面找不到了</title>" && error "CodeForces: problem not exist: $1"
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

##################################### Init #####################################
# shellcheck disable=SC2120
_init() {
  str="$@"
  type=0

  for RE in "^Lu?o?gu?\s*\K(\w{4,6})" "^NC\s*\K([0-9]{4,6})" "^EX\s*\K(\w{4,6})" "cf\s*\K([0-9]{3}\w)"
  do
    echo "$str" | grep -iq -P "$RE" && str=$(echo "$str" | grep -i -Po "$RE") && break
    type=$((type + 1))
  done
  case $type in
    0)
      (cd luogu && _luogu "$str")
      ;;
    1)
      (cd nowcoder_acm && _NC "$str")
      ;;
    2)
      (cd nowcoder_oi_advance && _EX "$str")
      ;;
    3)
      (cd CodeForces && _CF "$str")
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
  diff -yN .todo/todo.txt $HOME/.todo/todo.txt
}

_todo_push() {
    cat "$HOME/.todo/todo.txt" > .todo/todo.txt
    cat "$HOME/.todo/done.txt" > .todo/done.txt
    git add .todo/*
    git commit -m "todo-list updated on $(date +%D)"
}

_todo_pull() {
  error "Don't do this"
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
set -e
if [ "${$(pwd)##*/}" != "$PROJECT" ]; then
  if [ "${dir_proj_program_learning_tools_temporary##*/}" != "$PROJECT" ]; then
    error "invalid \$PROJ setting: ${dir_proj_program_learning_tools_temporary:-(NULL)}"
  else
    cd "$dir_proj_program_learning_tools_temporary"
  fi
fi
cmd=$1
shift
$cmd "$@"