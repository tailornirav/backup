# Interactive Check
[[ $- != *i* ]] && return

# Alaises
alias cd='z'
alias m='mpv'
alias .='z ..'
alias ..='z ../..'
alias mount='doas mount'
alias umount='doas umount'
alias pacman='doas pacman'
alias grep='grep --color=auto'
alias ls='lsd -alFh --group-dirs first --color always'

alias rasp-root='TERM=xterm-256color ssh root@192.168.1.150'
alias rasp-dietpi='TERM=xterm-256color ssh dietpi@192.168.1.150'

# Export
export EDITOR=nvim
export RASP=192.168.1.150
export PS1="\[\e[31m\]\A\[\e[m\]\[\e[31m\]>\[\e[m\] "

# Git push
function gpush {
  git add . && git commit -m $1 && git push -u origin main
}

# cd
eval "$(zoxide init bash)"
