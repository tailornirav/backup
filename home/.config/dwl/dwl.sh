#gammastep &
swayidle -w \
  timeout 300 'systemctl suspend' \
  before-sleep 'playerctl pause' \
  before-sleep 'swaylock -eu -i ~/.config/dwl/lock' &
swaybg -i ~/.config/dwl/wall &
swaylock -eu -i ~/.config/dwl/lock
