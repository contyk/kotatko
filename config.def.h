static const char *fonts[] = {
    "Source Code Pro Medium:size=8",
    "Noto Sans Mono CJK JP:size=8",
};
/* Color scheme based on base16-gruvbox-dark-medium */
static const char color[16][8] = {
    "#282828",
    "#fb4934",
    "#b8bb26",
    "#fabd2f",
    "#83a598",
    "#d3869b",
    "#8ec07c",
    "#d5c4a1",
    "#665c54",
    "#fb4934",
    "#b8bb26",
    "#fabd2f",
    "#83a598",
    "#d3869b",
    "#8ec07c",
    "#fbf1c7",
};
static const char *colors[][3] = {
    /* foreground,
     * background,
     * border */
    [SchemeNorm] = { color[7], color[0], color[8] },
    [SchemeSel]  = { color[15], color[8], color[15] },
    [SchemeUrg]  = { color[0], color[3], color[3] },
};
static const unsigned int borderpx = 6;
static const unsigned int snap     = 8;
static const unsigned int rmaster  = 1;
static const unsigned int columns  = 1;
static const unsigned int gappx    = 24;
static const int showbar           = 1;
static const int topbar            = 1;
static const float barpadfact      = 1.5;
static const char *tags[] = {
    "main",
    "work",
    "misc",
    "chat",
    "proc",
};

static const Rule rules[] = {
    /* class,
     * instance,
     * title,
     * tags mask,
     * iscentered,
     * isfloating,
     * isterminal,
     * noswallow,
     * monitor */
    { "XTerm", "xterm", NULL, 0, 0, 0, 1, 1, -1 },
    { "Ibus-extension-gtk3", NULL, NULL, 0, 0, 1, 0, 0, -1 },
    { ">", NULL, ">", 0, 1, 1, 1, 0, -1 },
    { "pamix", NULL, "pamix", 0, 1, 1, 1, 1, -1 },
    { NULL, NULL, "Event Tester", 0, 0, 0, 0, 1, -1 },
};

static const float mfact     = 0.70;
static const int nmaster     = 1;
static const int resizehints = 0;

static const Layout layouts[] = {
    { "+", tile },
    { "~", NULL },
    { "0", monocle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG) \
    { MODKEY,                       KEY, view,       {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY, toggleview, {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY, tag,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} }

static const char *termcmd[] = {
    "xterm",
    NULL
};

static const char *lockcmd[] = {
    "slock",
    NULL
};

static const char *execcmd[] = {
    "xterm",
    "-class", ">",
    "-title", ">",
    "-geometry", "80x6",
    "-e",
    "zsh", "-c",
    "print -rl -- ${(ko)commands} | "
    "fzf --print-query --info=hidden --layout=reverse | "
    "tail -n1 | "
    "(nohup ${SHELL:-zsh} &) >/dev/null 2>&1",
    NULL
};

static const char *shotcmd[] = {
    "sh", "-c",
    "maim --select --bordersize 3 --hidecursor --quality 10 | "
    "xclip -in -selection clipboard -target image/png",
    NULL
};

static const char *amixcmd[] = {
    "xterm",
    "-class", "pamix",
    "-title", "pamix",
    "-geometry", "80x25",
    "-e",
    "pamix",
    NULL
};

static Key keys[] = {
    /* modifier         key        function        argument */
    { MODKEY,           XK_p,      spawn,          {.v = execcmd } },
    { MODKEY|ShiftMask, XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask, XK_l,      spawn,          {.v = lockcmd } },
    { MODKEY,           XK_s,      spawn,          {.v = shotcmd } },
    { MODKEY,           XK_a,      spawn,          {.v = amixcmd } },
    { MODKEY,           XK_b,      togglebar,      {0} },
    { MODKEY,           XK_j,      focusstack,     {.i = +1 } },
    { MODKEY|ShiftMask, XK_j,      movestack,      {.i = +1 } },
    { MODKEY,           XK_k,      focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask, XK_k,      movestack,      {.i = -1 } },
    { MODKEY,           XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,           XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,           XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,           XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,           XK_Return, zoom,           {0} },
    { MODKEY,           XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask, XK_c,      killclient,     {0} },
    { MODKEY,           XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,           XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,           XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,           XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask, XK_space,  togglefloating, {0} },
    { MODKEY,           XK_c,      togglecolumns,  {0} },
    { MODKEY,           XK_r,      togglermaster,  {0} },
    { MODKEY,           XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask, XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,           XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,           XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask, XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask, XK_period, tagmon,         {.i = +1 } },
    TAGKEYS(            XK_1,                      0),
    TAGKEYS(            XK_2,                      1),
    TAGKEYS(            XK_3,                      2),
    TAGKEYS(            XK_4,                      3),
    TAGKEYS(            XK_5,                      4),
    { MODKEY|ShiftMask, XK_q,      quit,           {0} },
};

static Button buttons[] = {
    /* click            event mask  button   function        argument */
    { ClkLtSymbol,      0,          Button1, setlayout,      {0} },
    { ClkLtSymbol,      0,          Button3, setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,      0,          Button2, zoom,           {0} },
    { ClkStatusText,    0,          Button2, spawn,          {.v = termcmd } },
    { ClkClientWin,     MODKEY,     Button1, movemouse,      {0} },
    { ClkClientWin,     MODKEY,     Button2, togglefloating, {0} },
    { ClkClientWin,     MODKEY,     Button3, resizemouse,    {0} },
    { ClkTagBar,        0,          Button1, view,           {0} },
    { ClkTagBar,        0,          Button3, toggleview,     {0} },
    { ClkTagBar,        MODKEY,     Button1, tag,            {0} },
    { ClkTagBar,        MODKEY,     Button3, toggletag,      {0} },
};
