#!/bin/zsh

export proj_root=path/to/project-learning

pjinit() {
  zsh $proj_root/tools/tool.sh _init "$@"
}
pjstat() {
  zsh $proj_root/tools/tool.sh _stat "$@"
}
pjtodo() {
  zsh $proj_root/tools/tool.sh _todo "$@"
}
pjtest() {
  zsh $proj_root/tools/test.sh "$@"
}
