#!/bin/zsh
export dir_proj_program_learning_tools_temporary=${PROJ:-$(pwd)}
if [ -d "$1" ]; then
  export dir_proj_program_learning_tools_temporary=$1
fi
## set PROJ as project root dir and source this
if ! [ -f "$dir_proj_program_learning_tools_temporary/tools/tool.sh" ] || ! [ -f "$dir_proj_program_learning_tools_temporary/tools/test.sh" ]; then
  printf "\033[1;31mERROR:\033[0m invalid \$PROJ setting\n"
  unset dir_proj_program_learning_tools_temporary
  return 1;
fi
proj-init() {
  zsh $dir_proj_program_learning_tools_temporary/tools/tool.sh _init "$@"
}
proj-stat() {
  zsh $dir_proj_program_learning_tools_temporary/tools/tool.sh _stat "$@"
}
proj-todo() {
  zsh $dir_proj_program_learning_tools_temporary/tools/tool.sh _todo "$@"
}
proj-test() {
  zsh $dir_proj_program_learning_tools_temporary/tools/test.sh "$@"
}
proj-set() {
  if [ -d "$1" ]; then
    export dir_proj_program_learning_tools_temporary=$1
  else
     printf "\033[1;31mERROR:\033[0m invalid \$PROJ setting\n"
  fi
}