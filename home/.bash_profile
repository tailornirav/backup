# dwl
if [ -z "${WAYLAND_DISPLAY}" ] && [ "${XDG_VTNR}" -eq 1 ]; then
  cd ~/tailor && exec dbus-run-session dwl -s ~/.config/dwl/dwl.sh
fi
