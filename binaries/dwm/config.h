/* appearance */
static const unsigned int borderpx  = 0;
static const unsigned int snap      = 32;
static const int showbar            = 0;
static const int topbar             = 0;
static const char *fonts[]          = { "IBM Plex Mono:size=10" };
static const char dmenufont[]       = "IBM Plex Mono:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

static const Rule rules[] = {
	{ "firefox",            NULL,       NULL,       1 << 1,       0,           -1 },
	{ "neomutt",            NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Steam",              NULL,       NULL,       1 << 2,       0,           -1 },
	{ "cmus",               NULL,       NULL,       1 << 3,       0,           -1 },
	{ "mpv",                NULL,       NULL,       1 << 4,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55;
static const int nmaster     = 1;
static const int resizehints = 0;

static const Layout layouts[] = {
	{ "[]=",      tile },
	{ "><>",      NULL },
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask

#define XF86AudioLowerVolume    0x1008ff11
#define XF86AudioMute           0x1008ff12
#define XF86AudioRaiseVolume    0x1008ff13

#define TAGKEYS(KEY,TAG) \
	{ 0,        KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY,   KEY,      tag,            {.ui = 1 << TAG} }, \

/* commands */
static const char *termcmd[]        = { "/bin/sh", "-c", "st -d ~/tailor", NULL };
static const char *browser[]        = { "/bin/sh", "-c", "firefox", NULL };
static const char *steam[]          = { "/bin/sh", "-c", "progl steam", NULL };
static const char *mail[]           = { "/bin/sh", "-c", "st -c neomutt neomutt", NULL };
static const char *cmus[]           = { "/bin/sh", "-c", "st -c cmus cmus", NULL };
static const char *volumetoggle[]   = { "/bin/sh", "-c", "pactl set-sink-mute @DEFAULT_SINK@ toggle", NULL };
static const char *volumeup[]       = { "/bin/sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ +2%", NULL };
static const char *volumedown[]     = { "/bin/sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ -2%", NULL };

static Key keys[] = {
	{ MODKEY,                       XK_Return,                  spawn,          {.v = termcmd } },
  { MODKEY,                       XK_b,                       spawn,          {.v = browser } },
  { MODKEY,                       XK_s,                       spawn,          {.v = steam } },
  { MODKEY,                       XK_m,                       spawn,          {.v = mail } },
  { MODKEY,                       XK_c,                       spawn,          {.v = cmus } },
  { MODKEY,                       XK_Tab,                     view,           {0} },
  { MODKEY,                       XK_dollar,                  focusstack,     {.i = +1 } },
  { MODKEY,                       XK_l,                       focusstack,     {.i = +1 } },
  { MODKEY,                       XK_h,                       focusstack,     {.i = -1 } },
  { 0,                            XF86AudioMute,              spawn,          {.v = volumetoggle } },
  { 0,                            XF86AudioRaiseVolume,       spawn,          {.v = volumeup } },
  { 0,                            XF86AudioLowerVolume,       spawn,          {.v = volumedown } },
	TAGKEYS(                        XK_F1,                                      0)
	TAGKEYS(                        XK_F2,                                      1)
	TAGKEYS(                        XK_F3,                                      2)
	TAGKEYS(                        XK_F4,                                      3)
	TAGKEYS(                        XK_F5,                                      4)
	TAGKEYS(                        XK_F6,                                      5)
	TAGKEYS(                        XK_F7,                                      6)
	TAGKEYS(                        XK_F8,                                      7)
	TAGKEYS(                        XK_F9,                                      8)
	TAGKEYS(                        XK_F10,                                     9)
	{ MODKEY|ShiftMask,             XK_q,                       quit,           {0} },
};

/* button definitions */
static Button buttons[] = {
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
