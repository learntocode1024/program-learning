proj_root="$HOME/program-learning"

error() {
  printf "program-learning: \033[1;31merror: \033[0m%s\n" "$@" > /dev/stderr
  exit 1
}
warning() {
  printf "program-learning: \033[38;2;225;140;0mwarning: \033[0m%s\n" "$@"
}
################################## Templates ###################################

CPP_T="$proj_root/templates/cpp.cpp"
username=misaka18931

# __fill SOURCE(- for defalt) DESTINATION URL
# Predefined Variables List
### $DATE
### $USERNAME
### $PROBLEMURL
### $FILEDIR
__fill() {
  SRC=$CPP_T
  FILE=${1}
  URL=${2}
  if [ "-" = "$SRC" ]; then
    SRC=$CPP_T
  fi
  sed -e 's%$DATE%'"$(date +%m-%d-%y)"'%' \
      -e 's%$USERNAME%'"$username"'%' \
      -e 's%$FILEDIR%'"$FILE"'%' \
      -e 's%$PROBLEMURL%'"$URL"'%' \
      "$SRC" > "$proj_root/$file"
}

_luogu() {
  
}

##################################### Init #####################################
# shellcheck disable=SC2120
main() {
  [ $# -le 0 ] && exit 0
  word=$1
  shift 1
  case $word in
    luogu|lg)
      _luogu "$@"
      ;;
    codeforces|cf)
      _cf "$@"
      ;;
    libreoj|loj)
      _loj "$@"
      ;;
    atcoder|abc|arc|agc)
      _at "$@"
      ;;
    noiac)
      _noi_ac "$@"
      ;;
    -f)
      _custom "$@"
      ;;
    *)
      error "invalid word found: $word"
  esac
  unset word
}

##################################### main #####################################

set -e
[ -d "$proj_root" ] || error "error entering directory: $proj_root"
main "$@"
