#!/bin/bash
curl -sL https://deb.nodesource.com/setup_15.x | sudo -E bash -
sudo add-apt-repository ppa:neovim-ppa/unstable 
sudo apt update && sudo apt upgrade && sudo apt install nodejs neovim clangd -y

if [ -d ~/.config/nvim ] ;then rm -rf ~/.config/nvim ;fi
mkdir -p ~/.config/nvim
# Install Vim-plug
sh -c 'curl -fLo ~/.config/nvim/autoload/plug.vim --create-dirs \ 
       https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
# Install config

# jackguo380/vim-lsp-cxx-highlight
# danilo-augusto/vim-afterglow (changed)
# coc.nvim
# coc-clangd

" Soft Tabs
set tabstop=8
set shiftwidth=2
set softtabstop=2
set expandtab

" Vim-plug Package Manager
call plug#begin('~/.config/nvim/plugged')

Plug 'neoclide/coc.nvim', {'branch': 'release'}
" Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'jackguo380/vim-lsp-cxx-highlight'
Plug 'danilo-augusto/vim-afterglow'

call plug#end()
" Color Scheme/Highlighting
let g:lsp_cxx_hl_use_text_props = 1
colorscheme afterglow
puremourning/vimspector

