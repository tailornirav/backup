# If running from tty1 start dwl
if [ "$(tty)" = "/dev/tty1" ]; then
  cd ~/tailor && exec dbus-run-session dwl -s ~/.config/dwl/dwl.sh
fi
