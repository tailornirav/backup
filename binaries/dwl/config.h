/* appearance */
static const int sloppyfocus               = 0;
static const int bypass_surface_visibility = 0;
static const unsigned int borderpx         = 0;
static const float bordercolor[]           = {0.5, 0.5, 0.5, 1.0};
static const float focuscolor[]            = {1.0, 0.0, 0.0, 1.0};
static const float fullscreen_bg[]         = {0.1, 0.1, 0.1, 1.0};

/* tagging */
static const int tagcount = 6;

/* rules */
static const Rule rules[] = {
	{ "NULL", NULL, 0,  0,  -1 },
};

/* layout */
static const Layout layouts[] = {
	{ "[]=",      tile }
};

/* monitors */
static const MonitorRule monrules[] = {
	{ "eDP-1",       0.6, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
  .layout = "us",
  .variant = "dvp",
	.options = "caps:escape",
};
static const int repeat_rate = 25;
static const int repeat_delay = 600;

/* Trackpad */
static const int drag_lock = 1;
static const int left_handed = 0;
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const double accel_speed = 0.0;
static const int natural_scrolling = 1;
static const int disable_while_typing = 1;
static const int middle_button_emulation = 0;
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;

/* commands */
static const char *terminal[]   = { "foot", NULL };
static const char *browser[]    = { "google-chrome-stable", NULL };
static const char *dbeaver[]    = { "dbeaver", NULL };
static const char *insomnia[]   = { "insomnia", "--ozone-platform-hint=auto", NULL };
static const char *bottom[]     = { "foot", "-e", "btm", NULL };
static const char *latch[]      = { "swaylock", "-eu", "-i", "~/.config/dwl/lock", NULL };

static const char *shot[]       = { "/bin/sh", "-c", "grim -g \"$(slurp)\" - | wl-copy -t image/png", NULL };
static const char *full[]       = { "/bin/sh", "-c", "grim -g \"$(slurp)\"", NULL };

static const char *volup[]      = { "wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "2%+", NULL };
static const char *voldown[]    = { "wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "2%-", NULL };
static const char *volmute[]    = { "wpctl", "set-mute", "@DEFAULT_AUDIO_SINK@", "toggle", NULL };

static const char *brightup[]   = { "brightnessctl", "set", "1%+", NULL };
static const char *brightdown[] = { "brightnessctl", "set", "1%-", NULL };

static const char *playpause[]   = { "playerctl", "play-pause", NULL };
static const char *next[]        = { "playerctl", "next", NULL };
static const char *prev[]        = { "playerctl", "previous", NULL };
static const char *stop[]        = { "playerctl", "stop", NULL };

static const Key keys[] = {
	{ WLR_MODIFIER_ALT,   XKB_KEY_Return,       spawn,          {.v = terminal} },
  { WLR_MODIFIER_ALT,   XKB_KEY_space,        spawn,          {.v = browser} },
  { WLR_MODIFIER_ALT,   XKB_KEY_d,            spawn,          {.v = dbeaver} },
  { WLR_MODIFIER_ALT,   XKB_KEY_i,            spawn,          {.v = insomnia} },
  { WLR_MODIFIER_ALT,   XKB_KEY_Escape,       spawn,          {.v = bottom} },

  { WLR_MODIFIER_ALT,   XKB_KEY_p,            spawn,          {.v = shot} },
  { WLR_MODIFIER_LOGO,  XKB_KEY_p,            spawn,          {.v = full} },

  { 0,                  0x1008ff13,           spawn,          {.v = volup} },
  { 0,                  0x1008ff11,           spawn,          {.v = voldown} },
  { 0,                  0x1008ff12,           spawn,          {.v = volmute} },

  { 0,                  0x1008ff02,           spawn,          {.v = brightup} },
  { 0,                  0x1008ff03,           spawn,          {.v = brightdown} },

  { 0,                  0x1008ff14,           spawn,          {.v = playpause} },
  { 0,                  0x1008ff17,           spawn,          {.v = next} },
  { 0,                  0x1008ff17,           spawn,          {.v = prev} },
  { 0,                  0x1008ff15,           spawn,          {.v = stop} },

  { WLR_MODIFIER_ALT,   XKB_KEY_BackSpace,    spawn,          {.v = latch} },

	{ WLR_MODIFIER_ALT,   XKB_KEY_h,            focusstack,     {.i = +1} },
	{ WLR_MODIFIER_ALT,   XKB_KEY_l,            focusstack,     {.i = -1} },
  { WLR_MODIFIER_ALT,   XKB_KEY_dollar,       shiftview,      {.i = +1} },
	{ WLR_MODIFIER_ALT,   XKB_KEY_Tab,          view,           {0} },
  { WLR_MODIFIER_ALT,   XKB_KEY_q,            quit,           {0} },
	{ WLR_MODIFIER_LOGO,  XKB_KEY_h,            setmfact,       {.f = -0.05} },
	{ WLR_MODIFIER_LOGO,  XKB_KEY_l,            setmfact,       {.f = +0.05} },

  { WLR_MODIFIER_ALT,   XKB_KEY_ampersand,    view,         {.ui = 1 << 0} },
  { WLR_MODIFIER_LOGO,  XKB_KEY_ampersand,    tag,          {.ui = 1 << 0} },
  { WLR_MODIFIER_ALT,   XKB_KEY_bracketleft,  view,         {.ui = 1 << 1} },
  { WLR_MODIFIER_LOGO,  XKB_KEY_bracketleft,  tag,          {.ui = 1 << 1} },
  { WLR_MODIFIER_ALT,   XKB_KEY_braceleft,    view,         {.ui = 1 << 2} },
  { WLR_MODIFIER_LOGO,  XKB_KEY_braceleft,    tag,          {.ui = 1 << 2} },
  { WLR_MODIFIER_ALT,   XKB_KEY_braceright,   view,         {.ui = 1 << 3} },
  { WLR_MODIFIER_LOGO,  XKB_KEY_braceright,   tag,          {.ui = 1 << 3} },
  { WLR_MODIFIER_ALT,   XKB_KEY_parenleft,    view,         {.ui = 1 << 4} },
  { WLR_MODIFIER_LOGO,  XKB_KEY_parenleft,    tag,          {.ui = 1 << 4} },
  { WLR_MODIFIER_ALT,   XKB_KEY_equal,        view,         {.ui = 1 << 5} },
  { WLR_MODIFIER_LOGO,  XKB_KEY_equal,        tag,          {.ui = 1 << 5} },
};

static const Button buttons[] = {
  {0,0,0,{0}}
};
