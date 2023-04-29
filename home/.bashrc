# Interactive Check
[[ $- != *i* ]] && return

# Alaises
alias cd='z'
alias .='z ..'
alias ..='z ../..'
alias mount='doas mount'
alias umount='doas umount'
alias pacman='doas pacman'
alias grep='grep --color=auto'
alias ls='lsd -alFh --group-dirs first --color always'

# Export
export EDITOR=nvim
export PS1="\[\e[31m\]\A\[\e[m\]\[\e[31m\]>\[\e[m\] "

# cd
eval "$(zoxide init bash)"
