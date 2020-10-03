#!/bin/zsh
## set PROJ as project root dir
proj-init() {
  zsh $PROJ/tools/tool.sh _init "$@"
}
proj-stat() {
  zsh $PROJ/tools/tool.sh _stat "$@"
}
proj-todo() {
  zsh $PROJ/tools/tool.sh _todo "$@"
}
proj-test() {
  zsh $PROJ/tools/test.sh "$@"
}